#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "filaI.h"
#include "pilhaI.h"

void inverterFila(FilaI *pontFila);

int main()
{   

    FilaI *fila = criarFilaI();

    enfileirarI(2, fila);
    enfileirarI(3, fila);
    enfileirarI(7, fila);
    enfileirarI(8, fila);
    enfileirarI(10, fila);
    mostrarFilaI(fila);

    inverterFila(fila);
    mostrarFilaI(fila);

    destruirFilaI(&fila);
    
    return 0;   
}

void inverterFila(FilaI *pontFila)
{
    PilhaI *pilha = criarPilhaInt();

    while (pontFila->tamanho > 0)
    {
        empilharPilhaI(proximoI(pontFila), pilha);
        desinfileirarI(pontFila);
    }

    while (pilha->tamanho > 0)
    {
        enfileirarI(obterTopoPilhaI(pilha), pontFila);
        desempilharPilhaI(pilha);
    }


    destruirPilhaI(&pilha);
}