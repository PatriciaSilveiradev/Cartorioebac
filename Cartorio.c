#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responsável por cuidar das string

int registro()   //função responsável por cadastrar os usuários no sistema
{
    // início criação de variáveis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	 // final da criação de variáveis/strings
	 
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf);  //%s refere-se a string, salva (armazena) dentro dela, q é do cpf, funciona pq foi incluída uma biblioteca pra ela
	
	strcpy(arquivo, cpf);  //responsável por copiar os valores das string, copiou o valor do cpf na variável arquivo (strcpy é uma fução q copia o valor das variáveis com string)
	
	FILE *file;  // cria o arquivo e "w" significa escrever, no banco de dados
	file = fopen(arquivo, "w");  //cria o arquivo, escreve, comando file equivale a abrir a variável arquivo e o "w" quer dizer escrever um arquivo novo
	fprintf(file,cpf);  //salva o valor da variável cpf
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo criado na variável arquivo, "a" de atualizar, acessar o q está dentro
	fprintf(file,",");  // depois de aberto o arquivo ele salva a "," (nova informação) pra separar as informações dadas pelo usuário
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //pergunta ao usuário, coleta informação
	scanf("%s", nome);   //armazena na string e na variável nome
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza 
	fprintf(file,nome); //salva o conteúdo da variável nome dentro do arquivo
	fclose(file);   //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo criado na variável arquivo, "a" de atualizar, acessar o q está dentro
	fprintf(file,",");  // depois de aberto o arquivo ele salva a "," (nova informação) pra separar as informações dadas pelo usuário
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: " );  //pergunta ao usuário, coleta informação
	scanf("%s", sobrenome);  //armazena na string e na variável sobrenome
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza 
	fprintf(file,sobrenome);  //salva o conteúdo da variável sobrenome dentro do arquivo
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abriu o arquivo criado na variável arquivo, "a" de atualizar, acessar o q está dentro
	fprintf(file,",");  // depois de aberto o arquivo ele salva a "," (nova informação) pra separar as informações dadas pelo usuário
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //pergunta ao usuário, coleta informação
	scanf("%s", cargo);  //armazena na string e na variável cargo
	
	file = fopen(arquivo, "a");   //abre o arquivo e atualiza 
	fprintf(file, cargo);  //salva o conteúdo da variável (string) cargo dentro do arquivo == cpf
	fclose(file);   //fecha o arquivo
	
	system("pause");  //o sistema fica parado
	
	
}

int consulta()
{
     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
     
     char cpf[40];   // variável/string
     char conteudo[200];   // variável/string
     
     printf("Digite o cpf a ser consultado: ");  //pergunta ao usuário, coleta informação
     scanf("%s", cpf); //armazena na string e na variável cpf
     
     FILE *file;  // FILE = acesse a pasta do arquivo
     file = fopen(cpf,"r");   //abra o arquivo cpf e leia ele "r"
     
     if(file == NULL)   //se não encontrar o arquivo cpf ou se o valor for nulo
     {
     	printf("Não foi possível abrir o arquivo, não localizado!.\n");   //fala para o usuário
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)   //enquanto busca o conteúdo das string e escreve, armazena até 200 ou for nulo
	 {
	 	printf("\nEssas são as informações do usuário: ");   //fala para o usuário
	 	printf("%s", conteudo);  //salve na string conteúdo
	 	printf("\n\n");   //pula 2 linhas
	 }
	 
	 system("pause");   //o sistema fica parado


}

int deletar()
{
	char cpf[40];    // variável/string
	
	printf("Digite o cpf do usuário a ser deletado: ");   //pergunta ao usuário, coleta informação
	scanf("%s", cpf);  //armazena na string e na variável cpf
	
	remove(cpf);  //função q acessa a pasta principal e remove o arquivo
	
	FILE *file;  // FILE = acesse a pasta do arquivo
	file = fopen(cpf,"r");  //abra o arquivo cpf e leia ele "r"
	
	if(file == NULL)  //se o arquivo for igual a nulo, ou seja, ele não for encontrado
	{
		printf("O usuário não se encontra no sistema!\n");   //fala para o usuário
		system("pause");    //o sistema fica parado para o usuário ler a mensagem
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("### Cartório da Ebac ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
	
        system("cls");
        for(laco=1;laco=1;)
        {
    	
        	system("cls");
	
           setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
     	   printf("### Cartório da Ebac ###\n\n"); //Início do menu
    	   printf("Escolha a opção desejada do menu:\n\n");
     	   printf("\t1 - Registrar nomes\n");
    	   printf("\t2 - Consultar nomes\n");
    	   printf("\t3 - Deletar nomes\n\n"); 
    	   printf("\t4 - Sair do Sistema\n\n");
    	   printf("Opção: "); //Fim do menu
	
    	   scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	   system("cls");  //responsável por limpar a tela
	
	
	       switch(opcao)   // início da seleção do menu
	       {   
	           case 1:
	           registro(); //chamada de funções
	    	   break;
	       
	           case 2:
	           consulta();
	           break;
	       
	           case 3:
	           deletar();
	           break;
	       
	           case 4:
	           printf("Obrigado por utilizar o sistema!\n");
	           return 0;
	           break;
	       
	           default:
	           printf("Está opção não está disponível!\n");
	           system("pause");
	           break;  // fim da seleção
	       	
	       
	       }
        }
    }
    
    else
       printf("Senha incorreta!");
}
