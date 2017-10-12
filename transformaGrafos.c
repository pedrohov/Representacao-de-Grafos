/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#include <stdio.h>
#include "transformaGrafos.h"


// Implementacao sub-rotinas:
GrafoL gTransformaLista(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return NULL;

    GrafoL novo = glCria(gNumVertices(g), gNumArestas(g));

    int i, j;
    for(i = 0; i < gNumVertices(g); i++)
        for(j = 0; j < gNumVertices(g); j++)
            if(gMatriz(g)[i][j] == 1) {
                lInsereVizinho(glPegaListaAdj(novo), i, j);
            }

    return novo;
}

GrafoM gTransformaMatriz(GrafoL g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return NULL;

    GrafoM novo = gCria(glNumVertices(g), glNumArestas(g));

    int i;
    for(i = 0; i < glNumVertices(g); i++) {
        Lista vizinhos = lPegaVizinhos(glPegaListaAdj(g), i);

        if(vizinhos != NULL) {
            int tam;
            int *arrayVizinhos = lArrayElementos(vizinhos, &tam);

            int k;
            for(k = 0; k < tam ; k++) {
                gMatriz(novo)[i][arrayVizinhos[k]] = 1;
            }
            printf("\n");
        }
    }

    return novo;
}