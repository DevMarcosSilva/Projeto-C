#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void preencherdados(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura){
    
    for (int i = 0; i < 999; i++){
        printf("Digite o nome do usuario: ");
        fgets(nome[i], 50, stdin);
        fflush(stdin);
        
        if (nome[i][0] == 'z')
        {
            system("cls");
            break;
        }
        
        do{
            printf("Digite a altura em metros: ");
            scanf("%lf", &altura[i]);   
            fflush(stdin);
        } while (altura[i] < 1 || altura[i] > 2);
        do{
            printf("Digite o email do usuario: ");
            fgets(email[i], 25, stdin);
            fflush(stdin);
        } while (strchr(email[i], '@') == 0);
        do{
            printf("Digite o sexo do usuario: ");
            fgets(sexo[i], 13, stdin);
            fflush(stdin);
        } while (strcmp(sexo[i], "masculino") == 0 && strcmp(sexo[i], "feminino") == 0 && strcmp(sexo[i], "indiferente") == 0);
        
        printf("Digite o endereco do usuario: ");
        fgets(endereco[i], 30, stdin);
        printf("Usuario tomou vacina ? 1 - sim / 2 - nao: ");
        scanf("%d", &vacina[i]);
        getchar();
        system("cls");
    }
}

void editarDado(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura) {
    int escolha;
    char opcao;
    
    do {
        printf("Escolha o numero do dado que deseja editar (0 a 2): ");
        scanf("%d", &escolha);
        getchar();
        
        printf("Dado escolhido: Nome: %s, Email: %s, Sexo: %s, Endereco: %s, Altura: %.2lf\n, Vacina: %d\n", nome[escolha], email[escolha], sexo[escolha], endereco[escolha], altura[escolha], vacina[escolha]);
        
        printf("Qual dado deseja editar?\n");
        printf("a - Nome\n");
        printf("b - Email\n");
        printf("c - Sexo\n");
        printf("d - Endereco\n");
        printf("e - Altura\n");
        printf("f - Vacina\n");
        printf("s - Sair\n");
        printf("Opcao: ");
        scanf("%c", &opcao);
        getchar();
        
        switch(opcao) {
            case 'a':
                printf("Digite o novo nome: ");
                fgets(nome[escolha], 50, stdin);
                break;
            case 'b':
                printf("Digite o novo email: ");
                fgets(email[escolha], 25, stdin);
                break;
            case 'c':
                printf("Digite o novo sexo: ");
                fgets(sexo[escolha], 13, stdin);
                break;
            case 'd':
                printf("Digite o novo endereco: ");
                fgets(endereco[escolha], 30, stdin);
                break;
            case 'e':
                do {
                    printf("Digite a nova altura em metros: ");
                    scanf("%lf", &altura[escolha]);
                    getchar();
                } while (altura[escolha] < 1 || altura[escolha] > 2);
                break;
            case 'f':
                printf("O usuario tomou vacina? 1 - sim / 2 - nao: ");
                scanf("%d", &vacina[escolha]);
                getchar();
                break;
            case 's':
                printf("Edicao finalizada.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        
    } while (opcao != 'z');
}

void dadosPorEmail(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura, char *emailBuscado) {
    for (int i = 0; i < 999; i++){
        if (strcmp(email[i], emailBuscado) == 0){
            printf("Dados do usuario com email %s", emailBuscado);
            printf("Nome: %s", nome[i]);
            printf("Email: %s", email[i]);
            printf("Sexo: %s", sexo[i]);
            printf("Endereco: %s", endereco[i]);
            printf("Altura: %.2lf\n", altura[i]);
            printf("Vacina: %d\n", vacina[i]);
            break;
        }
        else
            printf("Usuario de email %s nao encontrado", emailBuscado);
    }
    
}

void backupUsuarios(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura, int backupVacina[], char backupNome[][50], char backupEmail[][25], char backupSexo[][13], char backupEndereco[][30], double *backupAltura) {
    for (int i = 0; i < 999; i++){
        strcpy(backupNome[i], nome[i]);
        strcpy(backupEmail[i], email[i]);
        strcpy(backupSexo[i], sexo[i]);
        strcpy(backupEndereco[i], endereco[i]);
        backupAltura[i] = altura[i];
        backupVacina[i] = vacina[i];
    }
    
}

void excluirUsuario(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura, int excluirDados) {
    for (int i = excluirDados; i < 999; i++)
    {
        strcpy(nome[i], nome[i + 1]);
        strcpy(email[i], email[i + 1]);
        strcpy(sexo[i], sexo[i + 1]);
        strcpy(endereco[i], endereco[i + 1]);
        altura[i] = altura[i + 1];
        vacina[i] = vacina[i + 1];
    }

    strcpy(nome[999], "");
    strcpy(email[999], "");
    strcpy(sexo[999], "");
    strcpy(endereco[999], "");
    altura[999] = 0.0;
    vacina[999]; 0;
}

void restaurandoDados(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura, int backupVacina[], char backupNome[][50], char backupEmail[][25], char backupSexo[][13], char backupEndereco[][30], double *backupAltura) {
    for (int i = 0; i < 999; i++){
        strcpy(nome[i], backupNome[i]);
        strcpy(email[i], backupEmail[i]);
        strcpy(sexo[i], backupSexo[i]);
        strcpy(endereco[i], backupEndereco[i]);
        altura[i] = backupAltura[i];
        vacina[i] = backupVacina[i];
    }
}

int main()
{
    int vacina[999], backupVacina[999], i;
    char opcao, nome[999][50], backupNome[999][50], email[999][25], backupEmail[999][50], sexo[999][13], backupSexo[999][13], enderenco[999][30], backupEndereco[999][30];
    double altura[999], backupAltura[999];

    do{
        printf("Digite a opcao que deseja fazer: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao){
        case 'a': 
            preencherdados(&vacina, nome, email, sexo, enderenco, altura);
            break;

        case 'b':
            editarDado(&vacina, nome, email, sexo, enderenco, altura);
            break;
        case 'c':
            printf("Digite o indice do usuario que deseja excluir (0 a 2): ");
            int excluirDados;
            scanf("%d", &excluirDados);
            excluirUsuario(vacina, nome, email, sexo, enderenco, altura, excluirDados);
            printf("Usuario excluido");
            break;
        case 'd':
            printf("Digite o email do usuario que deseja buscar: ");
            char emailBuscado[25];
            fgets(emailBuscado, 25, stdin);
            dadosPorEmail(vacina, nome, email, sexo, enderenco, altura, emailBuscado);
            break;
        case 'e':
            printf("Usuarios cadstrados\n");
            for ( i = 0; i < 999; i++){
                if (strlen(nome[i]) > 2)
                {
                    printf(" Nome: %s Email: %s Sexo: %s Endereco: %s altura: %.2lf\n vacina: %d\n", nome[i], email[i], sexo[i], enderenco[i], altura[i], vacina[i]);
                }
            break;
            }
            break;
        case 'f':
            backupUsuarios(vacina, nome, email, sexo, enderenco, altura, backupVacina, backupNome, backupEmail, backupSexo, backupEndereco, backupAltura);
            printf("Backup realizado.");
            break;
        case 'g':
            restaurandoDados(vacina, nome, email, sexo, enderenco, altura, backupVacina, backupNome, backupEmail, backupSexo, backupEndereco, backupAltura);
            printf("Dados restaurados com sucesso");
            break;
        case 's':
            printf("Programa Finalizado");
            break;
        default:
            printf("Opçãi invalida. Tente novamente\n");
            break;
        }
    } while (opcao != 's');
    return 0;
}