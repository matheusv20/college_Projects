#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"
#include "pilhaI.h"

void mostrarEmBinario(int valor);


int main()
{   
    int numero = 0;

    printf("Digite um número: ");
    scanf("%d", &numero);
    espaco();

    printf("Número em binário: ");

    mostrarEmBinario(numero);
}

void mostrarEmBinario(int valor)
{
    PilhaI * pilha = criarPilhaInt();

    while (valor > 0)
    {
        int resto = valor % 2;

        empilharPilhaI(resto, pilha);

        valor = valor/2;
    }

    while(pilha->tamanho > 0)
    {
        printf("%d", obterTopoPilhaI(pilha));

        desempilharPilhaI(pilha);
    }

    espaco();

    destruirPilhaI(&pilha);
    printf("\n\nPrograma Finalizado.\n");
    

}
