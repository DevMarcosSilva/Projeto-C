#include<stdio.h>
#include<string.h>

    void  preencherdados (char nome[][10], char sobrenome[][10]){
        int i;
        for ( i = 0; i < 1; i++)
        {
            printf("Digite seu nome: ");
            fgets(nome, 10, stdin);
            printf("Digite seu sobrenome: ");
            fgets(sobrenome, 10, stdin);
        }
        
    }

    int main()
    {
        char nome[2][10],sobrenome[2][10];
        int i;
        
        preencherdados(nome, sobrenome);
        
        for (i = 0; i < 1; i++)
        {
            printf(" %s %s", nome[i], sobrenome[i]);
        }
        
       
            
            
            
        
        
        
        return 0;
    }
    