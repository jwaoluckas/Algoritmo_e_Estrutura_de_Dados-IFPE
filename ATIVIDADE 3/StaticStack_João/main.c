#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){
    No *remover = NULL;
    No *topo = NULL;
    
    int opcao = -1;

    while(opcao != 0){
        system("cls");

        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\nEscolha: ");
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
                printf("Opção inválida!\n");
        }

        if(opcao != 0){
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    }

    return 0;
}
