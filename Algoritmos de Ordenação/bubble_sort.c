#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

void bubblesort(int tamanho_do_array, int Array[]){
    system("cls");

    printf("\tBUBBLE SORT\n\n");
    
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

    int tamanho_do_array_original = tamanho_do_array;
    int loop = 0;

    while(loop == 0){
        loop = 1;

        for(int i = 0; i < tamanho_do_array-1; i++){
            if(Array[i] > Array[i+1]){
                loop = 0;

                int a = Array[i];
                Array[i] = Array[i+1];
                Array[i+1] = a;
            }
        }

        tamanho_do_array -= 1;
    }

    printf("Array final: ");
    for(int i = 0; i < tamanho_do_array_original; i++){
        printf("%d", Array[i]);

        if(i != tamanho_do_array_original-1){
            printf(" | ");
        }
    }

    sleep(10);
    continuar();
}