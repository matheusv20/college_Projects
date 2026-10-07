#ifndef LISTASLI_H
#define LISTASLI_H 1

#include "noSLI.h"


typedef struct listasimples_int
{
    NoSLI *inicio;
    int tamanho;
} ListaSLI;

ListaSLI *criarListaSLI();

void mostrarListaSLI(ListaSLI *pontLista);

void inserirFimSLI(int valor, ListaSLI *pontLista);
void InserirInicioSLI(int valor, ListaSLI *pontLista);
int inserirPosicaoLSLI(int valor, int posicao, ListaSLI *pontLista);

int obterValorInicioSLI(ListaSLI *pontLista);
int obterValorFimSLI(ListaSLI *pontLista);
int obterValorPosicaoSLI(int posicao, ListaSLI *pontLista);

int removerInicioLSLI(ListaSLI *pontLista);
int removerFimLSLI(ListaSLI *pontLista);
int removerPosicaoLSLI(int posicao, ListaSLI *pontLista);

void limparLSLI(ListaSLI *pontLista);
void destruirLSLI(ListaSLI **pontPontLista);

int trocarValorInicioLSLI(int valor, ListaSLI *pontLista);
int trocarValorFimLSLI(int valor, ListaSLI *pontLista);
int trocarPosicaoLSLI(int valor, int posicao, ListaSLI *pontLista);





#endif