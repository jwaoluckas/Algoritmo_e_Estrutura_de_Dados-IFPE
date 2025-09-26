#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main() {
    No *lista = NULL;
    int opcao, valor;

    do{
        system("cls");

        printf("\n0 - Sair\n1 - Inserir no início\n2 - Inserir no final\n3 - Remover do início\n4 - Remover do final\n5 - Imprimir lista\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:{
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_no_inicio(&lista, valor);
                
                break;
            }

            case 2:{
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_no_fim(&lista, valor);
                
                break;
            }

            case 3:{
                remover_do_inicio(&lista);
                break;
            }
    
            case 4:{
                remover_do_fim(&lista);
                break;
            }

            case 5:{
                imprimir_lista(lista);
                system("pause");
                
                break;
            }

            case 0:{
                printf("Encerrando...\n");
                liberar_lista(&lista);
                
                break;
            }

            default:
                printf("Opcao invalida!\n");
        }
    }while (opcao != 0);

    return 0;
}