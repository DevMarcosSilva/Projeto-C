#include<stdio.h>
#include<string.h>

    void  coletadedados (char nome[][40], char email[][20]){
        int i;
        for ( i = 0; i < 2; i++)
        {
            printf("Informe o nome completo do %d usuario: ",i+1);
            fgets(nome[i], 40, stdin);
            system("cls");
            
            printf("Agora informe o email do %d usuraio ",i+1);
            fgets(email[i],20,stdin);
            system("cls");
 
            
        }
        
    }

    int main()
    {
        char nome[2][40],email[2][20];
        int i;
        
        coletadedados(nome,email);
        
        for (i = 0; i < 2; i++)
        {
            printf(" o %d uruario e  %s\n",i+1, nome[i]);
            printf("o email do %d usuario e %s",i+1,email[i]);
        }
        
       
            
            
            
        
        
        
        return 0;
    }
    
    