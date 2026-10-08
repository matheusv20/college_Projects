#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaDLI.h"

int main()
{
    ListaDLI *lista = criarListaDLI();
    ListaDLI *lista2 = criarListaDLI();

    inserirFimLDLI(5, lista);
    inserirFimLDLI(50, lista);
    inserirFimLDLI(5, lista);

    inserirFimLDLI(1, lista2);
    inserirFimLDLI(2, lista2);
    inserirFimLDLI(3, lista2);

    printf("\n");

    printf("LISTA ORDENADA: %d (1 SIM - 0 NÃO)", estaOrdenadasLDLI(lista));

    return 0;
}