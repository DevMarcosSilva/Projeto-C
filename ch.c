#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 2

char email[1000][20];
char nome[1000][50];
char sexo[1000][11];
double altura[1000];
char vacinacao[1000][11];
char endereco[1000][50];
int id[1000];

void coletaDeDados()
{
    int i, idd;
    float alturaAux;
    for (i = 0; i < SIZE; i++)
    {
        fflush(stdin);
        printf("Informe o nome completo do %d usuario: ", i + 1);
        fgets(nome[i], 50, stdin);
        fflush(stdin);
        system("cls");

        do
        {
            printf("Agora informe o email do %d usuraio ", i + 1);
            fgets(email[i], 20, stdin);
            fflush(stdin);
        } while (strchr(email[i], '@') == 0);

        system("cls");
        printf("Agora informe o endereço do usuário %d: ", i + 1);
        fgets(endereco[i], 50, stdin);
        fflush(stdin);

        do
        {
            printf("Informe a altura do usuário %d: ", i + 1);
            scanf("%f", &alturaAux);
            fflush(stdin);
        } while (alturaAux < 1 || alturaAux > 2);
        altura[i] = alturaAux;

        do
        {
            printf("Informe o sexo do %d usuario (Feminino, Masculino ou Indiferente): ", i + 1);
            scanf("%s", sexo[i]);
            fflush(stdin);
        } while (strcmp(sexo[i], "masculino") != 0 && strcmp(sexo[i], "feminino") != 0 && strcmp(sexo[i], "indiferente") != 0);

        do
        {
            printf("O usuario %d foi vacinado? 1-Sim ou 2-Nao: ", i + 1);
            scanf("%s", vacinacao[i]);
            fflush(stdin);

        } while (strcmp(vacinacao[i], "Sim") != 0 && strcmp(vacinacao[i], "sim") != 0 && strcmp(vacinacao[i], "Nao") != 0 && strcmp(vacinacao[i], "nao") != 0);

        srand(time(NULL));
        idd = 1000 + rand() % 5000;
        id[i] = idd;
        printf("O id do %d usuario é: %d\n\n", i + 1, id[i]);
    }
}

void buscarUsuario()
{
    int i, busca, idd;
    char emailp[50];
    do
    {
        printf("Digite 1 para busca pelo id ou qualquer valor para buscar por e-mail, ou 3 para sair: ");
        scanf("%d", &busca);

        switch (busca)
        {
        case 1:
            printf("Digite o id: ");
            scanf("%d", &idd);

            for (i = 0; i < SIZE; i++)
            {
                if (idd == id[i])
                {
                    printf("Nome: %s\nE-mail: %s\nSexo: %s\nEndereco: %s\nAltura: %.2lf\nVacina: %s\n", nome[i], email[i], sexo[i], endereco[i], altura[i], vacinacao[i]);
                }
                else
                {
                    printf("Erro\n");
                }
            }
            break;

        case 2:
            printf("Digite o E-mail: ");
            scanf("%s", emailp);

            for (i = 0; i < SIZE; i++)
            {
                if (strcmp(email[i], emailp) == 0)
                {
                    printf("\nNome: %s\nE-mail: %s\nSexo: %s\nEndereco: %s\nAltura: %.2lf\nVacina: %s\n", nome[i], email[i], sexo[i], endereco[i], altura[i], vacinacao[i]);
                }
                else
                {
                    printf("Erro\n");
                }
            }
            break;
        }
    } while (busca == 1 && busca == 2);
}

void backup()
{
    int i, idd;
    for (i = 0; i < SIZE; i++)
    {
        fflush(stdin);
        printf("Informe o nome completo do %d usuario: ", i + 1);
        fgets(nome[i], 50, stdin);
        fflush(stdin);
        system("cls");

        do
        {
            printf("Agora informe o email do %d usuraio ", i + 1);
            fgets(email[i], 20, stdin);
            fflush(stdin);
        } while (strchr(email[i], '@') == 0);

        system("cls");
        printf("Agora informe o endereÃ§o do usuraio %d: ", i + 1);
        fgets(endereco[i], 30, stdin);
        fflush(stdin);

        fflush(stdin);
        printf("Informe a altura do usuario %d: ", i + 1);
        scanf("%lf", &altura[i]);

        do
        {
            printf("Informe o sexo do %d usuario (Feminino, Masculino ou Indiferente): ", i + 1);
            scanf("%s", sexo[i]);
            fflush(stdin);
        } while (strcmp(sexo[i], "masculino") != 0 && strcmp(sexo[i], "feminino") != 0 && strcmp(sexo[i], "indiferente") != 0);

        do
        {
            printf("O usuario %d foi vacinado? 1-Sim ou 2-Nao: ", i + 1);
            scanf("%s", vacinacao[i]);
            fflush(stdin);

            srand(time(NULL));

            idd = 1000 + rand() % 5000;
            id[i] = idd;
            printf("O id do %d usuario é: %d\n\n", i + 1, id[i]);
        } while (strcmp(vacinacao[i], "Sim") != 0 && strcmp(vacinacao[i], "sim") != 0 && strcmp(vacinacao[i], "Nao") != 0 && strcmp(vacinacao[i], "nao") != 0);
    }
}

void editarUsuario()
{
    int i, busca, idd, op;
    char emailp[50];
    do
    {
        printf("Digite 1 para buscar o usuário pelo ID ou qualquer valor para buscar por e-mail, ou 3 para sair: ");
        scanf("%d", &busca);
        switch (busca)
        {
        case 1:
            fflush(stdin);
            printf("Digite o ID: ");
            scanf("%d", &idd);
            for (i = 0; i < SIZE; i++)
            {
                if (idd == id[i])
                {
                    fflush(stdin);
                    printf("Nome: %s\nE-mail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2lf\nVacina: %s\n", nome[i], email[i], sexo[i], endereco[i], altura[i], vacinacao[i]);
                    fflush(stdin);
                }
                else
                {
                    printf("Erro\n");
                }
            }
            break;
        default:
            fflush(stdin);
            printf("Digite o E-mail: ");
            fgets(emailp, 50, stdin);
            for (i = 0; i < SIZE; i++)
            {
                if (strcmp(email[i], emailp) == 0)
                {
                    printf("Nome: %s\nE-mail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2lf\nVacina: %s\n", nome[i], email[i], sexo[i], endereco[i], altura[i], vacinacao[i]);
                }
                else
                {
                    printf("Erro\n");
                }
            }
            break;
        }
    } while (busca == 1 || busca == 2);

    do
    {
        printf("\nQual dado deseja editar:\n1 - Nome\n2 - E-mail\n3 - Sexo\n4 - Endereço\n5 - Altura\n6 - Vacina\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            getchar();
            printf("Insira o novo nome: ");
            fgets(nome[i], 50, stdin);
            printf("Novo nome inserido com sucesso!\n");
            getchar();
            printf("Nome: %s\nE-mail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2lf\nVacina: %s\n", nome[i], email[i], sexo[i], endereco[i], altura[i], vacinacao[i]);
            break;
        case 2:
            do
            {
                printf("Insira o novo E-mail: ");
                fgets(email[i], 20, stdin);
                printf("Novo E-mail inserido com sucesso!\n");
                printf("Nome: %s\nE-mail: %s\nSexo: %s\nEndereço: %s\nAltura: %.2lf\nVacina: %s\n", nome[i], email[i], sexo[i], endereco[i], altura[i], vacinacao[i]);
            } while (strchr(email[i], '@') == NULL);
            break;
        default:
            break;
        }
    } while (op == 1 || op == 2);
}

void exibirUsuarios()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Usuário %d: \n", i + 1);
        getchar();
        printf("Nome: %s\n", nome[i]);
        getchar();
        printf("E-mail: %s\n", email[i]);
        getchar();
        printf("Sexo: %s\n", sexo[i]);
        printf("Endereco: %s\n", endereco[i]);
        printf("Altura: %.2lf\n", altura[i]);
        getchar();
        printf("Vacina: %s\n", vacinacao[i]);
    }
}

int main()
{
    setlocale(LC_ALL, "");

    int i, opcao, escolha;

    do
    {
        printf("Olá usuário, seja bem-vindo!\nInforme qual processo deseja realizar:\n");
        printf("1 - Incluir um usuário\n");
        printf("2 - Editar um usuário\n");
        printf("3 - Excluir um usuário\n");
        printf("4 - Buscar usuário pelo email ou ID\n");
        printf("5 - Exibir todos os usuários\n");
        printf("6 - Realizar backup dos dados\n");
        printf("7 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Deseja incluir quantos usuários? ");
            scanf("%d", &escolha);
            
            coletaDeDados();
            break;

        case 2:
            editarUsuario();
            break;

        case 3:
            printf("Função ainda não implementada\n");
            break;

        case 4:
            buscarUsuario();
            break;

        case 5:
            exibirUsuarios();
            break;

        case 6:
            backup();
            break;

        case 7:
            printf("Obrigado por utilizar nosso sistema!\n");
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != 7);

    return 0;
}