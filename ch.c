#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>

char email[1000][20], nome[100][50], sexo[100][11], vacinacao[1000][11], endereco[1000][50];
float altura[1000];
int id[1000], escolhamenu[1000], qtdausuarios;

void coletadedados() {
    int i, idd;

    printf("Quantos usuários deseja incluir? (Máximo 1000)");
    scanf("%d", &qtdausuarios);

    for (i = 0; i < qtdausuarios; i++) {
        fflush(stdin);
        printf("Informe o nome completo do usuário %d: ", i + 1);
        fgets(nome[i], 50, stdin);
        fflush(stdin);

        do {
            printf("Agora informe o email do usuário %d: ", i + 1);
            fgets(email[i], 20, stdin);
            fflush(stdin);
        } while (strchr(email[i], '@') == 0);

        printf("Agora informe o Endereço do usuário %d: ", i + 1);
        fgets(endereco[i], 50, stdin);
        fflush(stdin);

        do {
            printf("Informe a altura do usuário %d: ", i + 1);
            scanf("%f", &altura[i]);
        } while (altura[i] < 1 || altura[i] > 2);

        do {
            fflush(stdin);
            printf("Informe o sexo do usuário %d (Feminino, Masculino ou Indiferente): ", i + 1);
            scanf("%s", sexo[i]);

        } while (strcmp(sexo[i], "masculino") != 0 && strcmp(sexo[i], "feminino") != 0 && strcmp(sexo[i], "indiferente") != 0);

        do {
            printf("O usuário %d foi vacinado? (1-Sim ou 2-Não): ", i + 1);
            scanf("%s", vacinacao[i]);
            fflush(stdin);

        } while (strcmp(vacinacao[i], "Sim") != 0 && strcmp(vacinacao[i], "sim") != 0 && strcmp(vacinacao[i], "Não") != 0 && strcmp(vacinacao[i], "não") != 0);

        srand(time(NULL));
        idd = 1000 + rand() % 5000;
        id[i] = idd;
        printf("O ID do usuário %d é: %d\n\n", i + 1, id[i]);
    }

    printf("Para retornar ao menu inicial, digite 1: ");
    scanf("%d", &escolhamenu[i]);
    switch (escolhamenu[i]) {
        case 1:
            main();
            break;
    }
}

void buscarusuario() {
    int i, busca, iddd;
    char emailp[50];

    do {
        printf("Digite 1 para buscar pelo ID, ou qualquer valor para buscar por e-mail, ou 3 para sair: ");
        scanf("%d", &busca);

        switch (busca) {
            case 1:
                printf("Digite o ID: ");
                scanf("%d", &iddd);

                for (i = 0; i < qtdausuarios; i++) {
                    if (iddd == id[i]) {
                        printf("\nDados do usuário:\n");
                        printf("ID: %d\n", id[i]);
                        printf("Nome: %s", nome[i]);
                        printf("Email: %s", email[i]);
                        printf("Endereço: %s", endereco[i]);
                        printf("Altura: %.2f\n", altura[i]);
                        printf("Sexo: %s\n", sexo[i]);
                        printf("Vacinado: %s\n\n", vacinacao[i]);
                        break;
                    }
                }

                if (i == qtdausuarios) {
                    printf("\nUsuário não encontrado.\n\n");
                }
                break;

            default:
                printf("Digite o email: ");
                scanf("%s", emailp);

                for (i = 0; i < qtdausuarios; i++) {
                    if (strcmp(emailp, email[i]) == 0) {
                        printf("\nDados do usuário:\n");
                        printf("ID: %d\n", id[i]);
                        printf("Nome: %s", nome[i]);
                        printf("Email: %s", email[i]);
                        printf("Endereço: %s", endereco[i]);
                        printf("Altura: %.2f\n", altura[i]);
                        printf("Sexo: %s\n", sexo[i]);
                        printf("Vacinado: %s\n\n", vacinacao[i]);
                        break;
                    }
                }

                if (i == qtdausuarios) {
                    printf("\nUsuário não encontrado.\n\n");
                }
                break;
        }
    } while (busca == 1 || busca == 2);

    printf("Para retornar ao menu inicial, digite 1: ");
    scanf("%d", &escolhamenu[i]);
    switch (escolhamenu[i]) {
        case 1:
            main();
            break;
    }
}

void editarusuario() {
    int i, iddd, opcao;

    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &iddd);

    for (i = 0; i < qtdausuarios; i++) {
        if (iddd == id[i]) {
            printf("\nDados atuais do usuário:\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s", nome[i]);
            printf("Email: %s", email[i]);
            printf("Endereço: %s", endereco[i]);
            printf("Altura: %.2f\n", altura[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Vacinado: %s\n\n", vacinacao[i]);

            do {
                printf("Digite a opção que deseja editar:\n");
                printf("1 - Nome\n");
                printf("2 - Email\n");
                printf("3 - Endereço\n");
                printf("4 - Altura\n");
                printf("5 - Sexo\n");
                printf("6 - Vacinação\n");
                printf("7 - Sair\n");
                printf("Opção: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Digite o novo nome: ");
                        fflush(stdin);
                        fgets(nome[i], 50, stdin);
                        printf("Nome alterado com sucesso!\n\n");
                        break;

                    case 2:
                        printf("Digite o novo email: ");
                        fflush(stdin);
                        fgets(email[i], 20, stdin);
                        printf("Email alterado com sucesso!\n\n");
                        break;

                    case 3:
                        printf("Digite o novo endereço: ");
                        fflush(stdin);
                        fgets(endereco[i], 50, stdin);
                        printf("Endereço alterado com sucesso!\n\n");
                        break;

                    case 4:
                        do {
                            printf("Digite a nova altura: ");
                            scanf("%f", &altura[i]);
                        } while (altura[i] < 1 || altura[i] > 2);
                        printf("Altura alterada com sucesso!\n\n");
                        break;

                    case 5:
                        do {
                            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
                            scanf("%s", sexo[i]);
                        } while (strcmp(sexo[i], "masculino") != 0 && strcmp(sexo[i], "feminino") != 0 && strcmp(sexo[i], "indiferente") != 0);
                        printf("Sexo alterado com sucesso!\n\n");
                        break;

                    case 6:
                        do {
                            printf("Digite a nova situação de vacinação (Sim ou Não): ");
                            scanf("%s", vacinacao[i]);
                        } while (strcmp(vacinacao[i], "sim") != 0 && strcmp(vacinacao[i], "não") != 0);
                        printf("Situação de vacinação alterada com sucesso!\n\n");
                        break;

                    case 7:
                        break;

                    default:
                        printf("Opção inválida. Por favor, tente novamente.\n\n");
                        break;
                }
            } while (opcao != 7);

            break;
        }
    }

    if (i == qtdausuarios) {
        printf("\nUsuário não encontrado.\n\n");
    }

    printf("Para retornar ao menu inicial, digite 1: ");
    scanf("%d", &escolhamenu[i]);
    switch (escolhamenu[i]) {
        case 1:
            main();
            break;
    }
}

void excluirusuario() {
    int i, iddd, j;

    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &iddd);

    for (i = 0; i < qtdausuarios; i++) {
        if (iddd == id[i]) {
            printf("\nUsuário excluído:\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s", nome[i]);
            printf("Email: %s", email[i]);
            printf("Endereço: %s", endereco[i]);
            printf("Altura: %.2f\n", altura[i]);
            printf("Sexo: %s\n", sexo[i]);
            printf("Vacinado: %s\n\n", vacinacao[i]);

            for (j = i; j < qtdausuarios - 1; j++) {
                strcpy(nome[j], nome[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(endereco[j], endereco[j + 1]);
                altura[j] = altura[j + 1];
                strcpy(sexo[j], sexo[j + 1]);
                strcpy(vacinacao[j], vacinacao[j + 1]);
                id[j] = id[j + 1];
            }

            qtdausuarios--;
            printf("Usuário excluído com sucesso!\n\n");
            break;
        }
    }

    if (i == qtdausuarios) {
        printf("\nUsuário não encontrado.\n\n");
    }

    printf("Para retornar ao menu inicial, digite 1: ");
    scanf("%d", &escolhamenu[i]);
    switch (escolhamenu[i]) {
        case 1:
            main();
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    printf("------------ MENU ------------\n");
    printf("1 - Coleta de dados\n");
    printf("2 - Buscar usuário\n");
    printf("3 - Editar usuário\n");
    printf("4 - Excluir usuário\n");
    printf("5 - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            coletadedados();
            break;

        case 2:
            buscarusuario();
            break;

        case 3:
            editarusuario();
            break;

        case 4:
            excluirusuario();
            break;

        case 5:
            return 0;

        default:
            printf("Opção inválida. Por favor, tente novamente.\n\n");
            main();
            break;
    }

    return 0;
}
