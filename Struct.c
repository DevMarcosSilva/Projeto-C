#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_USUARIOS 1000
#define TAM_NOME 100
#define TAM_EMAIL 100
#define TAM_ENDERECO 200

typedef struct {
    int id;
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char sexo[TAM_NOME];
    char endereco[TAM_ENDERECO];
    double altura;
    int vacina;
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

int gerarId() {
    srand(time(NULL));
    return rand();
}

void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuários atingido!\n");
        return;
    }

    Usuario novoUsuario;
    novoUsuario.id = gerarId();

    printf("Digite o nome completo: ");
    fgets(novoUsuario.nome, TAM_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    do
        {
    printf("Digite o email: ");
    fgets(novoUsuario.email, TAM_EMAIL, stdin);
    novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';
    }while (strchr(novoUsuario.email, '@') == 0);

    do
        { 
    printf("Digite o sexo (Feminino, Masculino ou Indiferente): ");
    fgets(novoUsuario.sexo, TAM_NOME, stdin);
    novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';
    } while (strcmp(novoUsuario.sexo, "masculino") !=0 && strcmp(novoUsuario.sexo, "feminino")!=0&& strcmp(novoUsuario.sexo, "indiferente")!=0);

    printf("Digite o endereço: ");
    fgets(novoUsuario.endereco, TAM_ENDERECO, stdin);
    novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0';

    do
           {
    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario.altura);
    } while (novoUsuario.altura<1 || novoUsuario.altura >2);

    do
        {
    printf("Recebeu a vacina? ( sim ou  não): ");
    scanf("%d", &novoUsuario.vacina);
    } while (strcmp(novoUsuario.vacina, "Sim") ==0 && strcmp(novoUsuario.vacina, "sim")==0 && strcmp(novoUsuario.vacina, "Nao")==0 && strcmp(novoUsuario.vacina, "nao")==0);

    getchar(); // Limpar o buffer do teclado

    usuarios[totalUsuarios++] = novoUsuario;
    printf("Usuário cadastrado com sucesso!\n");
}

void editarUsuario() {
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuário não encontrado!\n");
        return;
    }

    Usuario *usuario = &usuarios[indice];

    printf("Digite o novo nome completo: ");
    fgets(usuario->nome, TAM_NOME, stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

    printf("Digite o novo email: ");
    fgets(usuario->email, TAM_EMAIL, stdin);
    usuario->email[strcspn(usuario->email, "\n")] = '\0';

    printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
    fgets(usuario->sexo, TAM_NOME, stdin);
    usuario->sexo[strcspn(usuario->sexo, "\n")] = '\0';

    printf("Digite o novo endereço: ");
    fgets(usuario->endereco, TAM_ENDERECO, stdin);
    usuario->endereco[strcspn(usuario->endereco, "\n")] = '\0';

    printf("Digite a nova altura (entre 1 e 2 metros): ");
    scanf("%lf", &usuario->altura);

    printf("Recebeu a vacina? (1 para sim, 0 para não): ");
    scanf("%d", &usuario->vacina);

    getchar(); 

    printf("Usuário editado com sucesso!\n");
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuário não encontrado!\n");
        return;
    }

    for (int i = indice; i < totalUsuarios - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }

    totalUsuarios--;
    printf("Usuário excluído com sucesso!\n");
}

void buscarUsuarioPorEmail() {
    char email[TAM_EMAIL];
    printf("Digite o email do usuário a ser buscado: ");
    fgets(email, TAM_EMAIL, stdin);
    email[strcspn(email, "\n")] = '\0';

    bool encontrado = false;
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            Usuario usuario = usuarios[i];
            printf("ID: %d\n", usuario.id);
            printf("Nome: %s\n", usuario.nome);
            printf("Email: %s\n", usuario.email);
            printf("Sexo: %s\n", usuario.sexo);
            printf("Endereço: %s\n", usuario.endereco);
            printf("Altura: %.2lf\n", usuario.altura);
            printf("Vacina: %s\n", usuario.vacina ? "Sim" : "Não");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado!\n");
    }
}

void imprimirUsuariosCadastrados() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        Usuario usuario = usuarios[i];
        printf("ID: %d\n", usuario.id);
        printf("Nome: %s\n", usuario.nome);
        printf("Email: %s\n", usuario.email);
        printf("Sexo: %s\n", usuario.sexo);
        printf("Endereço: %s\n", usuario.endereco);
        printf("Altura: %.2lf\n", usuario.altura);
        printf("Vacina: %s\n", usuario.vacina ? "Sim" : "Não");
        printf("-------------------------------\n");
    }
}

void fazerBackup() {
    FILE *arquivo = fopen("backup.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de backup.\n");
        return;
    }

    fprintf(arquivo, "%d\n", totalUsuarios);
    for (int i = 0; i < totalUsuarios; i++) {
        Usuario usuario = usuarios[i];
        fprintf(arquivo, "%d\n", usuario.id);
        fprintf(arquivo, "%s\n", usuario.nome);
        fprintf(arquivo, "%s\n", usuario.email);
        fprintf(arquivo, "%s\n", usuario.sexo);
        fprintf(arquivo, "%s\n", usuario.endereco);
        fprintf(arquivo, "%.2lf\n", usuario.altura);
        fprintf(arquivo, "%d\n", usuario.vacina);
    }

    fclose(arquivo);
    printf("Backup realizado com sucesso!\n");
}

void fazerRestauracao() {
    FILE *arquivo = fopen("backup.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de backup não encontrado.\n");
        return;
    }

    int totalUsuariosBackup;
    fscanf(arquivo, "%d\n", &totalUsuariosBackup);

    if (totalUsuariosBackup > MAX_USUARIOS) {
        printf("Limite de usuários excedido no backup!\n");
        fclose(arquivo);
        return;
    }

    totalUsuarios = 0;
    for (int i = 0; i < totalUsuariosBackup; i++) {
        Usuario usuario;
        fscanf(arquivo, "%d\n", &usuario.id);
        fgets(usuario.nome, TAM_NOME, arquivo);
        usuario.nome[strcspn(usuario.nome, "\n")] = '\0';
        fgets(usuario.email, TAM_EMAIL, arquivo);
        usuario.email[strcspn(usuario.email, "\n")] = '\0';
        fgets(usuario.sexo, TAM_NOME, arquivo);
        usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';
        fgets(usuario.endereco, TAM_ENDERECO, arquivo);
        usuario.endereco[strcspn(usuario.endereco, "\n")] = '\0';
        fscanf(arquivo, "%lf\n", &usuario.altura);
        fscanf(arquivo, "%d\n", &usuario.vacina);
        usuarios[totalUsuarios++] = usuario;
    }

    fclose(arquivo);
    printf("Restauração realizada com sucesso!\n");
}

int main() {
    char opcao;
    do {
        printf("----- MENU -----\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Buscar usuário por email\n");
        printf("5. Imprimir todos os usuários cadastrados\n");
        printf("6. Fazer backup dos usuários cadastrados\n");
        printf("7. Fazer restauração dos dados\n");
        printf("0. Sair\n");
        printf("Digite a opção desejada: ");
        scanf(" %c", &opcao);

        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case '1':
                cadastrarUsuario();
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
                imprimirUsuariosCadastrados();
                break;
            case '6':
                fazerBackup();
                break;
            case '7':
                fazerRestauracao();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");
    } while (opcao != '0');

    return 0;
}
