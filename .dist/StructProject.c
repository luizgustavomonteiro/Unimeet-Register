#include <stdio.h>
#include <stdlib.h>

void switchMenu()
{

    system("cls");
    printf("++++++++++++++++++++++++++++++\n");
    printf("UNIMEET - CADASTRO DE USUÁRIO\n");

    printf("++++++++++++++++++++++++++++++\n");

    printf("1) Abrir um arquivo csv.\n");
    printf("2) Criar um arquivo csv.\n");
    printf("3) Colaboradores.\n");
    printf("4) Sair.\n");

    int menu = 0;
    scanf("%i", &menu);

    switch (menu)
    {
    case 1:
        printf("Testando resposta switch");
        break;

    case 2:
        printf("Testando resposta switch");
        // função para criar o arquivo csv
        break;

    case 3:
        printf("Testando resposta switch");
        /*função para acessar os desenvolvedores*/
        break;

    case 4:
        printf("Testando resposta switch");
        /*função para sair da aplicação*/
        break;

    default:
        switchMenu();
        /*retornar ao menu*/
        break;
    }
}

int main()
{

    switchMenu();

    return 0;
}
