/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "grafoL.h"


// Estrutura:
struct grafoList {
    int nVertices;
    int nArestas;
    Lista adj;
};


// Implementacao sub-rotinas:
GrafoL glCria(int nV, int nA)
{
	// Prerequisitos (lin e col devem ser numeros positivos nao nulos):
    if((nV <= 0) || (nA <= 0))
        return NULL;

	GrafoL novo = (GrafoL) malloc(sizeof(struct grafoList));
	novo -> nVertices = nV;
	novo -> nArestas = nA;
	novo -> adj = lCria(0);

	// Insere os vertices no grafo:
	int i;
	for(i = 1; i < nV; i++) {
		novo -> adj = lInsere(novo -> adj, i);
	}

	return novo;
}

GrafoL glCarrega(const char *local)
{
	// Abre o arquivo para leitura:
    FILE *parq = fopen(local, "r");

    // Caso o arquivo nao exista, retorna NULL:
    if(parq == NULL)
    {
        printf("Arquivo nao encontrado.\n");
        return NULL;
    } 

    // Determinar quantidade de linhas e colunas;
    int i, j;
    fscanf(parq, "%d", &i);
    fscanf(parq, "%d", &j);

    // Cria o grafo:
    GrafoL novo = glCria(i, j);

    // Le e salva nos vizinhos:
    for(i = 0; i < novo -> nVertices; i++) {
        for(j = 0; j < novo -> nVertices; j++) {
            int aux;
            fscanf(parq, "%d", &aux);

            if(aux == 1)
                lInsereVizinho(novo -> adj, i, j);
        }
    }

    return novo;
}

Lista glPegaListaAdj(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return NULL;

    return g -> adj;
}

void glImprime(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return;

    printf("Vertices: %d\n", g -> nVertices);
    printf("Arestas: %d\n", g -> nArestas);

    lImprimeListaAdj(g -> adj);

    return;
}

void glVerticesSorvedouros(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return;

    int i;
    int *mostrados = (int*) malloc(sizeof(int) * g -> nVertices);
    int indexM = 0;

    printf("Vertices sorvedouros: ");
    for(i = 0; i < g -> nVertices; i++) {

    	// Recebe os vizinhos do vertice atual:
    	Lista vizinhos = lPegaVizinhos(g -> adj, i);

    	// Se nao houver vizinhos, vai para a proxima iteracao:
    	if(!lVazia(vizinhos)) {

	    	int tam;
	    	int *arrayVizinhos = lArrayElementos(vizinhos, &tam);

	    	// Mostra todos os vizinhos do vertice
	    	// que ainda nao foram mostrados:
	    	int k;
	    	for(k = 0; k < tam; k++) {
	    		int j;
	    		int exibido = 0;

	    		// Procura se o vertice foi exibido:
	    		for(j = 0; j < indexM; j++) {
	    			// Vertice ja exibido:
	    			if(mostrados[j] == arrayVizinhos[k]) {
	    				exibido = 1;
	    				break;
	    			}
	    		}

	    		// Se nao foi exibido, mostre-o:
	    		if(!exibido) {
	    			printf("%d ", arrayVizinhos[k]);
	    			mostrados[indexM] = arrayVizinhos[k];
	    			indexM++;
	    		}
	    	} // End vertices vizinhos.
	    } // End lista vazia.
    } // End loop vertices.

    printf("\n");

    free(mostrados);
    return;
}

void glVerticesFontes(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return;

    printf("Vertices fontes: ");
    int i;
    for(i = 0; i < g -> nVertices; i++) {
    	Lista vizinhos = lPegaVizinhos(g -> adj, i);

    	if(!lVazia(vizinhos))
    		printf("%d ", i);
    }

    printf("\n");

    return;
}

int glGrauVerticeIn(GrafoL g, int vertice)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    int grau = 0;
    int i;

    for(i = 0; i < g -> nVertices; i++) {
    	// Recebe os vizinhos do vertice atual:
    	Lista vizinhos = lPegaVizinhos(g -> adj, i);

    	if(lPertence(vizinhos, vertice))
    		grau++;
    }

    return grau;
}

int glGrauVerticeOut(GrafoL g, int vertice)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    Lista vizinhos = lPegaVizinhos(g -> adj, vertice);

    return lTamanho(vizinhos);
}

int glGrafoSimples(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    // Procura por lacos:
    int i;
    for(i = 0; i < g -> nVertices; i++) {
    	// Recebe os vizinhos do vertice atual:
    	Lista vizinhos = lPegaVizinhos(g -> adj, i);

    	if(lPertence(vizinhos, i))
    		return 0;
    }

    return 1;
}

int glGrafoCompleto(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    // Todos os vertices devem possuir
    // todos os outros vertices como vizinhos:
    int i;
    for(i = 0; i < g -> nVertices; i++) {
    	Lista vizinhos = lPegaVizinhos(g -> adj, i);

    	int k;
    	for(k = 0; k < g -> nVertices; k++)
    		if((k != i) && !lPertence(vizinhos, k))
    			return 0;
    }

    return 1;
}

int glNaoDirigido(GrafoL g)
{
	// Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    int i;
    for(i = 0; i < g -> nVertices; i++) {

        Lista vizinhos = lPegaVizinhos(g -> adj, i);

        int k;
        for(k = 0; k < g -> nVertices; k++) {
            if((k != i) && !lPertence(vizinhos, k)) {
                return 0;
            }
        }
    }

    return 1;
}

int glNumVertices(GrafoL g)
{
    // Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    return g -> nVertices;
}

int glNumArestas(GrafoL g)
{
    // Prerequisitos (Grafo nao nulo):
    if(g == NULL)
        return -1;

    return g -> nArestas;
}