#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char arquivo[40]; //in�cio das vari�veis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o
	scanf("%s", cpf); //%s � referente as strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write (escrever)
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //adiciona uma virgula
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o
	scanf("%s", nome); //%s referente a strings
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aquivo para atualizar ("a")
	fprintf(file, " "); //adiciona um espa�o
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o
	scanf("%s",sobrenome); //%s de string
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file,sobrenome);  //salva o valor na vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file, ", "); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o
	scanf("%s",cargo); //%s de string
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file,cargo); //salva o valor na vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file, "."); //adiciona um ponto
	fclose(file); //fecha o arquivo
	
	system("pause"); //comando para pausar a tela e dar tempo ao usu�rio
}

int consulta() //fun��o respons�vel pela consulta
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio das vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//fim das vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s � referente a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo para ler, "r" de read 
	
	if(file == NULL) //condi��o se arquivo for nulo
	{
		printf("\nArquivo n�o localizado!\n\n"); //retorno ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se a condi��o for contraria
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //retorno ao usu�rio
		printf("%s", conteudo); //acesso ao conteudo
		printf("\n\n");	//espa�o 
	}
	
	fclose(file);
	system("pause"); //pausa para dar tempo ao usu�rio ler
}

int deletar() //fun��o respons�vel por deletar os arquivos
{
	char cpf[40]; //string 
	
	printf("Digite o CPF a ser deletado: "); //mensagem vis�vel para o usu�rio
	scanf("%s",cpf); 
	
	remove(cpf); //comando para deletar o que foi solicitado
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio inexistente!\n\n"); //mensagem ap�s deletar o arquivo
		system("pause");
	}
}


int main()
{
	int opcao=0;//definindo vari�vel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//limpar o menu
	
		setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
		//in�cio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		//final do menu
	
		scanf("%d", &opcao);//armazenando o comando do usu�rio
	
		system("cls");//limpar o menu ap�s o usu�rio escolher uma op��o
		
		
		switch(opcao)
		{//inicio da sele��o
			case 1:
			registro(); //chamada de fun��o registro
			break;
			
			case 2:
			consulta(); //chamada de fun��o consulta
			break;
			
			case 3:
			deletar(); //chamada de fun��o deletar
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
			//fim da sele��o				
		}
	}	
}
