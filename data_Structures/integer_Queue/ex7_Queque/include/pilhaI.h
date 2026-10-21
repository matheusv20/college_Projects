#ifndef PILHAI_H
#define PILHAI_H 1

#include "noSLI.h"


typedef struct pilha_int
{
    NoSLI *topo;
    int tamanho;
} PilhaI;

PilhaI *criarPilhaInt();

void limparPilhaI(PilhaI *pontPilha);
void destruirPilhaI(PilhaI **pontpontPilha);
void mostrarPilhaI(PilhaI *pontPilha);

void empilharPilhaI(int valor, PilhaI *pontPilha);
int desempilharPilhaI(PilhaI *pontPilha);
int obterTopoPilhaI(PilhaI *pontPilha);

#endif