#include <stdio.h>
#include <stdlib.h>
#include "OpenFile.c"
#include "NewFile.c"
#include "Developers.c"
#include "ExitAplication.c"

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
        OpenFile();
        break;

    case 2:
        NewFile();
        // função para criar o arquivo csv
        break;

    case 3:
        Developers();
        /*função para acessar os desenvolvedores*/
        break;

    case 4:
        ExitAplication();
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
