#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

void insertionsort(int tamanho_do_array, int Array[]){
    system("cls");

    printf("\tINSERTION SORT\n\n");

    printf("Array original: ");
    for(int i = 0; i < tamanho_do_array; i++){
        printf("%d", Array[i]);

        if(i != tamanho_do_array-1){
            printf(" | ");
        }

        else{
            printf("\n\n");
        }
    }

    for(int i = 1; i < tamanho_do_array; i++){
        int chave = Array[i];
        int j = i-1;

        while((j >= 0) && (Array[j] > chave)){
            Array[j+1] = Array[j];
            j -= 1;
        }

        Array[j+1] = chave;

        printf("Array sendo tratado: ");
        for(int x = 0; x < tamanho_do_array; x++){
            printf("%d", Array[x]);

            if(x != tamanho_do_array-1){
                printf(" | ");
            }

            else{
                printf("\n\n");
            }
        }
    }

    printf("Array final: ");
    for(int i = 0; i < tamanho_do_array; i++){
        printf("%d", Array[i]);

        if(i != tamanho_do_array-1){
            printf(" | ");
        }
    }

    sleep(10);
    continuar();
}