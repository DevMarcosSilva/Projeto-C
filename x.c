#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>

#define size 1000

char email[size][50];
char nome[size][50];
char sexo[size][20];
double altura[size];
int vacinacao[size];
char endereco[size][50];
int id[size];

void coletarDados() {
    int i;
    float alturaAux;
    
    for (i = 0; i < size; i++) {
        fflush(stdin);
        printf("Informe o nome completo do %dº usuário: ", i + 1);
        fgets(nome[i], 50, stdin);
        
        fflush(stdin);
        printf("Agora informe o email do %dº usuário: ", i + 1);
        fgets(email[i], 50, stdin);
        
        while (strchr(email[i], '@')) {
            printf("Email inválido. Informe novamente: ");
            fgets(email[i], 50, stdin);
        }
        
        printf("Agora informe o endereço do usuário %dº: ", i + 1);
        fgets(endereco[i], 50, stdin);
        
        do {
            printf("Informe a altura do usuário %dº (entre 1 e 2 metros): ", i + 1);
            scanf("%f", &alturaAux);
            fflush(stdin);
        } while (alturaAux < 1 || alturaAux > 2);
        altura[i] = alturaAux;
        
        printf("Informe o sexo do %dº usuário (Feminino, Masculino ou Indiferente): ", i + 1);
        fgets(sexo[i], 20, stdin);
        
        while (strcmp(sexo[i], "Feminino\n") != 0 && strcmp(sexo[i], "Masculino\n") != 0 && strcmp(sexo[i], "Indiferente\n") != 0) {
            printf("Sexo inválido. Informe novamente: ");
            fgets(sexo[i], 20, stdin);
        }
        
        printf("O usuário %dº foi vacinado? (1 - Sim, 0 - Não): ", i + 1);
        scanf("%d", &vacinacao[i]);
        
        srand(time(NULL));
        id[i] = 1000 + rand() % 5000;
        
        printf("O ID do %dº usuário é: %d\n\n", i + 1, id[i]);
        
        fflush(stdin);
        printf("Pressione Enter para continuar...\n");
        getchar();
        system("cls");
    }
}

void buscarUsuario() {
    int i, opcao;
    char emailBusca[50];
    int idBusca;
    
    printf("Digite 1 para buscar pelo ID ou qualquer outro valor para buscar pelo email: ");
    scanf("%d", &opcao);
    fflush(stdin);
    
    if (opcao == 1) {
        printf("Digite o ID: ");
        scanf("%d", &idBusca);
        
        for (i = 0; i < size; i++) {
            if (id[i] == idBusca) {
                printf("Nome: %s", nome[i]);
                printf("Email: %s", email[i]);
                printf("Sexo: %s", sexo[i]);
                printf("Endereço: %s", endereco[i]);
                printf("Altura: %.2lf\n", altura[i]);
                printf("Vacinado: %s\n\n", vacinacao[i]);
                break;
            }
        }
        
        if (i == size) {
            printf("Usuário não encontrado.\n");
        }
    } else {
        printf("Digite o email: ");
        fgets(emailBusca, 50, stdin);
        fflush(stdin);
        
        for (i = 0; i < size; i++) {
            if (strcmp(email[i], emailBusca) == 0) {
                printf("Nome: %s", nome[i]);
                printf("Email: %s", email[i]);
                printf("Sexo: %s", sexo[i]);
                printf("Endereço: %s", endereco[i]);
                printf("Altura: %.2lf\n", altura[i]);
                printf("Vacinado: %s\n\n", vacinacao[i]);
                
            }
        }
        
        if (i == size) {
            printf("Usuário não encontrado.\n");
        }
    }
}

void exibirUsuarios() {
    int i;
    
    for (i = 0; i < size; i++) {
        printf("Usuário %d:\n", i + 1);
        printf("Nome: %s", nome[i]);
        printf("Email: %s", email[i]);
        printf("Sexo: %s", sexo[i]);
        printf("Endereço: %s", endereco[i]);
        printf("Altura: %.2lf\n", altura[i]);
        printf("Vacinado: %s\n\n", vacinacao[i]);
    }
}

int main() {
    setlocale(LC_ALL, "");
    int escolha;
    
    
        printf("Olá usuário, seja bem-vindo!\n");
        printf("Informe qual processo deseja realizar:\n");
        printf("1 - Incluir um usuário\n");
        printf("2 - Editar um usuário\n");
        printf("3 - Excluir um usuário\n");
        printf("4 - Buscar usuário pelo email ou ID\n");
        printf("5 - Exibir todos os usuários cadastrados\n");
        printf("6 - Realizar backup dos usuários cadastrados\n");
        printf("7 - Realizar restauração dos dados\n");
        printf("8 - Sair\n");
        scanf("%d", &escolha);
        fflush(stdin);
        
        switch (escolha)
        {
        case 1:
            coletarDados();
            break;
        ca
        default:
            break;
        }
     return 0;
}