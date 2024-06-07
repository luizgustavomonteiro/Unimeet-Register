#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#include "fileOperations.c"

#ifdef _WIN32
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() system("clear")
#endif

// Função de apenas leitura para a função de Menu principal.
void showMenu()
{

    // Declarando a variável de opções do switch e inicializando ela com o valor 0.
    int options = 0;
    // Declarando a variável para o input do dado que será lido nas opções do switch.
    char input[100];

    CLEAR_SCREEN();

    printf("++++++++++++++++++++++++++++++\n");
    printf("UNIMEET - CADASTRO DE USUÁRIO\n");

    printf("++++++++++++++++++++++++++++++\n");

    printf("1) Abrir base de dados.\n");
    printf("2) Criar base de dados.\n");
    printf("3) Deletar base de dados.\n");
    printf("4) Desenvolvedores.\n");
    printf("5) Sair.\n");

    // Utilizando a função fgets e determinando o tamanho dela com o tamanho do valor do input.
    do
    {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &options) != 1 || options < 1 || options > 5)
        {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (options < 1 || options > 5);

    switch (options)
    {
    case 1:
        OpenFile();

        break;

    case 2:
        CreateFile();
        //  função para criar o arquivo csv
        break;

    case 3:
        DeleteFile();
        break;

    case 4:
        Developers();
        /*função para acessar os desenvolvedores*/
        break;

    case 5:
        // ExitAplication();
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