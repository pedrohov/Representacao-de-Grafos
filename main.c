/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#include <stdio.h>
#include "grafoM.h"
#include "grafoL.h"
#include "lista.h"
#include "transformaGrafos.h"


int main(void)
{
    // Descomente um dos tipos de grafo para testar
    // as principais funcoes implementadas.

    // Testa grafo por matriz de adjacencia:
        /*
        // Carrega um grafo:
        GrafoM g = gCarrega("g1.txt");

        // Imprime o grafo carregado:
        gImprime(g);

        // Mostra vertices sorvedouros:
        gVerticesSorvedouros(g);

        // Mostra vertices fontes:
        gVerticesFontes(g);

        // Mostra grau de entrada e saida do vertice 1:
        printf("Grau de entrada do vertice 1: %d\n", gGrauVerticeIn(g, 1));
        printf("Grau de saida do vertice 1: %d\n", gGrauVerticeOut(g, 1));

        // Checa tipos de grafo:
        printf("Grafo simples: %d\n", gGrafoSimples(g));
        printf("Grafo completo: %d\n", gGrafoCompleto(g));
        printf("Grafo nao dirigido: %d\n", gNaoDirigido(g));

        // Transforma grafo numa lista de adjacencia:
        printf("\nLista de adjacencia:\n");
        GrafoL gl = gTransformaLista(g);
        glImprime(gl);
        */


    // Testa lista de incidencia:
        /*
        // Cria e insere elementos:
        Lista tst = lCria(1);
        tst = lInsere(tst, 2);
        tst = lInsere(tst, 3);
        tst = lInsere(tst, 0);
        tst = lInsere(tst, 4);
        tst = lInsere(tst, 2);

        // Imprime a lista principal:
        printf("Tst: ");
        lImprime(tst);

        // Insere vizinhos do vertice 1:
        lInsereVizinho(tst, 1, 3);
        lInsereVizinho(tst, 1, 0);
        lInsereVizinho(tst, 1, 1);
        lInsereVizinho(tst, 1, 2);

        // Imprime vizinhos de 1:
        printf("Vizinhos de 1: ");
        lImprime(lPegaVizinhos(tst, 1));

        // Imprime toda a lista com todos os vizinhos:
        printf("\nLista de Adj:\n");
        lImprimeListaAdj(tst);
        */


    // Testa grafo por lista de adjacencia:
        /*
        // Carrega um grafo:
        GrafoL gl = glCarrega("g1.txt");

        // Imprime o grafo carregado:
        glImprime(gl);

        // Mostra vertices sorvedouros:
        glVerticesSorvedouros(gl);

        // Mostra vertices fontes:
        glVerticesFontes(gl);

        // Mostra grau de entrada e saida do vertice 1:
        printf("Grau de entrada do vertice 1: %d\n", glGrauVerticeIn(gl, 1));
        printf("Grau de saida do vertice 1: %d\n", glGrauVerticeOut(gl, 1));

        // Checa tipos de grafo:
        printf("Grafo simples: %d\n", glGrafoSimples(gl));
        printf("Grafo completo: %d\n", glGrafoCompleto(gl));
        printf("Grafo nao dirigido: %d\n", glNaoDirigido(gl));

        // Inverte lista de vizinhos do vertice 0 e imprime novamente:
        lInverteListaAdj(glPegaListaAdj(gl), 0);
        glImprime(gl);

        // Remove uma aresta e imprime:
        lRemoveVizinho(glPegaListaAdj(gl), 1, 0);
        glImprime(gl);
        */

    return 0;
}