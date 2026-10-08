#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaDLI.h"

int main()
{
    ListaDLI *lista = criarListaDLI();
    ListaDLI *lista2 = criarListaDLI();

    inserirFimLDLI(1, lista);
    inserirFimLDLI(2, lista);
    inserirFimLDLI(3, lista);

    inserirFimLDLI(1, lista2);
    inserirFimLDLI(2, lista2);
    inserirFimLDLI(3, lista2);

    printf("\n");

    printf("LISTAS IGUAIS: %d (1 SIM - 0 NÃO)", saoIdenticasLDLI(lista, lista2));

    return 0;
}