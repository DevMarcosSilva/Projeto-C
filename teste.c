#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define size 1   
char email[][20];
char nome[][50];
char sexo[][11];
double altura[50];
char vacinacao[][11];
char endereco [][50];

    void  coletadedados (){
            int i;
        for ( i = 0; i < size; i++)
        {   fflush(stdin);
            printf("Informe o nome completo do %d usuario: ",i+1);
            fgets(nome[i], 50, stdin);
            fflush(stdin);
            system("cls");
            do
            {
                printf("Agora informe o email do %d usuraio ",i+1);
                
            fgets(email[i],20,stdin);
            fflush(stdin);
            } while (strchr(email[i], '@') == 0);
            
            
            
            system("cls");
            printf("Agora informe o endereço do usuraio %d",i+1);
            fgets(endereco[i],30,stdin);
            fflush(stdin);
            
            fflush(stdin);
            printf("Informe a altura do usuario %d",i+1);
                scanf("%lf",&altura[i]);
            do
            {
             printf("informe o sexo do %d usuario: Feminino Masculino ou Iindiferente ",i+1);
             scanf("%s",sexo[i]);
             fflush(stdin);
            } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
             do
            {
             printf("o usuario %d foi vacinado ? 1-Sim ou 2-Nao",i+1);
            scanf("%s",vacinacao[i]);
             fflush(stdin);
            } while (strcmp(vacinacao[i], "Sim") !=0 && strcmp(vacinacao[i], "sim")!=0&& strcmp(vacinacao[i], "Nao")!=0&& strcmp(vacinacao[i], "nao")!=0);

            
        }
        
    }
        void buscarusuario(){
                
                
                int i,busuca[50];
                
                    fflush(stdin);
                    printf("Digite o E-mail:");
                    
                    fgets(busuca,20,stdin);
                    
                    
                for ( i = 0; i < size; i++)
                {
                    if (strcmp(email[i],busuca)==0)
                    {
                        printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                    }else printf("erro");
                    
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
        char nome[5][40],email[5][50], sexo[5][11],endereco[5][30],BuscaEmail[2][50],busuca[2][50],vacinacao[5];
        int i,id[2][5],opcao[1],escolha;
        double altura[50];
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
                coletadedados();
                
                break;
            case 4:
                buscarusuario();
            default:
                break;
            }
                } while (escolha==1);
        
        
    }
      