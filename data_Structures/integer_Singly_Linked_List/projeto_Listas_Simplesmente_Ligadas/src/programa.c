#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"


int main()
{
    ListaSLI *lista = criarListaSLI();

    inserirFimSLI(3, lista);
    
    return 0;
}