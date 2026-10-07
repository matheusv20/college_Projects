#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"


int main()
{
    ListaSLI * lista = criarListaSLI();

    inserirFimSLI(10, lista);
    inserirFimSLI(10, lista);
    inserirFimSLI(20, lista);
    inserirFimSLI(10, lista);
    inserirFimSLI(20, lista);
    inserirFimSLI(30, lista);
    inserirFimSLI(30, lista);
    inserirFimSLI(2, lista);
    inserirFimSLI(4, lista);

    ListaSLI * nova = criarCopiaSemRepeticaoLSLI(lista);


    mostrarListaSLI(nova);

    return 0;
}