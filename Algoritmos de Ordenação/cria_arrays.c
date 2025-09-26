#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "headers.h"

void arrays(int tamanho_do_array){
    int array[tamanho_do_array];
    
    int inicio = 10;
    int fim = 500;

    srand(time(NULL));

    for(int i = 0; i < tamanho_do_array; i++){
        int num_aleatorio = inicio + rand() % (fim - inicio + 1);
        array[i] = num_aleatorio;

        if(i != 0){
            while(array[i-1] == array[i]){
                int num_aleatorio = inicio + rand() % (fim - inicio + 1);
                array[i] = num_aleatorio;
            }
        }
    }

    system("cls");

    int opcao;
    printf("Escolha uma op‡Æo:\n"
    "0-Fechar Aplica‡Æo\n"
    "1-BUBBLE SORT\n"
    "2-SELECTION SORT\n"
    "3-INSERTION SORT\n"
    "4-MERGE SORT\n"
    "5-QUICK SORT\n"
    "6-RADIX SORT\n"
    "7-COUNTING SORT\n"
    "Responda: ");
    scanf("%d", &opcao); 

    while((opcao < 0) || (opcao > 7)){
        system("cls");
        
        printf("Op‡Æo indispon¡vel. Tente novamente!\n"
        "Escolha uma op‡Æo:\n"
        "0-Fechar Aplica‡Æo"
        "1-BUBBLE SORT\n"
        "2-SELECTION SORT\n"
        "3-INSERTION SORT\n"
        "4-MERGE SORT\n"
        "5-QUICK SORT\n"
        "6-RADIX SORT\n"
        "7-COUNTING SORT\n"
        "Responda: ");
        scanf("%d", &opcao); 
    }

    if(opcao == 1){
        bubblesort(tamanho_do_array, array);
    }

    else if(opcao == 2){
        selectionsort(tamanho_do_array, array);
    }

    else if(opcao == 3){
        insertionsort(tamanho_do_array, array);
    }

    else if(opcao == 4){
        mergesort(0, tamanho_do_array-1, tamanho_do_array, array);
    }

    else if(opcao == 5){
        quicksort(0, tamanho_do_array-1, tamanho_do_array, array);
    }

    else if(opcao == 6){
        radixsort(tamanho_do_array, array);
    }

    else if(opcao == 7){
        countingsort(tamanho_do_array, array);
    }

    else{
        system("cls");

        printf("Encerrando o programa\n");
        sleep(1);
        system("cls");
        printf("Encerrando o programa.\n");
        sleep(1);
        system("cls");
        printf("Encerrando o programa..\n");
        sleep(1);
        system("cls");
        printf("Encerrando o programa...\n");
        sleep(1);
        system("cls");
        printf("Programa encerrado!");
        exit(0);
    }
}