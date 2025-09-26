#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

int encontrando_o_maior(int tamanho_do_array, int Array[]){
    int maior = Array[0];

    for(int i = 1; i < tamanho_do_array; i++){
        if(Array[i] > maior){
            maior = Array[i];
        }
    }

    return maior;
}

void countingsort(int tamanho_do_array, int Array[]){
    system("cls");
    
    int maior = encontrando_o_maior(tamanho_do_array, Array);
    int contagem[maior+1];
        
    printf("\tCOUNTING SORT\n\n");
    
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

    for(int i = 0; i <= maior; i++){
        contagem[i] = 0;
    }

    for(int i = 0; i < tamanho_do_array; i++){
        contagem[Array[i]]++;
    }

    int index = 0;

    for(int i = 0; i <= maior; i++){
        while(contagem[i] > 0){
            Array[index] = i;
            index++;
            contagem[i]--;
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