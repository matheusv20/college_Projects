#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaDLI.h"

int main()
{
    ListaDLI * lista1 = criarListaDLI();

    inserirInicioLDLI(6, lista1);
    inserirInicioLDLI(5, lista1);
    inserirInicioLDLI(4, lista1);
    inserirInicioLDLI(3, lista1);
    inserirInicioLDLI(2, lista1);
    inserirInicioLDLI(1, lista1);

    mostrarListaDLI(lista1);

    removerElementoPosicaoLDLI(5, lista1);

    mostrarListaDLI(lista1);


    return 0;
}