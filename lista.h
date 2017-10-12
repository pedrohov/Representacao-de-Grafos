/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#ifndef __LISTA__
#define __LISTA__


    // Tipos:
    typedef struct nodo *Lista;


    // Sub-rotinas:
    Lista lCria(int vertice);
    Lista lInsere(Lista l, int vertice);
    Lista lPegaVertice(Lista l, int vertice);
    Lista lPegaVizinhos(Lista l, int vertice);
    void  lInsereVizinho(Lista l, int vertice, int vizinho);
    void  lImprime(Lista l);
    void  lImprimeListaAdj(Lista l);
    void  lRemoveVizinho(Lista l, int vertice, int vizinho);
    void  lInverteListaAdj(Lista l, int vertice);
    int   lPertence(Lista l, int vertice);
    int   lVazia(Lista l);
    int   lTamanho(Lista l);
    int*  lArrayElementos(Lista l, int *tam);


#endif