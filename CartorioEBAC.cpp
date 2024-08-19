#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char arquivo[40]; //início das variáveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //final das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação
	scanf("%s", cpf); //%s é referente as strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa write (escrever)
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ", "); //adiciona uma virgula
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação
	scanf("%s", nome); //%s referente a strings
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aquivo para atualizar ("a")
	fprintf(file, " "); //adiciona um espaço
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação
	scanf("%s",sobrenome); //%s de string
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file,sobrenome);  //salva o valor na variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file, ", "); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação
	scanf("%s",cargo); //%s de string
	
	file = fopen (arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file,cargo); //salva o valor na variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar ("a")
	fprintf(file, "."); //adiciona um ponto
	fclose(file); //fecha o arquivo
	
	system("pause"); //comando para pausar a tela e dar tempo ao usuário
}

int consulta() //função responsável pela consulta
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//inicio das variáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim das variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s é referente a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo para ler, "r" de read 
	
	if(file == NULL) //condição se arquivo for nulo
	{
		printf("\nArquivo não localizado!\n\n"); //retorno ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //se a condição for contraria
	{
		printf("\nEssas são as informações do usuário: "); //retorno ao usuário
		printf("%s", conteudo); //acesso ao conteudo
		printf("\n\n");	//espaço 
	}
	
	fclose(file);
	system("pause"); //pausa para dar tempo ao usuário ler
}

int deletar() //função responsável por deletar os arquivos
{
	char cpf[40]; //string 
	
	printf("Digite o CPF a ser deletado: "); //mensagem visível para o usuário
	scanf("%s",cpf); 
	
	remove(cpf); //comando para deletar o que foi solicitado
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário inexistente!\n\n"); //mensagem após deletar o arquivo
		system("pause");
	}
}


int main()
{
	int opcao=0;//definindo variável
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//limpar o menu
	
		setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
		//início do menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		//final do menu
	
		scanf("%d", &opcao);//armazenando o comando do usuário
	
		system("cls");//limpar o menu após o usuário escolher uma opção
		
		
		switch(opcao)
		{//inicio da seleção
			case 1:
			registro(); //chamada de função registro
			break;
			
			case 2:
			consulta(); //chamada de função consulta
			break;
			
			case 3:
			deletar(); //chamada de função deletar
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n");
			system("pause");
			break;
			//fim da seleção				
		}
	}	
}
