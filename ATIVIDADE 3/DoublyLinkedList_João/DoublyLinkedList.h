// DoublyLinkedList.h

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

void inserir_no_inicio(No **lista, int num);
void inserir_no_fim(No **lista, int num);
void remover_do_inicio(No **lista);
void remover_do_fim(No **lista);
void imprimir_lista(No *no);
void liberar_lista(No **lista);

#endif