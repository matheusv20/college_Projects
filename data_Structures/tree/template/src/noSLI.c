#include "noSLI.h"

NoSLI *criarNoSLI(int valor, NoSLI *proximo)
{
    NoSLI *novo = (NoSLI *) malloc(sizeof(NoSLI));
    novo->valor = valor;
    novo->proximo = proximo;
    return novo;
}