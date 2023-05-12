#include<stdio.h>
#include<string.h>

    void  coletadedados (char nome[][40], char email[][20], char sexo[][11], char endereco[][30] ){
        int i;
        for ( i = 0; i < ; i++)
        {
            printf("Informe o nome completo do %d usuario: ",i+1);
            fgets(nome[i], 40, stdin);
            fflush(stdin);
            system("cls");
            printf("Agora informe o email do %d usuraio ",i+1);
            fgets(email[i],20,stdin);
            fflush(stdin);
            system("cls");
            do
            {
             printf("informe o sexo do %d usuario: feminino masculino ou indiferente ",i+1);
             scanf("%s",sexo[i]);
             fflush(stdin);
            } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
            
            printf("Agora informe o endereço do usuraio %d",i+1);
            fgets(endereco[i],30,stdin);
            fflush(stdin);
            
        }
        
    }
     int vacina(int vacinacao[][1]){
            int i;
            for ( i = 0; i < 5; i++)
            {
             printf("o usuario %d foi vacinado ? 1-Sim ou 2-Nao",i+1);
            scanf("%d",&vacinacao[i]);
            }
            
            
     }

    int main()
    {
        char nome[5][40],email[5][50], sexo[5][11],endereco[5][30];
        int i,vacinacao[5];
        
        coletadedados(nome,email,sexo,endereco);
        vacina(vacinacao);
        printf("%d",vacinacao);
        for (i = 0; i < 5; i++)
        {
            printf("\no nome do %d uruario e %s\n",i+1, nome[i]);
            printf("\no email do %d usuario e %s\n",i+1,email[i]);
            printf("\no sexo do %d usuario e %s\n",i+1,sexo[i]);
            printf("\no endereco do %d usuraio e %s\n",i+1,endereco[i]);
            if (vacinacao[i] == 1)
            {
                printf("o usuario %d foi vacinado ",i+1);
            }else printf("o usuario %d nao foi vacinado ",i+1);
            
            
        }
        
       
            
            
            
        
        
        
        return 0;
    }
    
    