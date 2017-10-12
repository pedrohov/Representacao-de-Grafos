/*
 *  Disciplina: Estrutura de Dados II
 *  Professor:  Denise F. Garcia Rezende
 *  Aluno:      Pedro Henrique Oliveira Veloso
 *  Matricula:  0002346
 *  Data:       11/10/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


// Estruturas:
struct nodo {
    int vertice;	// ID do vertice.
    Lista proximo;	// Proximo nodo na lista.
    Lista vizinhos; 	// Permite lista de listas.
};


// Implementacao sub-rotinas:
Lista lCria(int vertice)
{
    Lista nova = (Lista) malloc(sizeof(struct nodo));
    nova -> vertice = vertice;
    nova -> proximo = NULL;
    nova -> vizinhos = NULL;

    return nova;
}

Lista lInsere(Lista l, int vertice)
{
    // Prerequisitos (vertice positivo):
    if(vertice < 0) {
        return l;
    }

    Lista aux = l;
    Lista nova = lCria(vertice);

    // Se o vertice ja existir na lista, nao insere:
    if(lPertence(l, vertice)) {
        return l;
    }

    // Lista vazia:
    if(l == NULL) {
        l = nova;
        return l;
    }

    // Insere no inicio:
    if(l -> vertice > vertice) {
        nova -> proximo = l;
        l = nova;
        return l;
    }

    // Determina a posicao do novo no,
    // garantindo a ordem crescente:
    while(aux -> proximo != NULL)
    {
        if(aux -> proximo -> vertice > vertice)
            break;

        aux = aux -> proximo;
    }

    // Insere novo vertice:
    nova -> proximo = aux -> proximo;
    aux -> proximo = nova;

    return l;
}

Lista lPegaVertice(Lista l, int vertice)
{
    // Prerequisitos (Lista nao nula):
    if(l == NULL)
        return NULL;

    // Caso for o primeiro nodo:
    if(l -> vertice == vertice)
        return l;

    // Demais nodos:
    Lista aux = l;
    while(aux != NULL) {
        if(aux -> vertice == vertice)
            break;

        aux = aux -> proximo;
    }

    return aux;
}

Lista lPegaVizinhos(Lista l, int vertice)
{
    return lPegaVertice(l, vertice) -> vizinhos;
}

void lInsereVizinho(Lista l, int vertice, int vizinho)
{
    // Prerequisitos (vertices positivos):
    if((vertice < 0) || (vizinho < 0))
        return;

    // Recebe o ponteiro para o vertice:
    Lista nodoVertice = lPegaVertice(l, vertice);

    // Insere o vertice vizinho na lista de vizinhos do vertice:
    if(nodoVertice != NULL)
    	nodoVertice -> vizinhos = lInsere(nodoVertice -> vizinhos, vizinho);

    return;
}

void lImprime(Lista l)
{
    // Prerequisitos (Lista nao nula):
    if(l == NULL)
        return;

    Lista aux = l;
    while(aux != NULL) {
        printf("%d ", aux -> vertice);
        aux = aux -> proximo;
    }

    printf("\n");
    return;
}

void lImprimeListaAdj(Lista l)
{
    // Prerequisitos (Lista nao nula):
    if(l == NULL)
        return;

    Lista aux = l;

    while(aux != NULL) {
        // Pega lista de vizinhos:
        Lista vizinhos = aux -> vizinhos;

        // Mostra vertice atual:
        printf("%d -> ", aux -> vertice);

        // Se nao houver vizinhos, mostra (null):
        if(vizinhos == NULL)
            printf("(null)\n");
        else {
            // Se houver vizinhos, separa por ',':
            while(vizinhos -> proximo != NULL) {
                printf("%d, ", vizinhos -> vertice);
                vizinhos = vizinhos -> proximo;
            }
            printf("%d\n", vizinhos -> vertice);
        }

        aux = aux -> proximo;
    }

    return;
}

void lRemoveVizinho(Lista l, int vertice, int vizinho)
{
    // Prerequisitos (Lista nao nula):
    if(l == NULL)
        return;

    Lista nodoVertice = lPegaVertice(l, vertice);
    Lista aux = nodoVertice -> vizinhos;

    // Se nao houver vizinhos, saia:
    if(aux == NULL)
        return;

    // Se for a primeira posicao:
    if(aux -> vertice == vizinho) {
        nodoVertice -> vizinhos = aux -> proximo;
        free(aux);
        return;
    }

    // Demais posicoes:
    while(aux -> proximo != NULL) {
        if(aux -> proximo -> vertice == vizinho) {
            // Remove vertice:
            Lista remover = aux -> proximo;
            aux -> proximo = aux -> proximo -> proximo;
            free(remover);
            return;
        }
        aux = aux -> proximo;
    }
    return;
}

void lInverteListaAdj(Lista l, int vertice)
{
    // Prerequisitos (Lista nao nula):
    if(l == NULL)
        return;

    Lista vizinhos = lPegaVertice(l, vertice);

    Lista anterior = vizinhos -> vizinhos;
    Lista guarda = anterior -> proximo;
    anterior -> proximo = NULL;

    while(guarda != NULL) {
        
        // Armazena o proximo:
        Lista prox = guarda -> proximo;

        // Inverte o proximo para o anterior:
        guarda -> proximo = anterior;

        // Atualiza os ponteiros:
        anterior = guarda;
        guarda = prox;
    }

    vizinhos -> vizinhos = anterior;

    return;
}

int lPertence(Lista l, int vertice)
{
    // Prerequisitos (Lista nao nula):
    if((l == NULL) || (vertice < 0))
        return 0;

    Lista aux = l;
    while(aux != NULL) {
        if(aux -> vertice == vertice) {
            return 1;
        }
        // Vertice nao encontrado, lista ordenada:
        else if(aux -> vertice > vertice)
            break;

        aux = aux -> proximo;
    }

    return 0;
}

int lVazia(Lista l)
{
	// Prerequisitos (Lista nao nula):
    if(l == NULL)
        return 1;

    return 0;
}

int lTamanho(Lista l)
{
	// Prerequisitos (Lista nao nula):
    if(l == NULL)
        return 0;

    int tamanho = 0;
    Lista aux = l;

    while(aux != NULL)
    {
    	tamanho++;
    	aux = aux -> proximo;
    }

    return tamanho;
}

int* lArrayElementos(Lista l, int *tam)
{
    // Prerequisitos (Lista nao nula):
    if(l == NULL)
        return NULL;

	*tam = lTamanho(l);
	int *array = (int*) malloc(sizeof(int) * (*tam));
    int i = 0;

    Lista aux = l;
    while(aux != NULL) {
        array[i] = aux -> vertice;
        i++;
        aux = aux -> proximo;
    }
	return array;
}