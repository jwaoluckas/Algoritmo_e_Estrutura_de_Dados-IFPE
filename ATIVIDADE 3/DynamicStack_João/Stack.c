#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Pessoa cria_pessoa(){
    Pessoa p;

    printf("Digite um número: ");
    scanf("%d", &p.valor);
    getchar();
    
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("Valor: %d\n", p.valor);
}

No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo->p = cria_pessoa();
        novo->proximo = topo;
        
        return novo;
    }
    
    else{
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
}

No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        
        return remover;
    }
    
    else{
        printf("Pilha vazia!\n");
        return NULL;
    }
}

void imprimir_pilha(No *topo){
    int tamanho = 0;

    No *temp = topo;
    size_t memoria = 0;

    printf("\n------ PILHA ------\n");
    
    while(temp){
        imprimir_pessoa(temp->p);
        temp = temp->proximo;
        tamanho++;
        memoria += sizeof(No);
    }

    printf("-------------------\n");

    if(topo){
        printf("Topo: ");
        imprimir_pessoa(topo->p);
    }
    
    else{
        printf("Topo: (vazio)\n");
    }

    printf("Tamanho: %d\n", tamanho);
    printf("Memória alocada: %zu bytes\n", memoria);
}
