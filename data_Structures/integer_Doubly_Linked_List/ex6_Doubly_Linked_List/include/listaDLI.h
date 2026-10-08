#ifndef LISTADLI_H
#define LISTADLI_H 1

#include "noDLI.h"

typedef struct lista_duplamente_inteiros
{
    NoDLI *inicio;
    NoDLI *fim;
    int tamanho;
} ListaDLI;

ListaDLI *criarListaDLI();

void inserirInicioLDLI(int valor, ListaDLI *pontLista);
void inserirFimLDLI(int valor, ListaDLI *pontLista);
void inserirElementoPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista);

void limparLDLI(ListaDLI *pontLista);
void destruirLDLI(ListaDLI **pontLista);

int removerInicioLDLI(ListaDLI *pontLista);
int removerFimLDLI(ListaDLI *pontLista);
int removerElementoPosicaoLDLI(int posicao, ListaDLI *pontLista);

int obterValorInicioLDLI(ListaDLI *pontLista);
int obterValorFimLDLI(ListaDLI *pontLista);
int obterValorPosicaoLDLI(int posicao, ListaDLI *pontLista);

int trocarValorInicioLDLI(int valor, ListaDLI *pontLista);
int trocarValorFimLDLI(int valor, ListaDLI *pontLista);
int trocarValorPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista);

void mostrarListaDLI(ListaDLI *pontLista);

int estaOrdenadasLDLI(ListaDLI *pontLista);

#endif