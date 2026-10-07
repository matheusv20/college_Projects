#ifndef NODLI_H
#define NODLI_H 1

#include <stdlib.h>
#include <stdio.h>

typedef struct no_duplamente_ligados_inteiros
{
    int valor;
    struct no_duplamente_ligados_inteiros *anterior;
    struct no_duplamente_ligados_inteiros *proximo;
} NoDLI;

NoDLI *criarNoDLI(int valor, NoDLI *anterior, NoDLI *proximo);



#endif