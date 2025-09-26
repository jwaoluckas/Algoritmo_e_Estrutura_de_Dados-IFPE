#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros = NULL; // "Array vazio"
    int tamanho = 0;

    // Adicionando elementos dinamicamente
    numeros = realloc(numeros, (tamanho + 1) * sizeof(int));
    numeros[tamanho++] = 10;

    numeros = realloc(numeros, (tamanho + 1) * sizeof(int));
    numeros[tamanho++] = 20;

    // Exibir elementos
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }

    free(numeros); // Liberar memória
    return 0;
}

whi