#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaDLI.h"

int main()
{
    ListaDLI *lista = criarListaDLI();

    inserirFimSLI(3, lista);

    mostrarListaDLI(lista);

    return 0;
}