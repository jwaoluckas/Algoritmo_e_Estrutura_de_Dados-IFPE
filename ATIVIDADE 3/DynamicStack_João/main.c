#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){
    No *remover = NULL;
    No *topo = NULL;
    
    int opcao = -1;

    while(opcao != 0){
        printf("\nMenu:\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir\n");
        printf("0 - Encerrar o programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:{
                topo = empilhar(topo);
                break;
            }

            case 2:{
                remover = desempilhar(&topo);
                
                if(remover){
                    printf("Elemento removido:\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                }

                break;
            }

            case 3:{
                imprimir_pilha(topo);
                break;
            }

            case 0:{
                printf("Encerrando o programa...\n");
                break;
            }

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        if(opcao != 0){
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    }

    return 0;
}
