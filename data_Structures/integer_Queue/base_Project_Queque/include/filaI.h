#ifndef FILAI_H
#define FILAI_H 1

#include "noSLI.h"

typedef struct fila_int
{
    NoSLI *inicio;
    NoSLI *fim;
    int tamanho;
} FilaI;

FilaI * criarFilaI();

void limparFilaI(FilaI *pontFila);
void destruirFilaI(FilaI **pontPontFila);
void mostrarFilaI(FilaI *pontFila);

void enfileirarI(int valor, FilaI *pontFila);
int desinfileirarI(FilaI *pontFila);
int proximoI(FilaI *pontFila);

#endif