#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

void selectionsort(int tamanho_do_array, int Array[]){
    system("cls");

    printf("\tSELECTION SORT\n\n");
    
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

    for(int i = 0; i < tamanho_do_array-1; i++){
        int menor_indice = i;

        for(int j = i+1; j < tamanho_do_array; j++){
            if(Array[j] < Array[menor_indice]){
                menor_indice = j;
            }
        }

        if(menor_indice != i){
            int a = Array[i];
            Array[i] = Array[menor_indice];
            Array[menor_indice] = a;
        }

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