#include "utilidades.h"

void lerString(char texto[], int tamanho)
{
    if (fgets(texto, tamanho, stdin) != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
    } else {
        printf("Erro lendo uma String.\n");
        exit(1);
    }
}

int lerInt()
{
    char texto[255];
    lerString(texto, 255);
    return atoi(texto);
}

float lerFloat()
{
    char texto[255];
    lerString(texto, 255);
    return (float)atof(texto);
}

void espaco()
{
    printf("\n\n");
}