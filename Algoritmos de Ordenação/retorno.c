#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers.h"

void continuar(){
    system("cls");
    
    int opcao;
    printf("Deseja continuar?\n"
    "0-NÆo\n"
    "1-Sim\n"
    "Responda: ");
    scanf("%d", &opcao);

    while((opcao < 0) || (opcao > 1)){
        printf("Op‡Æo indispon¡vel. Tente novamente!\n"
        "Deseja continuar?\n"
        "0-NÆo\n"
        "1-Sim\n"
        "Responda: ");
        scanf("%d", &opcao);
    }

    if(opcao == 0){
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

    else{
        main();
    }
}