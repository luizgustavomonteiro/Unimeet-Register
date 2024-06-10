#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fileOperations.h"

#ifdef _WIN32
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() system("clear")
#endif

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
            printf("Opção inválida, tente novamente.\n");
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
        ExitAplication();
        /*função para sair da aplicação*/
        break;
    }
}

void OpenFile()
{

    FILE *file = fopen("database.csv", "r+"); // 'r+' permite leitura e escrita no arquivo.
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo. Voltando ao menu principal...\n");
        showMenu();
        return;
    }

    printf("Base de dados aberta com sucesso!\n");
    fclose(file); // Fechar o arquivo após verificar.
    CLEAR_SCREEN();
    showMenuUser(); // Chamar o menu CRUD
}

void CreateFile()
{
    FILE *file = fopen("database.csv", "w");
    if (file == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        return;
    }

    fprintf(file, "ID,Nome,Email,DataInicio,Sexo,DataNascimento,AtualSemestre,AnoFormacao\n");

    char continuar = 'n';

    do
    {
        RegisterUser user;

        printf("Digite o ID do usuário: ");
        scanf("%d", &user.id);
        getchar(); // Limpa o buffer de entrada

        printf("Digite o nome do usuário: ");
        fgets(user.nome, sizeof(user.nome), stdin);
        user.nome[strcspn(user.nome, "\n")] = '\0'; // Remove o '\n' no final

        printf("Digite o email do usuário: ");
        fgets(user.email, sizeof(user.email), stdin);
        user.email[strcspn(user.email, "\n")] = '\0'; // Remove o '\n' no final

        printf("Data de início do usuário: (DD MM AAAA) ");
        scanf("%i %i %i", &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano);
        getchar(); // Limpa o buffer de entrada

        printf("Digite o sexo do usuário (1 para masculino ou 0 para feminino): ");
        scanf("%i", &user.sexo);

        printf("Data de nascimento do usuário: (DD MM AAAA) ");
        scanf("%i %i %i", &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano);
        getchar(); // Limpa o buffer de entrada

        printf("Digite o atual semestre do usuário: ");
        scanf("%i", &user.atualSemestre);
        getchar(); // Limpa o buffer de entrada

        printf("Digite o ano de formação do usuário: ");
        scanf("%i", &user.anoFormacao);
        getchar(); // Limpa o buffer de entrada

        // Escreve os valores no arquivo no formato CSV
        fprintf(file, "%d,%s,%s,%02d/%02d/%04d,%d,%02d/%02d/%04d,%d,%d\n",
                user.id, user.nome, user.email,
                user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano,
                user.sexo,
                user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano,
                user.atualSemestre, user.anoFormacao);

        printf("Deseja cadastrar mais um usuário? (s/n): ");
        scanf("%c", &continuar);
        getchar(); // Limpa o buffer de entrada
        CLEAR_SCREEN();

    } while (continuar == 's' || continuar == 'S');

    fclose(file);
    printf("Arquivo criado com sucesso\n");
    showMenu();
    CLEAR_SCREEN();
}

void DeleteFile()
{
    const char *filename = "database.csv";

    if (remove(filename) == 0)
    {
        printf("Base de dados deletada com sucesso!\n");
        promptChoice(); // Chama a função para perguntar ao usuário o que ele deseja fazer em seguida
    }
    else
    {
        printf("Erro ao deletar o arquivo!\n");
        promptChoice(); // Chama a função mesmo em caso de erro
    }
}

void Developers()
{
    printf("Universidade São Francisco USF - Campus Itatiba\n");
    printf("-----------------------------------------------\n");
    printf("Curso: Programação Estruturada\n");
    printf("-----------------------------------------------\n");
    printf("Professor Mentor: Felipe Cavalaro\n");
    printf("-----------------------------------------------\n");
    printf("Alunos Desenvolvedores:\n");
    printf("Bruno Romero Morales\n");
    printf("Nathalia Lima Veiga\n");
    printf("Luiz Gustavo Monteiro dos Reis\n");

    printf("\n");
    promptChoice();
}

void ExitAplication()
{
    printf("Encerrando Aplicação...");
    exit(0);
}

void showMenuUser()

{
    int choice;
    char input[100];

    printf("\n **************** Menu ****************\n");
    printf("1) Listar todos os usuários\n");
    printf("2) Adicionar um novo usuário\n");
    printf("3) Editar um usuário existente\n");
    printf("4) Deletar um usuário\n");
    printf("5) Voltar ao menu principal\n");
    printf("******************************************\n");

    do
    {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 5)
        {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice < 1 || choice > 5);

    switch (choice)
    {
    case 1:
        readUsers();
        break;
    case 2:
        createUser();
        break;
    case 3:
        updateUser();
        break;
    case 4:
        deleteUser();
        break;
    case 5:
        CLEAR_SCREEN();
        showMenu();
        return;
    }
}

void readUsers()
{
    FILE *file = fopen("database.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char line[500];
    printf("ID, Nome, Email, Data de Início, Sexo, Data de Nascimento, Atual Semestre, Ano de Formação\n");
    printf("------------------------------------------------------------------------------------------\n");

    fgets(line, sizeof(line), file); // Ignorar cabeçalho
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
    promptChoiceUser();
}

void createUser()
{
    FILE *file = fopen("database.csv", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    RegisterUser user;

    printf("Digite o ID do usuário: ");
    scanf("%d", &user.id);
    getchar();

    printf("Digite o nome do usuário: ");
    fgets(user.nome, sizeof(user.nome), stdin);
    user.nome[strcspn(user.nome, "\n")] = '\0';

    printf("Digite o email do usuário: ");
    fgets(user.email, sizeof(user.email), stdin);
    user.email[strcspn(user.email, "\n")] = '\0';

    printf("Data de início do usuário (DD MM AAAA): ");
    scanf("%i %i %i", &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano);
    getchar();

    printf("Digite o sexo do usuário (1 para masculino ou 0 para feminino): ");
    scanf("%i", &user.sexo);

    printf("Data de nascimento do usuário (DD MM AAAA): ");
    scanf("%i %i %i", &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano);
    getchar();

    printf("Digite o atual semestre do usuário: ");
    scanf("%i", &user.atualSemestre);
    getchar();

    printf("Digite o ano de formação do usuário: ");
    scanf("%i", &user.anoFormacao);
    getchar();

    fprintf(file, "%d,%s,%s,%02d/%02d/%04d,%d,%02d/%02d/%04d,%d,%d\n",
            user.id, user.nome, user.email,
            user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano,
            user.sexo,
            user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano,
            user.atualSemestre, user.anoFormacao);

    fclose(file);
    printf("\n");
    printf("Usuário adicionado com sucesso!\n");

    promptChoiceUser();
}

void updateUser()
{
    FILE *file = fopen("database.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL)
    {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return;
    }

    int id, found = 0;
    RegisterUser user;

    printf("Digite o ID do usuário que deseja atualizar: ");
    scanf("%d", &id);
    getchar();

    fprintf(tempFile, "ID,Nome,Email,DataInicio,Sexo,DataNascimento,AtualSemestre,AnoFormacao\n");

    char line[500];
    fgets(line, sizeof(line), file); // Lê o cabeçalho e escreve no arquivo temporário
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%199[^,],%199[^,],%d/%d/%d,%d,%d/%d/%d,%d,%d",
               &user.id, user.nome, user.email,
               &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano,
               &user.sexo,
               &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano,
               &user.atualSemestre, &user.anoFormacao);

        if (user.id == id)
        {
            printf("Usuário encontrado! Insira os novos dados:\n");

            printf("Digite o nome do usuário: ");
            fgets(user.nome, sizeof(user.nome), stdin);
            user.nome[strcspn(user.nome, "\n")] = '\0';

            printf("Digite o email do usuário: ");
            fgets(user.email, sizeof(user.email), stdin);
            user.email[strcspn(user.email, "\n")] = '\0';

            printf("Data de início do usuário (DD MM AAAA): ");
            scanf("%i %i %i", &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano);
            getchar();

            printf("Digite o sexo do usuário (1 para masculino ou 0 para feminino): ");
            scanf("%i", &user.sexo);
            getchar();

            printf("Data de nascimento do usuário (DD MM AAAA): ");
            scanf("%i %i %i", &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano);
            getchar();

            printf("Digite o atual semestre do usuário: ");
            scanf("%i", &user.atualSemestre);
            getchar();

            printf("Digite o ano de formação do usuário: ");
            scanf("%i", &user.anoFormacao);
            getchar();

            found = 1;
        }

        fprintf(tempFile, "%d,%s,%s,%02d/%02d/%04d,%d,%02d/%02d/%04d,%d,%d\n",
                user.id, user.nome, user.email,
                user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano,
                user.sexo,
                user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano,
                user.atualSemestre, user.anoFormacao);
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("database.csv");
        rename("temp.csv", "database.csv");
        printf("Usuário atualizado com sucesso!\n");
        printf("\n");

        printf("Deseja atualizar mais algum usuário?\n");
        char choice;
        scanf(" %c", &choice);

        // Limpa o buffer de entrada
        while (getchar() != '\n')
            ;

        if (choice == 's' || choice == 'S')
        {
            CLEAR_SCREEN();
            updateUser();
        }
        else
        {
            showMenuUser();
        }
    }
    else
    {
        remove("temp.csv");
        printf("Usuário com ID %d não encontrado.\n", id);
        CLEAR_SCREEN();
        updateUser();
    }
}

void deleteUser()
{
    FILE *file = fopen("database.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL)
    {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return;
    }

    int id, found = 0;
    RegisterUser user;

    printf("Digite o ID do usuário que deseja deletar: ");
    scanf("%d", &id);
    getchar();

    fprintf(tempFile, "ID,Nome,Email,DataInicio,Sexo,DataNascimento,AtualSemestre,AnoFormacao\n");

    char line[500];
    fgets(line, sizeof(line), file); // Lê o cabeçalho e escreve no arquivo temporário
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%199[^,],%199[^,],%d/%d/%d,%d,%d/%d/%d,%d,%d",
               &user.id, user.nome, user.email,
               &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano,
               &user.sexo,
               &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano,
               &user.atualSemestre, &user.anoFormacao);

        if (user.id != id)
        {
            fprintf(tempFile, "%d,%s,%s,%02d/%02d/%04d,%d,%02d/%02d/%04d,%d,%d\n",
                    user.id, user.nome, user.email,
                    user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano,
                    user.sexo,
                    user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano,
                    user.atualSemestre, user.anoFormacao);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found)
    {
        remove("database.csv");
        rename("temp.csv", "database.csv");
        printf("Usuário deletado com sucesso.\n");
        promptChoiceUser();
    }
    else
    {
        remove("temp.csv");
        printf("Usuário com ID %d não encontrado.\n", id);
        promptChoiceUser();
    }
}

void promptChoice()
{
    char choice;
    printf("Deseja voltar ao menu principal (s/n)? ");
    scanf(" %c", &choice);

    // Limpa o buffer de entrada
    while (getchar() != '\n')
        ;

    if (choice == 's' || choice == 'S')
    {
        CLEAR_SCREEN(); // Limpa a tela antes de mostrar o menu principal novamente
        showMenu();     // Volta ao menu principal
    }
    else
    {
        exit(0); // Sai da aplicação
    }
}

void promptChoiceUser()
{
    char choice;
    printf("Deseja voltar ao menu (s/n)? ");
    scanf(" %c", &choice);

    while (getchar() != '\n')
        ;

    if (choice == 's' || choice == 'S')
    {
        CLEAR_SCREEN();
        showMenuUser();
    }
    else
    {
        showMenu();
    }
}
