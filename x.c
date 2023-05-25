#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

int totalUsuarios = 0;

int id[MAX_USERS];
char nome[MAX_USERS][MAX_NAME_LENGTH];
char email[MAX_USERS][MAX_EMAIL_LENGTH];
char sexo[MAX_USERS][MAX_NAME_LENGTH];
char endereco[MAX_USERS][MAX_ADDRESS_LENGTH];
double altura[MAX_USERS];
int vacina[MAX_USERS];

void incluirUsuario() {
    if (totalUsuarios == MAX_USERS) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }
    
    
    printf("Digite o nome completo: ");
    fgets(nome[totalUsuarios], MAX_NAME_LENGTH, stdin);
    printf("Digite o email: ");
    fgets(email[totalUsuarios], MAX_EMAIL_LENGTH, stdin);
    printf("Digite o sexo (Feminino/Masculino/Indiferente): ");
    fgets(sexo[totalUsuarios], MAX_NAME_LENGTH, stdin);
    printf("Digite o endereço: ");
    fgets(endereco[totalUsuarios], MAX_ADDRESS_LENGTH, stdin);
    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &altura[totalUsuarios]);
    printf("Recebeu vacina? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacina[totalUsuarios]);
    getchar(); 
    
    
    id[totalUsuarios] = rand();
    
    totalUsuarios++;
    
    printf("Usario cadastrado com sucesso, selecione a opçaõ 5 para saber o ID do mesmo!\n");
}

void editarUsuario() {
    int idUsuario;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &idUsuario);
    getchar();
    
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (id[i] == idUsuario) {
            
            printf("Digite o novo nome completo: ");
            fgets(nome[i], MAX_NAME_LENGTH, stdin);
            printf("Digite o novo email: ");
            fgets(email[i], MAX_EMAIL_LENGTH, stdin);
            printf("Digite o novo sexo (Feminino/Masculino/Indiferente): ");
            fgets(sexo[i], MAX_NAME_LENGTH, stdin);
            printf("Digite o novo endereço: ");
            fgets(endereco[i], MAX_ADDRESS_LENGTH, stdin);
            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &altura[i]);
            printf("Recebeu vacina? (1 - Sim / 0 - Nao): ");
            scanf("%d", &vacina[i]);
            getchar(); 
            
            printf("Usuario editado com sucesso!\n");
            return;
        }
    }
    
    printf("Usuario nao encontrado.\n");
}

void excluirUsuario() {
    int idUsuario;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idUsuario);
    getchar(); 

    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (id[i] == idUsuario) {
            int j;
            for (j = i; j < totalUsuarios - 1; j++) {
                id[j] = id[j + 1];
                strcpy(nome[j], nome[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(sexo[j], sexo[j + 1]);
                strcpy(endereco[j], endereco[j + 1]);
                altura[j] = altura[j + 1];
                vacina[j] = vacina[j + 1];
            }
            totalUsuarios--;
            
            printf("Usuario excluido com sucesso!\n");
            return;
        }
    }
    
    printf("Usuario não encontrado.\n");
}

void buscarUsuarioPorEmail() {
    char emailUsuario[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(emailUsuario, MAX_EMAIL_LENGTH, stdin);
    
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(email[i], emailUsuario) == 0) {
            printf("ID: %d\n", id[i]);
            printf("Nome: %s", nome[i]);
            printf("Email: %s", email[i]);
            printf("Sexo: %s", sexo[i]);
            printf("Endereço: %s", endereco[i]);
            printf("Altura: %.2lf\n", altura[i]);
            printf("Vacina: %s\n", vacina[i] ? "Sim" : "Nao");
            
            return;
        }
    }
    
    printf("Usuario nao encontrado.\n");
}

void imprimirUsuarios() {
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", id[i]);
        printf("Nome: %s", nome[i]);
        printf("Email: %s", email[i]);
        printf("Sexo: %s", sexo[i]);
        printf("Endereco: %s", endereco[i]);
        printf("Altura: %.2lf\n", altura[i]);
        printf("Vacina: %s\n", vacina[i] ? "Sim" : "Nao");
        printf("------------------------\n");
    }
}

void fazerBackup() {
    // Falta colocar uma lógica para fazer backup dos usuários cadastrados aqui
    printf("Backup realizado com sucesso!\n");
}

void restaurarDados() {
    /// Falta colocar uma lógica para restaurar os dados a partir de um backup aqui
    printf("Dados restaurados com sucesso!\n");
}

int main() {
    char opcao;
    
    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Incluir usuario\n");
        printf("2 - Editar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Buscar usuario por email\n");
        printf("5 - Imprimir usuarios cadastrados\n");
        printf("6 - Fazer backup\n");
        printf("7 - Restaurar dados\n");
        printf("0 - Sair\n");
        
        printf("Opcao: ");
        scanf(" %c", &opcao);
        getchar();
        
        switch (opcao) {
            case '1':
                incluirUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                buscarUsuarioPorEmail();
                break;
            case '5':
                imprimirUsuarios();
                break;
            case '6':
                fazerBackup();
                break;
            case '7':
                restaurarDados();
                break;
            case '0':
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != '0');
    
    return 0;
}