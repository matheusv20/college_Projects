#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"


int main()
{
    ListaSLI * lista = criarListaSLI();
    espaco();

    ListaSLI * lista2 = criarListaSLI();
    espaco();

    ListaSLI * lista3 = criarListaSLI();
    espaco();

    printf("+--------------------------------+\n");
    printf("| INSERIR ELEMENTOS EM UMA LISTA |\n");
    printf("+--------------------------------+\n");
    espaco();

    printf("+--------------+\n");
    printf("| -> PELO FIM  |\n");
    printf("+--------------+\n");
    espaco();

    printf("// Mostrando o primeiro elemento da lista: \n");
    printf("Primeiro Elemento da Lista: %d", obterValorInicioSLI(lista));
    espaco();

    printf("// Mostrando o último elemento da lista: \n");
    printf("Ultimo Elemento da Lista: %d", obterValorFimSLI(lista));
    espaco();

    printf("// Mostrando a lista: \n");
    mostrarListaSLI(lista);
    espaco();

    printf("// Inserindo o primeiro elemento da lista pelo fim e mostrando ela: \n");
    inserirFimSLI(10, lista);
    mostrarListaSLI(lista);
    espaco();

    printf("// Inserindo mais um elemento na lista pelo fim e mostrando ela: \n");
    inserirFimSLI(20, lista);
    mostrarListaSLI(lista);
    espaco();

    printf("// Inserindo mais um elemento na lista pelo fim e mostrando ela: \n");
    inserirFimSLI(30, lista);
    mostrarListaSLI(lista);
    espaco();

    printf("// Removendo o primeiro elemento da lista e mostrando ela: \n");
    printf("Remover o primeiro elemento da lista (se deu certo = 1, errado = 0):  %d\n\n", removerInicioLSLI(lista));
    mostrarListaSLI(lista);
    espaco();
    espaco();

    printf("// Mostrando o primeiro elemento da lista: \n");
    printf("Primeiro Elemento da Lista: %d", obterValorInicioSLI(lista));
    espaco();

    printf("// Mostrando o último elemento da lista: \n");
    printf("Ultimo Elemento da Lista: %d", obterValorFimSLI(lista));
    espaco();

    printf("// Removendo o último elemento da lista e mostrando ela: \n");
    printf("Remover último elemento da lista (se deu certo = 1, errado = 0): %d\n\n", removerFimLSLI(lista));
    mostrarListaSLI(lista);
    espaco();
    espaco();

    printf("+----------------+\n");
    printf("| -> PELO INÍCIO |\n");
    printf("+----------------+\n");
    espaco();

    mostrarListaSLI(lista2);
    espaco();

    removerInicioLSLI(lista2);

    printf("Primeiro Elemento da Lista: %d", obterValorInicioSLI(lista2));
    espaco();

    printf("Ultimo Elemento da Lista: %d", obterValorFimSLI(lista2));
    espaco();
    espaco();

    InserirInicioSLI(55, lista2);
    mostrarListaSLI(lista2);
    espaco();

    InserirInicioSLI(67, lista2);
    mostrarListaSLI(lista2);
    espaco();

    InserirInicioSLI(100, lista2);
    mostrarListaSLI(lista2);
    espaco(); 

    printf("Remover o primeiro elemento da lista (se deu certo = 1, errado = 0): %d\n\n", removerInicioLSLI(lista2));
    mostrarListaSLI(lista2);
    espaco();

    printf("Primeiro Elemento da Lista: %d", obterValorInicioSLI(lista2));
    espaco();

    printf("Ultimo Elemento da Lista: %d", obterValorFimSLI(lista2));
    espaco();

    printf("// Limpando lista");
    limparLSLI(lista2);
    espaco();

    mostrarListaSLI(lista2);
    espaco();
    espaco(); 


    printf("+--------------------------------+\n");
    printf("| -> LISTA ALEATORIA PARA TESTES |\n");
    printf("+--------------------------------+\n");
    espaco();
    

    InserirInicioSLI(55, lista3);
    InserirInicioSLI(30, lista3);
    InserirInicioSLI(67, lista3);
    InserirInicioSLI(100, lista3);
    mostrarListaSLI(lista3);
    espaco();

    int valorTrocar = 0;
    int elementoInserir = 0;
    int posicaoInserir = 0;
    int posicaoRemover = 0;
    int posicaoTrocar = 0;
    int elementoObter = 0;


    // printf("// Trocando o valor do primeiro elemento da lista e mostrando ela: \n");
    // printf("Digite o valor que você deseja inserir no primeiro nó na lista: ");
    // scanf("%d", &valorTrocar);
    // espaco();
    // printf("Trocar o valor do inicio da lista (se deu certo = 1, errado = 0): %d \n\n", trocarValorInicioLSLI(valorTrocar, lista3));
    // mostrarListaSLI(lista3);
    // espaco();


    // printf("// Trocando o valor do último elemento da lista e mostrando ela: \n");
    // printf("Digite o valor que você deseja inserir no último nó na lista: ");
    // scanf("%d", &valorTrocar);
    // espaco();
    // printf("Trocar o valor do fim da lista (se deu certo = 1, errado = 0): %d \n\n", trocarValorFimLSLI(valorTrocar, lista3));
    // mostrarListaSLI(lista3);
    // espaco();

    
    // printf("// Inserindo um valor em alguma posicao da lista e mostrando ela: \n");
    // printf("Digite o valor que você deseja inserir na lista: ");
    // scanf("%d", &elementoInserir);
    // espaco();
    // printf("Digite a posição que você deseja inserir: ");
    // scanf("%d", &posicaoInserir);
    // espaco();
    // printf("Inserindo o elemento %d na posição %d da lista (se deu certo = 1, errado = 0): %d \n\n", elementoInserir, posicaoInserir, inserirPosicaoLSLI(elementoInserir, posicaoInserir, lista3));
    // mostrarListaSLI(lista3);
    // espaco();

    // printf("// Removendo um valor em alguma posicao da lista e mostrando ela: \n");
    // printf("Digite a posição que você deseja remover: ");
    // scanf("%d", &posicaoRemover);
    // espaco();
    // printf("Removendo o elemento na posição %d da lista (se deu certo = 1, errado = 0): %d \n\n", posicaoRemover, removerPosicaoLSLI(posicaoRemover, lista3));
    // mostrarListaSLI(lista3);
    // espaco();

    // printf("// Trocando um valor em alguma posicao da lista e mostrando ela: \n");
    // printf("Digite a posição que você deseja trocar: ");
    // scanf("%d", &posicaoTrocar);
    // espaco();
    // printf("Digite o valor que você deseja trocar: ");
    // scanf("%d", &valorTrocar);
    // espaco();
    // printf("Trocando o elemento na posição %d da lista por %d (se deu certo = 1, errado = 0): %d \n\n", posicaoTrocar, valorTrocar, trocarPosicaoLSLI(valorTrocar, posicaoTrocar, lista3));
    // mostrarListaSLI(lista3);
    // espaco();

    printf("// Mostrando algum elemento da lista: \n");
    printf("Digite a posição que você deseja obter o elemento: ");
    scanf("%d", &elementoObter);
    printf("O elemento Nº %d da Lista é %d", elementoObter, obterValorPosicaoSLI(elementoObter, lista3));
    espaco();

    return 0;
}