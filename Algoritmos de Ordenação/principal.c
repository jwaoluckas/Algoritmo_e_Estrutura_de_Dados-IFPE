#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include "headers.h"

int main(){
    system("cls");

    int tamanho;
    printf("Escolha um tamanho para o array:\n"
    "1-Array de tamanho 5.000\n"
    "2-Array de tamanho 10.000\n"
    "3-Array de tamanho 25.000\n"
    "4-Array de tamanho 100.000\n"
    "5-Array de tamanho 500.000\n"
    "Responda: ");
    scanf("%d", &tamanho);

    while((tamanho < 1) || (tamanho > 5)){
        system("cls");

        printf("Op��o indispon�vel. Tente novamente!\n"
        "Escolha um tamanho para o array:\n"
        "1-Array de tamanho 5.000\n"
        "2-Array de tamanho 10.000\n"
        "3-Array de tamanho 25.000\n"
        "4-Array de tamanho 100.000\n"
        "5-Array de tamanho 500.000\n"
        "Responda: ");
        scanf("%d", &tamanho);        
    }

    if(tamanho == 1){
        tamanho = 5;
        arrays(tamanho);
    }

    else if(tamanho == 2){
        tamanho = 10000;
        arrays(tamanho);
    }

    else if(tamanho == 3){
        tamanho = 25000;
        arrays(tamanho);
    }

    else if(tamanho == 4){
        tamanho = 100000;
        arrays(tamanho);
    }

    else{
        tamanho = 500000;
        arrays(tamanho);
    }

    return 0;
}