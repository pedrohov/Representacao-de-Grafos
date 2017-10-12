/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#ifndef __GRAFO_MAT_ADJ__
#define __GRAFO_MAT_ADJ__

    // Tipos:
    // Linhas indicam os vertices de partida das arestas.
    // Colunas indicam os vertices de chegada das arestas.
    typedef struct grafoMat *GrafoM;


    // Sub-rotinas:
    GrafoM gCria(int nV, int nA);                   // Cria uma nova matriz.
    GrafoM gCarrega(const char *local);             // Carrega uma matriz de 'local'.
    void   gImprime(GrafoM g);                      // Imprime a matriz no terminal.
    void   gVerticesSorvedouros(GrafoM g);          // Imprime os vertices sorvedouros.
    void   gVerticesFontes(GrafoM g);               // Imprime os vertices fontes.
    int    gGrauVerticeIn(GrafoM g, int vertice);   // Determina o grau de entrada do vertice.
    int    gGrauVerticeOut(GrafoM g, int vertice);  // Determina o grau de saida do vertice.
    int    gGrafoSimples(GrafoM g);                 // Checa se o grafo e simples (0 ou 1).
    int    gGrafoCompleto(GrafoM g);                // Checa se o grafo e completo (0 ou 1).
    int    gNaoDirigido(GrafoM g);                  // Checa se o grafo e dirigido (0 ou 1).
    int    gNumVertices(GrafoM g);                  // Retorna o numero de vertices do grafo.
    int    gNumArestas(GrafoM g);                   // Retorna o numero de arestas do grafo.
    int**  gMatriz(GrafoM g);                       // Retorna a matriz de adjacencia do grafo.
    

#endif
