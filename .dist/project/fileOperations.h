#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

typedef struct FormatData
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct RegisterUser
{
    int id;
    char nome[200]; // N é o número de caracteres definidos para registro da informação
    char email[200];
    Data dataInicio;
    int sexo;            // 0 para masculino ou 1 para feminino
    Data dataNascimento; // formato YYYYMMDD
    int atualSemestre;
    int anoFormacao; // formato YYYYMMDD
} RegisterUser;

void OpenFile();
void CreateFile();
void DeleteFile();
void Developers();
void ExitAplication();
void readUsers();
void createUser();
void updateUser();
void deleteUser();
void showMenuUser();
void promptChoice();
void promptChoiceUser();
void verifIDUnique(RegisterUser *user);
int isIdUnique(int id);

#endif