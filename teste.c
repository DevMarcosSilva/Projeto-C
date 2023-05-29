#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
   

char email[1000][20],nome[100][50],sexo[100][11],vacinacao[1000][11],endereco[1000][50],emailbackup[1000][20],sexobackup[0][11],vacinacaobackup[1000][11],nomebackup[1000][50],enderecobackup[1000][50];

float altura[1000];

int id[1000],escolhamenu,qtdausuarios;

double alturabackup[1000];

void encerrarprograma(){
    printf("programa encerrado!!");
}
        void coletadedados (){
            int i,idd;
         
          printf("Quantos usuários deseja incluir?Obs:máximo 1000!");
          scanf("%d",&qtdausuarios);
            
            for ( i = 0; i < qtdausuarios; i++)
        {   fflush(stdin);
            printf("Informe o nome completo do %d usuários: ",i+1);
            fgets(nome[i], 50, stdin);
            fflush(stdin);
            system("cls");
        do
        {
            printf("Agora informe o email do %d usuários ",i+1);
            fgets(email[i],20,stdin);
            fflush(stdin);
        }while (strchr(email[i], '@') == 0);
            
            system("cls");
            printf("Agora informe o Endereço do usuário %d",i+1);
            fgets(endereco[i],30,stdin);
            fflush(stdin);
           do
           {
            printf("Informe a altura do usuários %d",i+1);
            scanf("%f",&altura);
           } while (altura[i]<1 || altura[i] >2);
            
        do
        {    fflush(stdin);
             printf("informe o sexo do %d usuários: Feminino Masculino ou Iindiferente ",i+1);
             scanf("%s",sexo[i]);
             
        } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
        do
        {
             printf("o usuários %d foi vacinado ? 1-Sim ou 2-Nao",i+1);
             scanf("%s",vacinacao[i]);
             fflush(stdin);
          
        } while (strcmp(vacinacao[i], "Sim") !=0 && strcmp(vacinacao[i], "sim")!=0&& strcmp(vacinacao[i], "Nao")!=0&& strcmp(vacinacao[i], "nao")!=0);
        
             srand(time(NULL));
             idd=1000+rand()%5000;
             id[i]=idd;
             printf("o id do %d usuários e: %d\n\n",i+1,id[i]);
        }  printf("Deseja ir para po menu inicial digite 1 sim ou 2 n?o");
            scanf("%d",&escolhamenu); 
            switch (escolhamenu)
            {
            case 1:
                main();
                break;
            case 2:
                encerrarprograma();
                break;
            default:
                break;
            }
        }
        
        void buscarusuario(){
                
             int i,busca,iddd;
             char emailp[50];
        do
        {
             printf("Digite 1 para busca pelo id ou qualquer valor para buscar por e-mail, ou 3 para sair; ");
             scanf("%d",&busca);
                    
            switch (busca)
            {
            case 1:
                printf("Digite o id :");
                scanf("%d",&iddd);
             
             for ( i = 0; i < qtdausuarios; i++)
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
             
             for ( i = 0; i < qtdausuarios; i++)
             {  if (strcmp(email[i],emailp)==0)
                {
                 printf("\n nome:%s \n e-mail: %s\n Sexo: %s\n Endereco %s\n altura %.2lf\n vacina: %s\n",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                }else printf("erro");
             }
              break;
            }
        } while (busca==1 && busca == 2);
        printf("Deseja ir para po menu inicial digite 1 sim ou 2 n?o");
            scanf("%d",&escolhamenu); 
            switch (escolhamenu)
            {
            case 1:
                main();
                break;
                case 2:
                encerrarprograma();
            default:
                break;
            }
                           }
               
        void backup(){
            int i,idd;
        for ( i = 0; i < qtdausuarios; i++)
        {   fflush(stdin);
            printf("Informe o nome completo do %d usuários: ",i+1);
            fgets(nomebackup[i], 50, stdin);
            fflush(stdin);
            system("cls");
            do
            {
                printf("Agora informe o email do %d usuários ",i+1);

            fgets(emailbackup[i],20,stdin);
            fflush(stdin);
            } while (strchr(email[i], '@') == 0);
            
            
            
            system("cls");
            printf("Agora informe o endereço do usuários %d",i+1);
            fgets(enderecobackup[i],30,stdin);
            fflush(stdin);
            
            fflush(stdin);
            printf("Informe a altura do usuários %d",i+1);
                scanf("%lf",&alturabackup[i]);
            do
            {
             printf("informe o sexo do %d usuários: Feminino Masculino ou Iindiferente ",i+1);
             scanf("%s",sexobackup[i]);
             fflush(stdin);
            } while (strcmp(sexobackup[i], "masculino") !=0 && strcmp(sexobackup[i], "feminino")!=0&& strcmp(sexobackup[i], "indiferente")!=0);
             do
            {
             printf("o usuario %d foi vacinado ? 1-Sim ou 2-Nao",i+1);
             scanf("%s",vacinacaobackup[i]);
             fflush(stdin);
             srand(time(NULL));
        
           
           idd=1000+rand()%5000;
           id[i]=idd;
           printf("o id do %d usuários e: %d\n\n",i+1,id[i]);
            } while (strcmp(vacinacaobackup[i], "Sim") !=0 && strcmp(vacinacaobackup[i], "sim")!=0&& strcmp(vacinacaobackup[i], "Nao")!=0&& strcmp(vacinacaobackup[i], "nao")!=0);
        }
         printf("Deseja ir para po menu inicial digite 1 sim ou 2 n?o");
            scanf("%d",&escolhamenu); 
            switch (escolhamenu)
            {
            case 1:
                main();
                break;
            
            default:
                break;
            }
        }

        void editarusuario(){
            
                int i,busca,iddd,op;
                char novonome[50];
                char emailp[50];
              
               do
               {     printf("Digite 1 para bucar o usuários pelo id ou qualquer valor para buspa por e-mail, ou 3 para sair; ");
                     scanf("%d",&busca);
                    switch (busca)
                {
                case 1:
                    
                    printf("Digite o id :");
                    scanf("%d",&iddd);
                    
                    for ( i = 0; i < qtdausuarios; i++){
                    
                    if (iddd==id[i])
                    {   printf("\nDados do usuário\n");
                        printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2f\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                        
                    }else printf("erro");
                    }
                    break;
                    case 2:
                    
                    fflush(stdin);
                    printf("Digite o E-mail:");
                    fgets(emailp,50,stdin);
                    
                    
                for ( i = 0; i < qtdausuarios; i++)
                {
                    if (strcmp(email,emailp)==0)
                    {   printf("\nDados do usuário\n");
                        printf("nome:%s \ne-mail: %s\n Sexo: %s\nEndereco %s\naltura %.2lf\n vacina: %s",nome[i],email[i],sexo[i],endereco[i],altura[i],vacinacao[i]);
                    }else printf("erro");
                    
                }break;
               }
               }while (busca==1 && busca == 2);
            
           
            printf("\nQual dado deseja Editar! \n 1-Nome \n 2-E-mail \n 3-Sexo \n 4-Endereço \n 5-Altura \n 6-Vacina \n");
            scanf("%d",&op);
            
            switch (op)
            {  
            case 1:
                getchar();
                printf("Insira o novo nome:");
                fgets(nome,50,stdin);
                printf("Novo nove inserido com sucesso!\n");
                
                printf("nome:%s\n", nome);
                printf("E-mail:%s\n", email);
                printf("Sexo:%s\n", sexo);
                printf("endereco:%s\n", endereco);
                printf("altura:%.2f\n", altura[i]);
                printf("vacinação:%s\n", vacinacao);
                printf("nome:%s\n", nome);
                
                
                
                break;
            case 2:
               do
               {getchar();
                printf("Insira o novo E-mail\n");
                fgets(email,50,stdin);
               
                printf("Novo Email inserido com sucesso!\n");
                
                printf("nome:%s\n", nome);
                printf("E-mail:%s\n", email);
                printf("Sexo:%s\n", sexo);
                printf("endereco:%s\n", endereco);
                fflush(stdin);
                printf("altura:%.2f\n", altura[i]);
                printf("vacinação:%s\n", vacinacao);
                printf("nome:%s\n", nome);
                
               } while (strchr(email[i], '@') == 0);
             break;
             case 3:
                do
               {getchar();
                printf("Insira o novo Sexo\n");
                fgets(sexo,50,stdin);
               
                printf("Novo Sexo inserido com sucesso!\n");
                
                printf("nome:%s\n", nome);
                printf("E-mail:%s\n", email);
                printf("Sexo:%s\n", sexo);
                printf("endereco:%s\n", endereco);
                fflush(stdin);
                printf("altura:%.2f\n", altura[i]);
                printf("vacinação:%s\n", vacinacao);
                printf("nome:%s\n", nome);
                
               } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
               break;
               case 4:
                getchar();
                printf("Insira o novo Endereço\n");
                fgets(endereco,50,stdin);
               
                printf("Novo Endereço inserido com sucesso!\n");
                
                printf("nome:%s\n", nome);
                printf("E-mail:%s\n", email);
                printf("Sexo:%s\n", sexo);
                printf("endereco:%s\n", endereco);
                fflush(stdin);
                printf("altura:%.2f\n", altura[i]);
                printf("vacinação:%s\n", vacinacao);
                printf("nome:%s\n", nome);
                
              
               break;
               case 5:
                do
               {getchar();
                printf("Insira a nova Altura\n");
                scanf("%f",&altura);
               
                printf("Novo Sexo inserido com sucesso!\n");
                
                printf("nome:%s\n", nome);
                printf("E-mail:%s\n", email);
                printf("Sexo:%s\n", sexo);
                printf("endereco:%s\n", endereco);
                fflush(stdin);
                printf("altura:%.2f\n", altura[i]);
                printf("vacinação:%s\n", vacinacao);
                printf("nome:%s\n", nome);
                
               } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
               break;
               case 6:
                do
               {getchar();
                printf("Insira o nova vacinação\n");
                fgets(vacinacao,50,stdin);
               
                printf("Novo Sexo inserido com sucesso!\n");
                
                printf("nome:%s\n", nome);
                printf("E-mail:%s\n", email);
                printf("Sexo:%s\n", sexo);
                printf("endereco:%s\n", endereco);
                fflush(stdin);
                printf("altura:%.2f\n", altura[i]);
                printf("vacinação:%s\n", vacinacao);
                printf("nome:%s\n", nome);
                
               } while (strcmp(sexo[i], "masculino") !=0 && strcmp(sexo[i], "feminino")!=0&& strcmp(sexo[i], "indiferente")!=0);
               break;
               
            default:
                break;
            }
            
            printf("Deseja ir para po menu inicial digite 1 sim ou 2 n?o");
            scanf("%d",&escolhamenu); 
            switch (escolhamenu)
            {
            case 1:
                main();
                break;
            
            default:
                break;
            }
}
                
        void exibirusuarios(){
            int i;

            for ( i = 0; i < qtdausuarios; i++)
            {
                printf("usuario %d: ",i+1);
                
                printf("nome :%s\n ",nome[i] );
                
                printf("E-mail :%s\n ",email[i]);
                
                printf("Sexo :%s\n ",sexo[i]);
                printf("Endereço :%d\n ",endereco[i]);
                printf("Altura :%d\n ",altura[i]);
                
                printf("Vacina :%s\n ",vacinacao[i]);
                

            }
            printf("Deseja ir para po menu inicial digite 1 sim ou 2 n?o");
            scanf("%d",&escolhamenu); 
            switch (escolhamenu)
            {
            case 1:
                main();
                break;
            
            default:
                break;
            }
        }
    
    int main()
    {   setlocale(LC_ALL,"");
        
        int escolha;
        
        do
        {printf("  olá usuário seja Bem vindo!\n  Informe qual processo deseja realizar!\n\n");
        printf("1-Incluir um usuário\n");
        printf("2-Edite um usuário\n");
        printf("3-Excluir um usuário\n");
        printf("4-Buscar usuário pelo email ou ID \n");
        printf("5-Exibir todos os usuários cadastrados\n");
        printf("6-Realizar restauração de dados\n");
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
            case 5:
                exibirusuarios();
                break;
            default:
                break;
            }
                } while (escolha==1);
        
        
    }
      