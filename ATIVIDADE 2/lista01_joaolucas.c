/* Aluno: JoÆo Lucas da Silva Soares Oliveira
   Data: 04/04/2025
   Disciplina: Algoritmo e Estrutura de Dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int loop = 0;

    while(loop == 0){
        void par_ou_impar(){
            system("cls");
            
            int num;

            printf("Digite um n£mero: ");
            scanf("%d", &num);

            if(num % 2 == 0){
                printf("O n£mero %d ‚ par", num);  
            }

            else{
                printf("O n£mero %d ‚ ¡mpar", num);
            }
            
            sleep(2);
        }

        void leia_tres_numeros(){
            system("cls");

            int maior_num;
            int menor_num;

            int num1, num2, num3;

            printf("Digite seus 3 n£meros: ");
            scanf("%d %d %d", &num1, &num2, &num3);

            if((num1 > num2) && (num1 > num3)){
                maior_num = num1;

                if(num2 > num3){
                    menor_num = num3;
                }

                else{
                    menor_num = num2;
                }

            }

            else if((num2 > num1) && (num2 > num3)){
                maior_num = num2;

                if(num1 > num3){
                    menor_num = num3;
                }

                else{
                    menor_num = num1;
                }

            }

            else if((num3 > num2) && (num3 > num1)){
                maior_num = num3;

                if(num2 > num1){
                    menor_num = num2;
                }

                else{
                    menor_num = num1;
                }

            }

            printf("Maior n£mero = %d", maior_num);
            printf("\n");
            printf("Menor n£mero = %d", menor_num);

            sleep(2);
        }

        void idade(){
            system("cls");

            int idade_do_usuario;

            printf("Digite sua idade: ");
            scanf("%d", &idade_do_usuario);

            while((idade_do_usuario < 1) || (idade_do_usuario > 120)){
                system("cls");

                printf("Digite sua idade: ");
                scanf("%d", &idade_do_usuario);
            }

            if(idade_do_usuario < 18){
                printf("Usu rio menor de 18 anos.");
            }

            else if((idade_do_usuario >= 18) && (idade_do_usuario <= 60)){
                printf("Usu rio ‚ adulto.");
            }

            else{
                printf("Usu rio ‚ idoso.");
            }

            sleep(2);
        }

        void positivo_negativo_neutro(){
            system("cls");

            int num;

            printf("Digite um n£mero: ");
            scanf("%d", &num);

            if(num > 0){
                printf("O n£mero %d ‚ positivo.", num);
            }

            else if(num == 0){
                printf("O n£mero %d ‚ neutro.", num);
            }

            else{
                printf("O n£mero %d ‚ negativo.", num);
            }

            sleep(2);
        }

        void aluno(){
            system("cls");

            float nota1;
            float nota2;

            for (int i = 1; i < 3; i++){
                float nota;

                printf("Digite sua %dø nota: ", i);
                scanf("%f", &nota);

                while((nota < 0) || (nota > 10)){
                    system("cls");

                    printf("Op‡Æo indispon¡vel, tente novamente!\nDigite sua %dø nota: ", i);
                    scanf("%f", &nota);
                }

                if(i == 1){
                    nota1 = nota;
                }

                else{
                    nota2 = nota;
                }
            }

            float media;
            media = (nota1 + nota2) / 2;

            if(media >= 7){
                printf("Aluno aprovado com m‚dia %2.f", media);
            }

            else if(media >= 5){
                printf("Aluno ficou em recupere‡Æo com m‚dia %2.f", media);
            }

            else{
                printf("Aluno reprovado com m‚dia %2.f", media);
            }

            sleep(2);
        }

        void um_a_cem(){
            system("cls");

            for (int i = 1; i < 101; i++){
                printf("%d\n", i);
            }

            sleep(2);
        }

        void soma_de_um_a_seu_numero(){
            system("cls");
            
            int numero;
            int todos_somados = 0;

            printf("Digite um n£mero: ");
            scanf("%d", &numero);

            for (int i = 1; i < numero+1; i++){
                todos_somados += i;
            }

            printf("A soma de todos os n£meros entre 1 e %d ‚ = %d", numero, todos_somados);

            sleep(2);
        }

        void tabuada(){
            system("cls");

            int numero;

            printf("Digite um n£mero: ");
            scanf("%d", &numero);

            for (int i = 1; i <= 10; i++){
                int tabuada;
                tabuada = numero * i;

                printf("%dx%d = %d", numero, i, tabuada);

                if(i != 10){
                    printf("\n");
                }
            }

            sleep(4);
        }

        void divisores(){
            system("cls");

            int numero;

            printf("Digite um n£mero: ");
            scanf("%d", &numero);
            
            for (int i = 1; i <= numero; i++){
                if(numero % i == 0){
                    printf("%d ‚ divisor de %d", i, numero);

                    if(i != numero){
                        printf("\n");
                    }
                }
            }

            sleep(3);
        }

        void todos_os_positivos_somados(){
            system("cls");

            int numero;
            int todos_somados = 0;

            printf("Digite um n£mero: ");
            scanf("%d", &numero);

            while(numero >= 0){
                todos_somados += numero;

                printf("Digite um n£mero: ");
                scanf("%d", &numero);
            }

            printf("Todos os nÆo negativos somados = %d", todos_somados);

            sleep(3);
        }

        void piramide_de_asteriscos(){
            system("cls");

            char branco = ' ';
            int numero;

            printf("Digite um n£mero: ");
            scanf("%d", &numero);

            for (int i = 0; i < numero; i++){
                for (int n = 0; n < numero - i - 1; n++){
                    printf("%c", branco);
                }

                for (int x = 0; x < (2 * i + 1); x++){
                    printf("*");
                }

                printf("\n");

            }

            sleep(4);
        }

        void dez_vetores(){
            system("cls");

            int array[10];
            int tamanho_array = 0;

            for (int i = 1; i <= 10; i++){
                int numero;

                printf("Digite seu %dø n£mero: ", i);
                scanf("%d", &numero);

                printf("\n");

                array[tamanho_array++] = numero;
            }

            int loop = 0;
            int tamanho = sizeof(array) / sizeof(array[0]);
            
            while(loop == 0){
                loop = 1;

                for (int x = 0; x < tamanho-1; x++){
                    if(array[x] < array[x+1]){
                        loop = 0;

                        int a;

                        a = array[x];
                        array[x] = array[x+1];
                        array[x+1] = a;
                    }
                }

                tamanho -= 1;

            }

            printf("Maior n£mero = %d\n", array[0]);
            printf("Menor n£mero = %d", array[9]);

            sleep(4);
        }

        void cinco_numeros_array_ao_contrario(){
            system("cls");

            int array[5];
            int tamanho_array = 0;

            for (int i = 1; i <= 5; i++){
                int numero;

                printf("Digite seu %dø n£mero: ", i);
                scanf("%d", &numero);

                printf("\n");

                array[tamanho_array++] = numero;
            }

            int tamanho = sizeof(array) / sizeof(array[0]);

            printf("Array invertido: \n");

            for (int i = tamanho-1; i >= 0; i--){
                printf("%d\n", array[i]);
            }

            sleep(4);
        }

        void soma_dois_array(){
            system("cls");

            int array1[5];
            int array2[5];
            int soma_arrays[5];

            int soma = 0;

            for (int i = 1; i <= 2; i++){
                int tamanho_arrays = 0;

                for (int n = 1; n <= 5; n++){
                    int numero;

                    printf("Digite seu %dø n£mero do %dø array: ", n, i);
                    scanf("%d", &numero);

                    printf("\n");

                    if(i == 1){
                        array1[tamanho_arrays++] = numero;
                    }

                    else{
                        array2[tamanho_arrays++] = numero;
                    }
                }
            }

            int tamanho_arrays = 0;

            for (int i = 0; i < 5; i++){
                soma = array1[i] + array2[i];
                soma_arrays[tamanho_arrays++] = soma;
            }

            printf("Soma dos arrays: \n");

            for (int i = 0; i < 5; i++){
                printf("%d\n", soma_arrays[i]);
            }

            sleep(4);
        }

        void exibir_pares_do_array(){
            system("cls");

            int array[10];
            int tamanho_array = 0;

            for (int i = 1; i <= 10; i++){
                int numero;

                printf("Digite seu %dø n£mero: ", i);
                scanf("%d", &numero);

                printf("\n");

                array[tamanho_array++] = numero;
            }

            printf("N£meros pares do array: \n");

            for (int i = 0; i < 10; i++){
                if(array[i] % 2 == 0){
                    printf("%d\n", array[i]);
                }
            }

            sleep(3);
        }

        void positivos_negativos_e_neutro_no_aray(){
            system("cls");

            int array[10];
            int tamanho_array = 0;

            for (int i = 1; i <= 10; i++){
                int numero;

                printf("Digite seu %dø n£mero: ", i);
                scanf("%d", &numero);

                printf("\n");

                array[tamanho_array++] = numero;
            }

            for (int i = 0; i < 10; i++){
                if(array[i] > 0){
                    printf("Positivo: %d\n", array[i]);
                }
            }

            printf("\n");

            for (int i = 0; i < 10; i++){
                if(array[i] < 0){
                    printf("Negativo: %d\n", array[i]);
                }
            }

            printf("\n");

            for (int i = 0; i < 10; i++){
                if(array[i] == 0){
                    printf("Neutro: %d\n", array[i]);
                }
            }


            sleep(4);
        }

        void string_ao_contrario(){
            system("cls");

            char palavra[20];

            printf("Digite uma palavra de at‚ 20 caracteres abaixo: ");
            scanf(" %[^\n]s", palavra);

            int tamanho_palavra = strlen(palavra);
    
            printf("\nPalavra ao contr rio: ");

            for (int i = tamanho_palavra-1; i >= 0; i--){
                printf("%c", palavra[i]);
            }

            sleep(4);
        }

        void quantidade_vogais(){
            system("cls");

            char palavra[20];

            printf("Digite uma palavra de at‚ 20 caracteres abaixo: ");
            scanf(" %[^\n]s", palavra);

            int tamanho_palavra = strlen(palavra);
            int qtd_vogais = 0;

            for (int i = 0; i < tamanho_palavra; i++){
                if((palavra[i] == 'a') || (palavra[i] == 'A')){
                    qtd_vogais += 1;
                }

                else if((palavra[i] == 'e') || (palavra[i] == 'E')){
                    qtd_vogais += 1;
                }

                else if((palavra[i] == 'i') || (palavra[i] == 'I')){
                    qtd_vogais += 1;
                }
            
                else if((palavra[i] == 'o') || (palavra[i] == 'O')){
                    qtd_vogais += 1;
                }

                else if((palavra[i] == 'u') || (palavra[i] == 'U')){
                    qtd_vogais += 1;
                }
            }

            printf("Sua palavra tem %d vogais.", qtd_vogais);

            sleep(4);
        }

        void duas_strings_iguais(){
            system("cls");

            char palavra1[20];
            char palavra2[20];

            for (int i = 1; i <= 2; i++){
                printf("Digite a %dø string de at‚ 20 caracteres: ", i);
                
                if(i == 1){
                    scanf(" %[^\n]s", palavra1);
                }

                else{
                    scanf(" %[^\n]s", palavra2);
                }
            }

            int tamanho_palavra1 = strlen(palavra1);
            int tamanho_palavra2 = strlen(palavra2);

            int contador = 0;

            if(tamanho_palavra1 != tamanho_palavra2){
                printf("As strings %s e %s nÆo sÆo iguais:)", palavra1, palavra2);
            }

            else{
                for (int i = 0; i < tamanho_palavra1; i++){
                    if(palavra1[i] == palavra2[i]){
                        contador += 1;
                    }
                }

                if(contador == tamanho_palavra1){
                    printf("As strings %s e %s sÆo iguais:)", palavra1, palavra2);
                }
            }

            sleep(5);
        }

        void troca_espaco_por_hifen(){
            system("cls");

            char palavra[20];
            char nova_palavra[20];
            int tamanho_nova_palavra = 0;

            printf("Digite uma palavra de at‚ 20 caracteres abaixo: ");
            scanf(" %[^\n]s", palavra);

            int tamanho_palavra = strlen(palavra);

            for (int i = 0; i < tamanho_palavra; i++){
                if(palavra[i] != ' '){
                    nova_palavra[tamanho_nova_palavra++] = palavra[i];
                }

                else{
                    nova_palavra[tamanho_nova_palavra++] = '-';
                }
            }

            printf("\nPalavra com o h¡fen no lugar dos espa‡os: %s", nova_palavra);

            sleep(4);
        }

        void palindromo(){
            system("cls");

            char palavra[20];
            char palavra_ao_contrario[20];
            int tamanho_palavra_ao_contrario = 0;

            printf("Digite uma string de at‚ 20 caracteres abaixo: ");
            scanf(" %[^\n]s", palavra);

            int tamanho_palavra = strlen(palavra);
            int contador = 0;

            for (int i = tamanho_palavra-1; i >= 0; i--){
                palavra_ao_contrario[tamanho_palavra_ao_contrario++] = palavra[i];
            }
            
            palavra_ao_contrario[tamanho_palavra] = '\0';

            for (int i = 0; i < tamanho_palavra; i++){
                if(palavra[i] == palavra_ao_contrario[i]){
                    contador += 1;
                }
            }

            if(contador == tamanho_palavra){
                printf("A string %s ao contr rio ‚ %s. Ou seja, a string ‚ um pal¡ndromo:)", palavra, palavra_ao_contrario);
            }

            else{
                printf("A string %s ao contr rio ‚ %s. Ou seja, a string nÆo ‚ um pal¡ndromo:(", palavra, palavra_ao_contrario);
            }

            sleep(4);
        }

        int main2(){
            system("cls");

            int opcao_de_questao;

            printf("1-Q1\n"
                    "2-Q2\n"
                    "3-Q3\n"
                    "4-Q4\n"
                    "5-Q5\n"
                    "6-Q6\n"
                    "7-Q7\n"
                    "8-Q8\n"
                    "9-Q9\n"
                    "10-Q10\n"
                    "11-Q11\n"
                    "12-Q12\n"
                    "13-Q13\n"
                    "14-Q14\n"
                    "15-Q15\n"
                    "16-Q16\n"
                    "17-Q17\n"
                    "18-Q18\n"
                    "19-Q19\n"
                    "20-Q20\n"
                    "21-Q21\n"
                    "Digite o n£mero respectivo … questÆo desejada: ");
            scanf("%d", &opcao_de_questao);

            while((opcao_de_questao < 0) || (opcao_de_questao > 21)){
                system("cls");

                printf("1-Q1\n"
                    "2-Q2\n"
                    "3-Q3\n"
                    "4-Q4\n"
                    "5-Q5\n"
                    "6-Q6\n"
                    "7-Q7\n"
                    "8-Q8\n"
                    "9-Q9\n"
                    "10-Q10\n"
                    "11-Q11\n"
                    "12-Q12\n"
                    "13-Q13\n"
                    "14-Q14\n"
                    "15-Q15\n"
                    "16-Q16\n"
                    "17-Q17\n"
                    "18-Q18\n"
                    "19-Q19\n"
                    "20-Q20\n"
                    "21-Q21\n"
                    "Digite o n£mero respectivo … questÆo desejada: ");
                scanf("%d", &opcao_de_questao);
                
            }

            if(opcao_de_questao == 1){
                par_ou_impar();
            }

            else if(opcao_de_questao == 2){
                leia_tres_numeros();
            }

            else if(opcao_de_questao == 3){
                idade();
            }

            else if(opcao_de_questao == 4){
                positivo_negativo_neutro();
            }

            else if(opcao_de_questao == 5){
                aluno();
            }

            else if(opcao_de_questao == 6){
                um_a_cem();
            }

            else if(opcao_de_questao == 7){
                soma_de_um_a_seu_numero();
            }

            else if(opcao_de_questao == 8){
                tabuada();
            }

            else if(opcao_de_questao == 9){
                divisores();
            }
            
            else if(opcao_de_questao == 10){
                todos_os_positivos_somados();
            }

            else if(opcao_de_questao == 11){
                piramide_de_asteriscos();
            }

            else if(opcao_de_questao ==  12){
                dez_vetores();
            }

            else if(opcao_de_questao ==  13){
                cinco_numeros_array_ao_contrario();
            }

            else if(opcao_de_questao ==  14){
                soma_dois_array();
            }

            else if(opcao_de_questao ==  15){
                exibir_pares_do_array();
            }

            else if(opcao_de_questao == 16){
                positivos_negativos_e_neutro_no_aray();
            }

            else if(opcao_de_questao == 17){
                string_ao_contrario();
            }
            
            else if(opcao_de_questao == 18){
                quantidade_vogais();
            }

            else if(opcao_de_questao == 19){
                duas_strings_iguais();
            }

            else if(opcao_de_questao == 20){
                troca_espaco_por_hifen();
            }

            else if(opcao_de_questao == 21){
                palindromo();
            }

            else{
                system("cls");

                printf("Programa encerrado!");
                exit(0);
            }

            return 0;
        }

        main2();
    }
}