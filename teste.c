#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void preencherdados(int vacina[], char nome[][50], char email[][25], char sexo[][13], char endereco[][30], double *altura){
    
    for (int i = 0; i < 3; i++){
        printf("Digite o nome do usuario: ");
        fgets(nome[i], 50, stdin);
        fflush(stdin);
        
        if (nome[i][0] == 'z')
        {
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

int main()
{
    int vacina[3], i;
    char opcao, nome[3][50], email[3][25], sexo[3][13], enderenco[3][30];
    double altura[3];

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
            //codigo
            break;
        case 'd':
            //codigo
            break;
        case 'e':
            printf("Usuarios cadstrados\n");
            for ( i = 0; i < 3; i++){
                printf(" Nome: %s Email: %s Sexo: %s Endereco: %s altura: %.2lf\n vacina: %d\n", nome[i], email[i], sexo[i], enderenco[i], altura[i], vacina[i]);
            }
            break;
        case 'f':
            //codigo
            break;
        case 'g':
            //codigo
            break;
        case 'h':
            //codigo
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