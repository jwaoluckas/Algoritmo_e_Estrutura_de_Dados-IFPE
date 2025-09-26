#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

int encontrar_maior(int tamanho_do_array, int Array[]){
    int maior = Array[0];

    for(int i = 1; i < tamanho_do_array; i++){
        if(Array[i] > maior){
            maior = Array[i];
        }
    }

    return maior;
}

void counting_sort_por_digito(int exp, int tamanho_do_array, int Array[]){
    int resultado[tamanho_do_array];
    int contagem[10] = {0};

    for(int i = 0; i < tamanho_do_array; i++){
        contagem[(Array[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        contagem[i] += contagem[i-1];
    }

    for(int i = tamanho_do_array-1; i >= 0; i--){
        int pos = (Array[i] / exp) % 10;
        resultado[contagem[pos] - 1] = Array[i];
        contagem[pos]--;
    }

    for(int i = 0; i < tamanho_do_array; i++){
        Array[i] = resultado[i];
    }
}

void radixsort(int tamanho_do_array, int Array[]){
    system("cls");

    printf("\tRADIX SORT\n\n");
    
    printf("Array original: ");
    for(int i = 0; i < tamanho_do_array; i++){
        printf("%d", Array[i]);

        if(i != tamanho_do_array-1){
            printf(" | ");
        }

        else{
            printf("\n");
        }
    }

    int maior = encontrar_maior(tamanho_do_array, Array);

    for(int exp = 1; maior/exp > 0; exp *= 10){
        counting_sort_por_digito(exp, tamanho_do_array, Array);

        printf("Array ap¢s ordenar pelo d¡gito %d: ", exp);
        for(int i = 0; i < tamanho_do_array; i++){
            printf("%d", Array[i]);

            if(i != tamanho_do_array-1){
                printf(" | ");
            }
        }

        printf("\n");
    }

    sleep(10);
    continuar();
}