#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
    
    int inicio(int opcao[][2]){
        int escolha;
        
        
        
        
    }

    void  coletadedados ( int vacinacao[][1],char nome[][40], char email[][20], char sexo[][11], char endereco[][30], double altura[][1]){
            int i;
        for ( i = 0; i < 2; i++)
        {   fflush(stdin);
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
             printf("informe o sexo do %d usuario: Feminino Masculino ou Iindiferente ",i+1);
             scanf("%s",sexo[i]);
             fflush(stdin);
            } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
            
            printf("Agora informe o endereço do usuraio %d",i+1);
            fgets(endereco[i],30,stdin);
            fflush(stdin);
            printf("o usuario %d foi vacinado ? 1-Sim ou 2-Nao",i+1);
            scanf("%d",vacinacao[i]);
            printf("Informe a altura do usuario %d",i+1);
                scanf("%lf",altura[i]);
        }
        
    }
     
            
            
     
     double coletaltura(double altura[][1]){
            int i;
            for ( i = 0; i < 2; i++)
            {   
                printf("Informe a altura do usuario %d",i+1);
                scanf("%lf",&altura[i]);
            }
           
     }
     int idaleatorio(int id[]){
        int i,idd;
        srand(time(NULL));
        for ( i = 0; i < 2; i++)
        {
           
           idd=1000+rand()%5000;
           id[i]=idd;
           printf("o id do %d usuario e: %d",i+1,id[i]);
           
           
            
        }
        return id;

     }
    
    int main()
    {
        char nome[5][40],email[5][50], sexo[5][11],endereco[5][30];
        int i,vacinacao[5],id[2][5],opcao[1],escolha;
        double altura[2];
        do
        {printf("ola usuario seja bem vindo\ninform qual processo deseja realizar!\n ");
        printf("1-incluir um usuário\n");
        printf("1-edite um usuário\n");
        printf("2-exclua um usuário\n");
        printf("4-busque um usuário pelo email\n");
        printf("5-imprima todos os usuários cadastrados\n");
        printf("6-faça backup dos usuários cadastrados\n");
        printf("7-faça restauração dos dados");
        scanf("%d",&escolha);
            switch (escolha)
            {
            case 1:
                coletadedados(nome,email,sexo,endereco,vacinacao,altura);
                
                break;
            case 2:
                
            default:
                break;
            }
                } while (escolha==1);
        inicio(opcao);
        coletadedados(nome,email,sexo,endereco,vacinacao,altura);
        
        coletaltura(altura);
        idaleatorio(id);
        printf("%d",vacinacao);
        
        
        return 0;
    }
    
     
