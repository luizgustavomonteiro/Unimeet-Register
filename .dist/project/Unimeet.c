#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Inclusão da biblioteca ctype para verificar o caractere de entrada.
-> Para poder utilizar a função 'isdigit' para verificar se entrada
foi um número do tipo inteiro na variável options através de uma estrutura
condicional 'if'.
*/
#include "OpenFile.c"
#include "NewFile.c"
#include "DeleteFile.c"
#include "Developers.c"
#include "ExitAplication.c"

// Função de apenas leitura para a função de Menu principal.
void showMenu()
{

    // Declarando a variável de opções do switch e inicializando ela com o valor 0.
    int options = 0;
    // Declarando a variável para o input do dado que será lido nas opções do switch.
    char input[100];

    // Limpando a tela com o cls, necesário fazer uma verificação de sistema operacional.
    system("cls");

    printf("++++++++++++++++++++++++++++++\n");
    printf("UNIMEET - CADASTRO DE USUÁRIO\n");

    printf("++++++++++++++++++++++++++++++\n");

    printf("1) Abrir base de dados.\n");
    printf("2) Criar base de dados.\n");
    printf("3) Deletar base de dados.\n");
    printf("4) Desenvolvedores.\n");
    printf("5) Sair.\n");

    // Utilizando a função fgets e determinando o tamanho dela com o tamanho do valor do input.
    fgets(input, sizeof(input), stdin);

    /*Verificação da chamada 'sscanf' com o input do valor,
    '!=1' quando o dado passado não for 1 valor, se a chamada
    'sscanf' conseguir retornar um valor inteiro ela retornará 1,
    indicando que a verificação foi bem sucedida.
    */
    if (sscanf(input, "%d", &options) != 1)
    {
        showMenu();
        return;
    }

    switch (options)
    {
    case 1:
        OpenFile();

        break;

    case 2:
        NewFile();
        // função para criar o arquivo csv
        break;

    case 3:
        DeleteFile();
        break;

    case 4:
        Developers();
        /*função para acessar os desenvolvedores*/
        break;

    case 5:
        ExitAplication();
        /*função para sair da aplicação*/
        break;

    default:
        showMenu();
        /*retornar ao menu*/
        break;
    }
}

int main()
{

    showMenu();

    return 0;
}
