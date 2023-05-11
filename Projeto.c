#include<stdio.h>
#include<string.h>

    void  coletadedados (char nome[][40], char email[][20], char sexo[][11], char endereco[][30] ){
        int i;
        for ( i = 0; i < 2; i++)
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
    

    int main()
    {
        char nome[2][40],email[2][20], sexo[2][11],endereco[2][30];
        int i;
        
        coletadedados(nome,email,sexo,endereco);
        
        for (i = 0; i < 2; i++)
        {
            printf("\no nome do %d uruario e %s\n",i+1, nome[i]);
            printf("\no email do %d usuario e %s\n",i+1,email[i]);
            printf("\no sexo do %d usuario e %s\n",i+1,sexo[i]);
            printf("\no endereco do %d usuraio e %s\n",i+1,endereco[i]);
        }
        
       
            
            
            
        
        
        
        return 0;
    }
    
    