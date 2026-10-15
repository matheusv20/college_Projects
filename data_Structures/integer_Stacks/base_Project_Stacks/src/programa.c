#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"
#include "pilhaI.h"


int main()
{
    PilhaI * pilha = criarPilhaInt();

    mostrarPilhaI(pilha);

    empilharPilhaI(2, pilha);
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));

    empilharPilhaI(7, pilha);
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));

    empilharPilhaI(4, pilha);
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));

    empilharPilhaI(12, pilha);
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));

    empilharPilhaI(6, pilha);
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));


    mostrarPilhaI(pilha);


    printf("Desempilhou: %d\n", desempilharPilhaI(pilha));
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));
    mostrarPilhaI(pilha);

    printf("Desempilhou: %d\n", desempilharPilhaI(pilha));
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));
    mostrarPilhaI(pilha);

    printf("Desempilhou: %d\n", desempilharPilhaI(pilha));
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));
    mostrarPilhaI(pilha);

    printf("Desempilhou: %d\n", desempilharPilhaI(pilha));
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));
    mostrarPilhaI(pilha);

    printf("Desempilhou: %d\n", desempilharPilhaI(pilha));
    printf("Topo: %d\n\n", obterTopoPilhaI(pilha));
    mostrarPilhaI(pilha);


    printf("Desempilhou: %d\n\n", desempilharPilhaI(pilha));


    empilharPilhaI(2, pilha);
    empilharPilhaI(7, pilha);
    empilharPilhaI(4, pilha);
    empilharPilhaI(12, pilha);
    empilharPilhaI(6, pilha);

    mostrarPilhaI(pilha);

    limparPilhaI(pilha);

    mostrarPilhaI(pilha);

    destruirPilhaI(&pilha);
}