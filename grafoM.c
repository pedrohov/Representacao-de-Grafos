/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "grafoM.h"


// Estrutura:
struct grafoMat {
    int nVertices;  // Quantidade de vertices.
    int nArestas;   // Quantidade de arestas.
    int **adj;      // Aponta para o inicio de cada linha.
};


// Implementacao sub-rotinas:
GrafoM gCria(int nV, int nA)
{
    // Prerequisitos (lin e col devem ser numeros positivos nao nulos):
    if((nV <= 0) || (nA <= 0))
        return NULL;

    // Aloca memoria para uma matriz e define seu tamanho:
    GrafoM nova = (GrafoM)malloc(sizeof(struct grafoMat));
    nova -> nVertices = nV;
    nova -> nArestas = nA;
    nova -> adj = (int**)malloc(sizeof(int*) * nV);

    // Aloca o numero de colunas necessario p/ cada linha:
    int i, j;
    for(i = 0; i < nV; i++)
        nova -> adj[i] =(int*)malloc(sizeof(int) * nV);

    // Inicializa a matriz com 0's:
    for(i = 0; i < nV; i++)
        for(j = 0; j < nV; j++)
            nova -> adj[i][j] = 0;

    return nova;
}

GrafoM gCarrega(const char *local)
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

    // Cria matriz:
    GrafoM nova = gCria(i, j);

    // Le e salva cada elemento na matriz:
    for(i = 0; i < nova -> nVertices; i++)
        for(j = 0; j < nova -> nVertices; j++)
            fscanf(parq, "%d", &nova -> adj[i][j]);

    return nova;
}

void gImprime(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return;

    // Percorre a matriz e imprime cada elemento:
    int i, j;
    for(i = 0; i < g -> nVertices; i++)
    {
        printf("| ");
        for(j = 0; j < g -> nVertices - 1; j++)
            printf("%d\t", g -> adj[i][j]);

        // Nova linha para cada nova linha da matriz:
        printf("%d |\n", g -> adj[i][j]);
    }
    printf("\n");

    return;
}

void gVerticesSorvedouros(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return;

    // i = Linhas  -> Vertices de saida da aresta.
    // j = Colunas -> Vertices de chegada da aresta.
    printf("Vertices sorvedouros: ");
    int i, j;
    for(j = 0; j < g -> nVertices; j++) {
        for(i = 0; i < g -> nVertices; i++) {
            if(g -> adj[i][j] == 1) {
                printf("%d ", j);
                break;
            }
        }
    }
    printf("\n");
    return;
}

void gVerticesFontes(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return;

    // i = Linhas  -> Vertices de saida da aresta.
    // j = Colunas -> Vertices de chegada da aresta.
    printf("Vertices fontes: ");
    int i, j;
    for(i = 0; i < g -> nVertices; i++) {
        for(j = 0; j < g -> nVertices; j++) {
            if(g -> adj[i][j] == 1) {
                printf("%d ", i);
                break;
            }
        }
    }
    printf("\n");
    return;
}

int gGrauVerticeIn(GrafoM g, int vertice)
{
    // Prerequisitos (Matriz nao nula e vertice valido):
    if((g == NULL) || (vertice < 0) || (vertice >= g -> nVertices))
        return -1;

    int i;
    int grau = 0;
    for(i = 0; i < g -> nVertices; i++) {
        if(g -> adj[i][vertice] == 1)
            grau++;
    }
    
    return grau;
}

int gGrauVerticeOut(GrafoM g, int vertice)
{
    // Prerequisitos (Matriz nao nula e vertice valido):
    if((g == NULL) || (vertice < 0) || (vertice >= g -> nVertices))
        return -1;

    int j;
    int grau = 0;
    for(j = 0; j < g -> nVertices; j++) {
        if(g -> adj[vertice][j] == 1)
            grau++;
    }
    
    return grau;
}

int gGrafoSimples(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return -1;

    // Checa se existem lacos:
    int i;
    for(i = 0; i < g -> nVertices; i++) {
        if(g -> adj[i][i] == 1)
            return 0;
    }

    // A representacao em matriz de adjacencia
    // nao permite arestas paralelas:
    return 1;
}

int gGrafoCompleto(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return -1;

    int i, j;
    for(i = 0; i < g -> nVertices - 1; i++) {
        for(j = i + 1; j < g -> nVertices; j++) {
            if((g -> adj[i][j] != g -> adj[j][i])
               || (g -> adj[i][j] != 1))
                return 0;
        }
    }

    return 1;
}

int gNaoDirigido(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return -1;

    int i, j;
    for(i = 0; i < g -> nVertices; i++)
        for(j = i + 1; j < g -> nVertices; j++) {
            if(g -> adj[i][j] != g -> adj[j][i])
                return 1;
        }

    return 0;
}

int gNumVertices(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return -1;

    return g -> nVertices;
}

int gNumArestas(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return -1;

    return g -> nArestas;
}

int** gMatriz(GrafoM g)
{
    // Prerequisitos (Matriz nao nula):
    if(g == NULL)
        return NULL;

    return g -> adj;
}