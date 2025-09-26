#ifndef STACK_H
#define STACK_H

typedef struct{
    int valor;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa cria_pessoa();
void imprimir_pessoa(Pessoa p);

No* empilhar(No *topo);
No* desempilhar(No **topo);
void imprimir_pilha(No *topo);

#endif