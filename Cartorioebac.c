#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro()// Função responsável por cadastrar os usuarios no sistema

{
	//inicio criação de variaveis/string (cpf, nome, sobrenome e cargo)
	setlocale(LC_ALL, "Portuguese"); //define a linguagem para portugues
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario (cpf)
	scanf("%s", cpf); //permite que o usuário insira uma string e armazene o os dados na variável "nome"

	strcpy(arquivo, cpf);//copia os valores das string
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo e insere armazenados no "arquivo"
	fprintf(file,cpf);//salva o valor da variavel da string cpf
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo podendo adicionar mais informações nele
	fprintf(file,","); //adiciona a virgula e salva o arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //pede a coleta a informação do usuario (nome)
	scanf("%s",nome); //permite que o usuário insira uma string e armazene o os dados na variável "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo podendo adicionar mais informações nele
	fprintf(file,nome);//salva o valor da variavel da string nome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo podendo adicionar mais informações nele
	fprintf(file,",");//adiciona a virgula e salva o arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//pede a coleta a informação do usuario (sobrenome)
	scanf("%s",sobrenome);//permite que o usuário insira uma string e armazene o os dados na variável "sobrenome"

	file = fopen(arquivo, "a");//abre o arquivo podendo adicionar mais informações nele
	fprintf(file,sobrenome);//salva o valor da variavel da string sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo podendo adicionar mais informações nele
	fprintf(file,",");//adiciona a virgula e salva o arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//pede a coleta a informação do usuario (cargo)
	scanf("%s",cargo);//permite que o usuário insira uma string e armazene o os dados na variável "cargo"
	
	file = fopen(arquivo, "a");//abre o arquivo podendo adicionar mais informações nele
	fprintf(file,cargo);//salva a variavel da string cargo
	fclose(file);//fecha o arquivo
	
	system("pause"); //pauda o programa até o usuario pressionar qualquer tecla para continuar
	}

int consulta()// Função responsável por consultar os usuarios no sistema
{
	//inicio criação de variaveis/string (arquivo, cpf e conteudo)
	setlocale(LC_ALL, "Portuguese");//define a linguagem para portugues
	char arquivo[40];
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	 } 
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("o usuário não se encontra no sistema.\n");
	system ("pause");

	}
	
}


int main ()
{
	int opcao=0; //definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada o menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\nEsse software é de estudo da Luna ;)\n");
			printf("Opção: ");//fim do menu
	
	scanf("%d", &opcao);//armazenando a escolha do usuario
	
	system("cls");
	
		switch(opcao)
		{
			case 1:	
			registro();
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
			printf("Essa opção não está disponivel!");
			system("pause");
			break;
	}
	

	}
}
