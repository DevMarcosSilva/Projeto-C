#include <stdio.h>
#include <string.h>

struct Endereco {
    char rua[50];
    int numero;
    char bairro[30];
    char cidade[30];
    char estado[3];
    char cep[10];
};

void coletarEndereco(struct Endereco *endereco) {
    printf("Informe o endereço:\n");
    printf("Rua: ");
    scanf("%s", endereco->rua);
    fflush(stdin);
    printf("Número: ");
    scanf("%d", &endereco->numero);
    fflush(stdin);
    printf("Bairro: ");
    scanf("%s", endereco->bairro);
    fflush(stdin);
    printf("Cidade: ");
    scanf("%s", endereco->cidade);
    fflush(stdin);
    printf("Estado: ");
    scanf("%s", endereco->estado);
    fflush(stdin);
    printf("CEP: ");
    scanf("%s", endereco->cep);
    fflush(stdin);
}

int main() {
    struct Endereco endereco;
    coletarEndereco(&endereco);
    
    printf("\nEndereço informado:\n");
    printf("%s, %d - %s, %s - %s, %s\n", endereco.rua, endereco.numero, endereco.bairro, endereco.cidade, endereco.estado, endereco.cep);
    
    return 0;
}