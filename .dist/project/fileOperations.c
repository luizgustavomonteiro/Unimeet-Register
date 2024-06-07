#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fileOperations.h"

void OpenFile()
{
    FILE *file = fopen("database.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("Arquivo aberto com sucesso\n");
    fclose(file);
}

void CreateFile()
{
    setlocale(LC_ALL, "pt_BR");

    FILE *file = fopen("database.csv", "w");
    if (file == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        return;
    }

    RegisterUser user;

    printf("Digite o ID do usuário:");
    scanf("%d", &user.id);
    getchar();

    printf("Digite o nome do usuário: ");
    fgets(user.nome, sizeof(user.nome), stdin);
    user.nome[strcspn(user.nome, "\n")] = '\0';

    printf("Digite o email do usuário: ");
    fgets(user.email, sizeof(user.email), stdin);
    user.email[strcspn(user.email, "\n")] = '\0';

    printf("Data de início do usuário: (DD MM AAAA) ");
    scanf("%i %i %i", &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano);
    getchar(); // Limpa o buffer de entrada

    printf("Digite o sexo do usuário (1 para masculino ou 0 para feminino): ");
    scanf("%i", &user.sexo);

    printf("Data de nascimento do usuário: (DD MM AAAA) ");
    scanf("%i %i %i", &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano);

    printf("Digite o atual semestre do usuário: ");
    scanf("%i", &user.atualSemestre);

    printf("Digite o ano de formação do usuário: ");
    scanf("%i", &user.anoFormacao);

    // Mostrar os valores na tela
    printf("\nValores inseridos:\n");
    printf("ID: %d\n", user.id);
    printf("Nome: %s\n", user.nome);
    printf("Email: %s\n", user.email);
    printf("Data de início: %d/%d/%d\n", user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano);
    printf("Sexo: %d\n", user.sexo);
    printf("Data de nascimento: %d/%d/%d\n", user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano);
    printf("Atual semestre: %d\n", user.atualSemestre);
    printf("Ano de formação: %d\n", user.anoFormacao);

    // Escreve os valores no arquivo no formato CSV
    fprintf(file, "ID,Nome,Email,DataInicio,Sexo,DataNascimento,AtualSemestre,AnoFormacao\n");
    fprintf(file, "%d,%s,%s,%d/%d/%d,%d,%d/%d/%d,%d,%d\n",
            user.id, user.nome, user.email,
            user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano,
            user.sexo,
            user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano,
            user.atualSemestre, user.anoFormacao);

    fclose(file);
    printf("Arquivo criado com sucesso\n");
}