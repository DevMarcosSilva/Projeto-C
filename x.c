#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 25

int numUsers = 0;
int userIds[MAX_USERS];
char userNames[MAX_USERS][MAX_NAME_LENGTH];
char userEmails[MAX_USERS][MAX_EMAIL_LENGTH];

void incluirUsuario() {
    if (numUsers == MAX_USERS) {
        printf("Limite de usuários atingido.\n");
        return;
    }

    int newUserIndex = numUsers;

    printf("ID: ");
    scanf("%d", &userIds[newUserIndex]);

    printf("Nome: ");
    scanf("%s", userNames[newUserIndex]);

    printf("Email: ");
    scanf("%s", userEmails[newUserIndex]);

    numUsers++;

    printf("Usuário adicionado com sucesso.\n");
}

void editarUsuario() {
    int userId;
    printf("ID do usuário a ser editado: ");
    scanf("%d", &userId);

    int i;
    for (i = 0; i < numUsers; i++) {
        if (userIds[i] == userId) {
            printf("Novo nome: ");
            scanf("%s", userNames[i]);

            printf("Novo email: ");
            scanf("%s", userEmails[i]);

            printf("Usuário editado com sucesso.\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void excluirUsuario() {
    int userId;
    printf("ID do usuário a ser excluído: ");
    scanf("%d", &userId);

    int i;
    for (i = 0; i < numUsers; i++) {
        if (userIds[i] == userId) {
            int j;
            for (j = i; j < numUsers - 1; j++) {
                userIds[j] = userIds[j + 1];
                strcpy(userNames[j], userNames[j + 1]);
                strcpy(userEmails[j], userEmails[j + 1]);
            }

            numUsers--;

            printf("Usuário excluído com sucesso.\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void buscarUsuario() {
    int opcao;
    printf("Buscar usuário por:\n");
    printf("1. Email\n");
    printf("2. ID\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        char email[MAX_EMAIL_LENGTH];
        printf("Email: ");
        scanf("%s", email);

        int i;
        for (i = 0; i < numUsers; i++) {
            if (strcmp(userEmails[i], email) == 0) {
                printf("Usuário encontrado:\n");
                printf("ID: %d\n", userIds[i]);
                printf("Nome: %s\n", userNames[i]);
                printf("Email: %s\n", userEmails[i]);
                return;
            }
        }
    } else if (opcao == 2) {
        int userId;
        printf("ID: ");
        scanf("%d", &userId);

        int i;
        for (i = 0; i < numUsers; i++) {
            if (userIds[i] == userId) {
                printf("Usuário encontrado:\n");
                printf("ID: %d\n", userIds[i]);
                printf("Nome: %s\n", userNames[i]);
                printf("Email: %s\n", userEmails[i]);
                return;
            }
        }
    }

    printf("Usuário não encontrado.\n");
}

void exibirUsuarios() {
    if (numUsers == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    printf("Lista de usuários:\n");
    int i;
    for (i = 0; i < numUsers; i++) {
        printf("ID: %d\n", userIds[i]);
        printf("Nome: %s\n", userNames[i]);
        printf("Email: %s\n", userEmails[i]);
        printf("----------------------\n");
    }
}

void realizarBackup() {
    FILE *file = fopen("backup.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de backup.\n");
        return;
    }

    fwrite(&numUsers, sizeof(int), 1, file);
    fwrite(userIds, sizeof(int), numUsers, file);
    fwrite(userNames, sizeof(char), numUsers * MAX_NAME_LENGTH, file);
    fwrite(userEmails, sizeof(char), numUsers * MAX_EMAIL_LENGTH, file);

    fclose(file);

    printf("Backup realizado com sucesso.\n");
}

void realizarRestauracao() {
    FILE *file = fopen("backup.txt", "r");
    if (file == NULL) {
        printf("Arquivo de backup não encontrado.\n");
        return;
    }

    fread(&numUsers, sizeof(int), 1, file);
    fread(userIds, sizeof(int), numUsers, file);
    fread(userNames, sizeof(char), numUsers * MAX_NAME_LENGTH, file);
    fread(userEmails, sizeof(char), numUsers * MAX_EMAIL_LENGTH, file);

    fclose(file);

    printf("Restauração realizada com sucesso.\n");
}

int main() {
    int opcao;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Incluir usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Buscar usuário\n");
        printf("5. Exibir todos os usuários\n");
        printf("6. Realizar backup dos usuários\n");
        printf("7. Realizar restauração dos dados\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirUsuario();
                break;
            case 2:
                editarUsuario();
                break;
            case 3:
                excluirUsuario();
                break;
            case 4:
                buscarUsuario();
                break;
            case 5:
                exibirUsuarios();
                break;
            case 6:
                realizarBackup();
                break;
            case 7:
                realizarRestauracao();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}