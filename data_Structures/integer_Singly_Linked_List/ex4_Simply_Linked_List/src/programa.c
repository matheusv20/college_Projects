#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"


int main()
{
    ListaSLI * lista = criarListaSLI();
    ListaSLI * lista2 = criarListaSLI();

    inserirFimSLI(10, lista);
    inserirFimSLI(20, lista);
    inserirFimSLI(30, lista);

    inserirFimSLI(40, lista2);
    inserirFimSLI(50, lista2);
    inserirFimSLI(60, lista2);

    ListaSLI *concatenada = concaternarLSLI(lista, lista2);
    
    mostrarListaSLI(concatenada);
    
    return 0;
}