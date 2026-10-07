#include "noDLI.h"

NoDLI *criarNoDLI(int valor, NoDLI *anterior, NoDLI *proximo)
{
    NoDLI *novo = (NoDLI *) malloc(sizeof(NoDLI));
    novo->valor = valor;
    novo->anterior = anterior;
    novo->proximo = proximo;
    return novo;
}