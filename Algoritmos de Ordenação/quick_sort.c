#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

int particionar(int inicio, int fim, int tamanho_do_array, int Array[]){
    int pivo = Array[inicio];
    int i = inicio + 1;
    int j = fim;

    while(i <= j){
        while(i <= fim){
            if(Array[i] <= pivo){
                i++;
            }

            else{
                break;
            }
        }

        while(j >= inicio){
            if(Array[j] > pivo){
                j--;
            }

            else{
                break;
            }
        }

        if(i < j){
            int temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
        }
    }

    int temp = Array[inicio];
    Array[inicio] = Array[j];
    Array[j] = temp;

    return j;
}

void quicksort(int inicio, int fim, int tamanho_do_array, int Array[]){
    if((inicio == 0) && (fim == tamanho_do_array-1)){
        system("cls");
        
        printf("\tQUICK SORT\n\n");
        
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
    }

    if(inicio < fim){
        int pi = particionar(inicio, fim, tamanho_do_array, Array);
        
        quicksort(inicio, pi-1, tamanho_do_array, Array);
        quicksort(pi+1, fim, tamanho_do_array, Array);
    }

    if((inicio == 0) && (fim == tamanho_do_array-1)){
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
}