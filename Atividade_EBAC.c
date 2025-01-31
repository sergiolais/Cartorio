#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocaçao de espaço em memoria 
#include <locale.h> // biblioteca de alocacões de texto por região 
#include <string.h> // biblioteca responsavel por cuidar das string

int registro()//Função responsavel pelo registro
{ 
    //inicio da criação das variáveis/string
       char arquivo [40];
       char cpf [40];
       char nome [40];
       char sobrenome[40];
       char cargo [40];
    //fim da criação das variáveis/string
       
    printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//%s refere-se a string 
	
	
	strcpy(arquivo, cpf); // Responsavel por cipiar a string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo ,"w"); //responsavel por criar o arquivo 
	fprintf(file,cpf); // salva o arquivo
	fclose(file);// fecha o arquivo
	
	
	file = fopen (arquivo , "a");//responsavel por atualizar o arquivo 
	fprintf (file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen (arquivo ,"a");
	fprintf (file , nome);
	fclose(file);
	
	file = fopen (arquivo , "a");
	fprintf(file , ",");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	
	file = fopen (arquivo ,"a");
	fprintf(file , sobrenome);
	fclose(file);
	
	
	file =  fopen (arquivo , "a");
	fprintf(file , ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo);
	
	file = fopen (arquivo , "a");
	fprintf (file , cargo);
	fclose(file);
	
	file = fopen (arquivo , "a");
	fprintf(file , ",");
	fclose(file);
	
	system("pause");
	

}
int consultar()//função responsavel pela consulta 
{
	setlocale(LC_ALL, "Portuguese");//Seleçao de idioma 
	 
	 char cpf [40];
	 char conteudo [200];
	 	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");//responsavel por reescrever no arquivo
	 
	 if(file == NULL)
	 {
	 	printf("Nao foi possivel abrir o arquivo, Nao localizado!\n "); 
	 }   
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informacões do usuario: ");
		printf("%s", conteudo);
	    printf("\n\n");
	}
	
	 system("pause");//pausa a pagina
	 
	 
	 
}
int deletar()
{ 
      
	char cpf[40];
  
    printf("Digite o cpf a ser deletado: ");
    scanf("%s",cpf);
       
    FILE *file;
    file = fopen(cpf , "r");  
    
    if(file == NULL)
    {
    	printf("O usuario nao foi encotrado!\n");
    	system("pause");
	}
  
	remove(cpf);
	
    printf("Usuário deletado com sucesso!\n");
    system("pause");
}



int main()


{
	
	int opcao=0;//Definindo variaveis 
	int loop=1;
	
	for(loop==1;loop=1;)
	{
		
	system("cls");//responsavel por limpar a pagina
	
       setlocale(LC_ALL, "Portuguese");//Seleçao de idioma 
    
       printf("###### Cartório da EBAC ######\n\n");// inicio do menu
       printf("Escolha a opção desejada do menu:\n\n");
       printf("\t1 - Registrar Nomes\n");
       printf("\t2 - Consultar Nomes\n");
       printf("\t3 - Deletar Nomes\n\n");
       printf("\t4 - Sair do sistema\n\n");
       printf("Opçao: ");// Fim do menu
    
       scanf("%d" , &opcao);// armzenando as escolhas do usuario 
    
       system("cls");
    
       switch(opcao)
       
       {
       	    case 1:// inicio das escolhas do usuario 
            registro();
            break;
            
            case 2:
       	    consultar();
        	break;
        	
        	case 3:
        	deletar();
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por usar o sistema!");
	    	return 0;
		    break;
	
	    	
	    	default:
	    	printf("Essa opção nao está disponivel!\n\n");
	    	system("pause");
	    	break;
	    	
	   }//fim das escolhas do usuario 
    
    }
	
}
    
