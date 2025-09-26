#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;
        
        if(*lista){
            (*lista)->anterior = novo;
        }

        *lista = novo;
    }
    
    else{
        printf("Erro ao alocar memória!\n");
    }
}

void inserir_no_fim(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        
        if(*lista == NULL){
            novo->anterior = NULL;
            *lista = novo;
        }
        
        else{
            No *aux = *lista;
            
            while (aux->proximo){
                aux = aux->proximo;
            }

            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    
    else{
        printf("Erro ao alocar memória!\n");
    }
}

void remover_do_inicio(No **lista){
    if(*lista){
        No *remover = *lista;
        *lista = remover->proximo;
        
        if(*lista){
            (*lista)->anterior = NULL;
        }

        printf("Removido do início: %d\n", remover->valor);
        free(remover);
    }
    
    else{
        printf("Lista vazia!\n");
    }
}

void remover_do_fim(No **lista){
    if(*lista){
        No *aux = *lista;
        
        while(aux->proximo){
            aux = aux->proximo;
        }

        if(aux->anterior){
            aux->anterior->proximo = NULL;
        }

        else{
            *lista = NULL;
        }

        printf("Removido do final: %d\n", aux->valor);
        free(aux);
    }
    
    else{
        printf("Lista vazia!\n");
    }
}

void imprimir_lista(No *no){
    int tamanho = 0;
    No *inicio = no;
    No *fim = NULL;

    printf("\nLista: ");

    while(no){
        printf("%d ", no->valor);
        
        fim = no;
        no = no->proximo;
        tamanho++;
    }

    printf("\n");
    printf("Início: %s\n", inicio ? (sprintf((char[12]){0}, "%d", inicio->valor), (char[12]){0}) : "NULL");
    printf("Final: %s\n", fim ? (sprintf((char[12]){0}, "%d", fim->valor), (char[12]){0}) : "NULL");
    printf("Tamanho: %d\n", tamanho);
    printf("Memória alocada: %lu bytes\n\n", tamanho * sizeof(No));
}

void liberar_lista(No **lista){
    No *aux = *lista;

    while(aux){
        No *temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    
    *lista = NULL;
}