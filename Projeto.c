#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#define size 1   

char email[1000][20];
char nome[1000][50];
char sexo[1000][11];
double altura[50];
char vacinacao[1000][11];
char endereco [1000][50];
int id[][8];


    void  coletadedados (){
            int i,idd;
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
        }while (strchr(email[i], '@') == 0);
            
            system("cls");
            printf("Agora informe o endereço do usuário %d",i+1);
            fgets(endereco[i],30,stdin);
            fflush(stdin);
            printf("Informe a altura do usuario %d",i+1);
            scanf("%lf",&altura[i]);
        do
        {    fflush(stdin);
             printf("informe o sexo do %d usuario: Feminino Masculino ou Iindiferente ",i+1);
             scanf("%s",sexo[i]);
             
        } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
        do
        {
             printf("o usuario %d foi vacinado ? 1-Sim ou 2-Nao",i+1);
             scanf("%s",vacinacao[i]);
             fflush(stdin);
          
        } while (strcmp(vacinacao[i], "Sim") !=0 && strcmp(vacinacao[i], "sim")!=0&& strcmp(vacinacao[i], "Nao")!=0&& strcmp(vacinacao[i], "nao")!=0);
        
             srand(time(NULL));
             idd=1000+rand()%5000;
             id[i][i]=idd;
             printf("o id do %d usuario e: %d\n\n",i+1,id[i]);
        }    
        }
        
        
        void buscarusuario(){
                
             int i,busuca,iddd;
             char emailp[50];
        do
        {
             printf("Digite 1 para buca pelo id ou qualquer valor para buspa por e-mail, ou 3 para sair; ");
             scanf("%d",&busuca);
                    
            switch (busuca)
            {
            case 1:
                printf("Digite o id :");
                scanf("%d",&iddd);
             
             for ( i = 0; i < size; i++)
             {  if (iddd==id[i])
                { 
                printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                }
                else printf("erro");
             }
                break;
                    
            case 2:
                printf("Digite o E-mail:");
                fgets(emailp,50,stdin);
             
             for ( i = 0; i < size; i++)
             {  if (strcmp(email[i],emailp)==0)
                {
                 printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                }else printf("erro");
             }
              break;
            }
        } while (busuca==1 && busuca == 2);
                           }
        
        
        void backup(){
            int i,idd;
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
            printf("Agora informe o endereÃ§o do usuraio %d",i+1);
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
             srand(time(NULL));
        
           
           idd=1000+rand()%5000;
           id[i][i]=idd;
           printf("o id do %d usuario e: %d\n\n",i+1,id[i]);
            } while (strcmp(vacinacao[i], "Sim") !=0 && strcmp(vacinacao[i], "sim")!=0&& strcmp(vacinacao[i], "Nao")!=0&& strcmp(vacinacao[i], "nao")!=0);
        }
         
        }

        void editarusuario(){
            
                int i,busuca,iddd,op;
                char emailp[50];
               do
               {     printf("Digite 1 para bucar o usuario pelo id ou qualquer valor para buspa por e-mail, ou 3 para sair; ");
                     scanf("%d",&busuca);
                    switch (busuca)
                {
                case 1:
                    fflush(stdin);
                    printf("Digite o id :");
                    scanf("%d",&iddd);
                    for ( i = 0; i < size; i++){
                    
                    if (iddd==id[i])
                    {   fflush(stdin);
                        printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                        fflush(stdin);
                    }else printf("erro");
                    }
                    break;
                    case 2:
                    
                    fflush(stdin);
                    printf("Digite o E-mail:");
                    
                    fgets(emailp,50,stdin);
                    
                    
                for ( i = 0; i < size; i++)
                {
                    if (strcmp(email[i],emailp)==0)
                    {
                        printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                    }else printf("erro");
                    
                }break;
               }
               }while (busuca==1 && busuca == 2);
            
            do
            {
            printf("\nQual dado deseja Editar! \n 1-Nome \n 2-E-mail \n 3-Sexo \n 4-Endereço \n 5-Altura \n 6-Vacina \n");
            scanf("%d",&op);
            switch (op)
            {
            case 1:
                getchar();
                printf("Insira o novo nome:");
                gets(nome[i]);
                
                printf("Novo nome inserido com sucesso!\n");
                
                printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                ;
                break;
            case 2:
               do
               {
                printf("Insira o novo E-mail:");
                gets(email[i]);
                
                printf("Novo E-mail inserido com sucesso!\n");
                
                printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                
               } while (strchr(email[i], '@') == 0);
                
                
            break;
            default:
                break;
            }
            
            } while (op ==1 && op==2);
            
            
           
            
            
            }
                
        
    int main()
    {   setlocale(LC_ALL,"");
        char nome[5][40],email[5][50], sexo[5][11],endereco[5][30],BuscaEmail[2][50],busuca[2][50],vacinacao[5];
        int i,id[2][5],opcao[1],escolha;
        double altura[50];
        do
        {printf("  Olá usuário seja Bem vindo!\n  Informe qual processo deseja realizar!\n\n");
        printf("1-Incluir um usuário\n");
        printf("2-Edite um usuário\n");
        printf("3-Excluir um usuário\n");
        printf("4-Buscar usuário pelo email ou ID \n");
        printf("5-Exibir todos os usuários cadastrados\n");
        printf("6-Realizar backup dos usuários cadastrados\n");
        printf("7-Realizar restauração dos dados\n");
        scanf("%d",&escolha);
            switch (escolha)
            {
            case 1:
                coletadedados();
                
                break;
            case 2: 
                editarusuario();
                break;
            case 6:
              backup();    
            case 4:
                buscarusuario();
                break;
            default:
                break;
            }
                } while (escolha==1);
        
        
    }