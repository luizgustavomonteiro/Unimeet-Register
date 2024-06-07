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

    RegisterUser user;

    setlocale(LC_ALL, "");
    // Ignorar a primeira linha que contém os cabeçalhos
    char headerLine[500];
    fgets(headerLine, sizeof(headerLine), file);

    printf("Registros de usuários:\n");
    printf("ID | Nome | Email | Data de Início | Sexo | Data de Nascimento | Atual Semestre | Ano de Formação\n");
    printf("-----------------------------------------------------------------------------------------------\n");

    // Lê cada registro do arquivo CSV e os exibe na tela
    while (fscanf(file, "%d,%199[^,],%199[^,],%d/%d/%d,%d,%d/%d/%d,%d,%d\n",
                  &user.id, user.nome, user.email,
                  &user.dataInicio.dia, &user.dataInicio.mes, &user.dataInicio.ano,
                  &user.sexo,
                  &user.dataNascimento.dia, &user.dataNascimento.mes, &user.dataNascimento.ano,
                  &user.atualSemestre, &user.anoFormacao) == 12)
    {
        printf("%d | %s | %s | %02d/%02d/%04d | %d | %02d/%02d/%04d | %d | %d\n",
               user.id, user.nome, user.email,
               user.dataInicio.dia, user.dataInicio.mes, user.dataInicio.ano,
               user.sexo,
               user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano,
               user.atualSemestre, user.anoFormacao);
    }

    fclose(file);
    printf("Leitura dos registros concluída.\n");
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
        scanf(" %c", &continuar);
        getchar(); // Limpa o buffer de entrada

    } while (continuar == 's' || continuar == 'S');

    fclose(file);
    printf("Arquivo criado com sucesso\n");
}