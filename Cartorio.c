#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca respons�vel por cuidar das string

int registro()   //fun��o respons�vel por cadastrar os usu�rios no sistema
{
    // in�cio cria��o de vari�veis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	 // final da cria��o de vari�veis/strings
	 
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf);  //%s refere-se a string, salva (armazena) dentro dela, q � do cpf, funciona pq foi inclu�da uma biblioteca pra ela
	
	strcpy(arquivo, cpf);  //respons�vel por copiar os valores das string, copiou o valor do cpf na vari�vel arquivo (strcpy � uma fu��o q copia o valor das vari�veis com string)
	
	FILE *file;  // cria o arquivo e "w" significa escrever, no banco de dados
	file = fopen(arquivo, "w");  //cria o arquivo, escreve, comando file equivale a abrir a vari�vel arquivo e o "w" quer dizer escrever um arquivo novo
	fprintf(file,cpf);  //salva o valor da vari�vel cpf
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo criado na vari�vel arquivo, "a" de atualizar, acessar o q est� dentro
	fprintf(file,",");  // depois de aberto o arquivo ele salva a "," (nova informa��o) pra separar as informa��es dadas pelo usu�rio
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //pergunta ao usu�rio, coleta informa��o
	scanf("%s", nome);   //armazena na string e na vari�vel nome
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza 
	fprintf(file,nome); //salva o conte�do da vari�vel nome dentro do arquivo
	fclose(file);   //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo criado na vari�vel arquivo, "a" de atualizar, acessar o q est� dentro
	fprintf(file,",");  // depois de aberto o arquivo ele salva a "," (nova informa��o) pra separar as informa��es dadas pelo usu�rio
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: " );  //pergunta ao usu�rio, coleta informa��o
	scanf("%s", sobrenome);  //armazena na string e na vari�vel sobrenome
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza 
	fprintf(file,sobrenome);  //salva o conte�do da vari�vel sobrenome dentro do arquivo
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abriu o arquivo criado na vari�vel arquivo, "a" de atualizar, acessar o q est� dentro
	fprintf(file,",");  // depois de aberto o arquivo ele salva a "," (nova informa��o) pra separar as informa��es dadas pelo usu�rio
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //pergunta ao usu�rio, coleta informa��o
	scanf("%s", cargo);  //armazena na string e na vari�vel cargo
	
	file = fopen(arquivo, "a");   //abre o arquivo e atualiza 
	fprintf(file, cargo);  //salva o conte�do da vari�vel (string) cargo dentro do arquivo == cpf
	fclose(file);   //fecha o arquivo
	
	system("pause");  //o sistema fica parado
	
	
}

int consulta()
{
     setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
     
     char cpf[40];   // vari�vel/string
     char conteudo[200];   // vari�vel/string
     
     printf("Digite o cpf a ser consultado: ");  //pergunta ao usu�rio, coleta informa��o
     scanf("%s", cpf); //armazena na string e na vari�vel cpf
     
     FILE *file;  // FILE = acesse a pasta do arquivo
     file = fopen(cpf,"r");   //abra o arquivo cpf e leia ele "r"
     
     if(file == NULL)   //se n�o encontrar o arquivo cpf ou se o valor for nulo
     {
     	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");   //fala para o usu�rio
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)   //enquanto busca o conte�do das string e escreve, armazena at� 200 ou for nulo
	 {
	 	printf("\nEssas s�o as informa��es do usu�rio: ");   //fala para o usu�rio
	 	printf("%s", conteudo);  //salve na string conte�do
	 	printf("\n\n");   //pula 2 linhas
	 }
	 
	 system("pause");   //o sistema fica parado


}

int deletar()
{
	char cpf[40];    // vari�vel/string
	
	printf("Digite o cpf do usu�rio a ser deletado: ");   //pergunta ao usu�rio, coleta informa��o
	scanf("%s", cpf);  //armazena na string e na vari�vel cpf
	
	remove(cpf);  //fun��o q acessa a pasta principal e remove o arquivo
	
	FILE *file;  // FILE = acesse a pasta do arquivo
	file = fopen(cpf,"r");  //abra o arquivo cpf e leia ele "r"
	
	if(file == NULL)  //se o arquivo for igual a nulo, ou seja, ele n�o for encontrado
	{
		printf("O usu�rio n�o se encontra no sistema!\n");   //fala para o usu�rio
		system("pause");    //o sistema fica parado para o usu�rio ler a mensagem
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("### Cart�rio da Ebac ###\n\n");
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
	
     	   printf("### Cart�rio da Ebac ###\n\n"); //In�cio do menu
    	   printf("Escolha a op��o desejada do menu:\n\n");
     	   printf("\t1 - Registrar nomes\n");
    	   printf("\t2 - Consultar nomes\n");
    	   printf("\t3 - Deletar nomes\n\n"); 
    	   printf("\t4 - Sair do Sistema\n\n");
    	   printf("Op��o: "); //Fim do menu
	
    	   scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	   system("cls");  //respons�vel por limpar a tela
	
	
	       switch(opcao)   // in�cio da sele��o do menu
	       {   
	           case 1:
	           registro(); //chamada de fun��es
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
	           printf("Est� op��o n�o est� dispon�vel!\n");
	           system("pause");
	           break;  // fim da sele��o
	       	
	       
	       }
        }
    }
    
    else
       printf("Senha incorreta!");
}
