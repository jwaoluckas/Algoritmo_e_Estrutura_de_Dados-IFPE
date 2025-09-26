#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

void merge(int inicio, int meio, int fim, int tamanho_do_array, int Array[]){
    int i, j, k;
    
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(i = 0; i < n1; i++){
        L[i] = Array[inicio+i];
    }

    for(j = 0; j < n2; j++){
        R[j] = Array[meio+1+j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while((i < n1) && (j < n2)){
        if(L[i] <= R[j]){
            Array[k] = L[i];
            i++;
        }
        
        else{
            Array[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1){
        Array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        Array[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int inicio, int fim, int tamanho_do_array, int Array[]){
    system("cls");
    
    printf("\tMERGE SORT\n\n");

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
    
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        mergesort(inicio, meio, tamanho_do_array, Array);
        mergesort(meio+1, fim, tamanho_do_array, Array);
                
        merge(inicio, meio, fim, tamanho_do_array, Array);
    }

    if((inicio == 0) && (fim == tamanho_do_array - 1)){
        printf("\nArray final: ");
        for(int i = 0; i < tamanho_do_array; i++){
            printf("%d", Array[i]);

            if(i != tamanho_do_array - 1){
                printf(" | ");
            }
        }

    sleep(10);
    continuar();
    }
}