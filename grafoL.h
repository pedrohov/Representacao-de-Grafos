/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#ifndef __GRAFO_LISTA_ADJ__
#define __GRAFO_LISTA_ADJ__

    #include "lista.h"

    // Tipos:
    typedef struct grafoList *GrafoL;


    // Sub-rotinas:
    GrafoL glCria(int nV, int nA);                   // Cria um novo grafo.
    GrafoL glCarrega(const char *local);             // Carrega um grafo de 'local'.
    Lista  glPegaListaAdj(GrafoL g);                 // Retorna a lista de adjacencias do grafo.
    void   glImprime(GrafoL g);                      // Imprime o grafo no terminal.
    void   glVerticesSorvedouros(GrafoL g);          // Imprime os vertices sorvedouros.
    void   glVerticesFontes(GrafoL g);               // Imprime os vertices fontes.
    int    glGrauVerticeIn(GrafoL g, int vertice);   // Determina o grau de entrada do vertice.
    int    glGrauVerticeOut(GrafoL g, int vertice);  // Determina o grau de saida do vertice.
    int    glGrafoSimples(GrafoL g);                 // Checa se o grafo e simples (0 ou 1).
    int    glGrafoCompleto(GrafoL g);                // Checa se o grafo e completo (0 ou 1).
    int    glNaoDirigido(GrafoL g);                  // Checa se o grafo e dirigido (0 ou 1).
    int    glNumVertices(GrafoL g);                  // Retorna o numero de vertices do grafo.
    int    glNumArestas(GrafoL g);                   // Retorna o numero de arestas do grafo.
    

#endif