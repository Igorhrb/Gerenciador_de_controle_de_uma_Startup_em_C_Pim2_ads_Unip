#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define ANSI_COLOR_RED      "\x1b[31m"	//cria a cor vermelha
#define ANSI_COLOR_RESET   "\x1b[0m"	//cria a cor pradrao

char nome[200][50]; //variaveis de cadastro de pessoas
char email[200][50];
char cpf[200][50];
char idade[200][50];
char cadastrado[200][50];
char registro[200][50];
char funcao[200][50];

char resposta; //opção em char dos usuários

int op,opp;//variaveis de opções que o usuário pode escolhe

int j,i; //contadores

int validar(char l1[30],char l2[30]){ //validação de login e senha
	
	char log[30] = "admin"; //Denifição de administrador: possiveis gestores da startup
	char sen[30] = "admin123"; //login e senha do administrador
	
	char fun[30] = "funcionario"; //Definição de funcionario: possiveis empregados com menores autoridades (exemplo: secretaria responsavel por cadastro no sistema)
	char sfun[30] = "funci123"; //login e senha do funcionario
	
		if((strcmp(log,l1) == 0) && (strcmp(sen,l2) ==0)){ //comparação de parametro do usuário com o login administrador
			printf(ANSI_COLOR_RED"\n\t\tAdministrador do sistema Logado!\n"ANSI_COLOR_RESET);
			j=3;
			return menu(); //retorna menu de administrador e j=3
			}
			
		if((strcmp(fun,l1) == 0) && (strcmp(sfun,l2) ==0)){ //comparação de parametro do funcionario com o login funcionario
			printf(ANSI_COLOR_RED"\n\t\tFuncionario Logado!\n"ANSI_COLOR_RESET);
			j=2;
			return menufun(); //retorna menu de funcionario e j=2
		}
		else {
			system("cls"); 
			printf(ANSI_COLOR_RED"\n\t\tSenha incorreta, tente novamente: \n"ANSI_COLOR_RESET); //caso a senha esteja incorreta, retorne para a tela de login
			return main();
		}
	}
int main(void){ //função de login		
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\n----------------------------------------------------------------------------------\n\t\t"); 
	printf("\n\t\tBEM VINDO AO SISTEMA DE GERENCIAMENTO DA FREE-UP\n\n");
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("\n\t\tMenu de opções\n\n\t\t1-Login\n\n\t\t2-Fechar o programa\n\t\t");
	printf("\n\t\tInsira a opção: ");
	scanf("%s", &resposta);//captura a resposta do usuário
	system("cls");
	do{
		switch(resposta){
		case '1':	return inicio();//se a resposta for 1 entao passa para o menu de login

		case '2':	printf("\n\t\tSaindo do programa...\n\t\tObrigado por usar nosso software, até a proxima!\n\n");
				system("pause"); //se a resposta for 2 entao ele finaliza o programa
				return 0;

		default:	printf(ANSI_COLOR_RED"\n\t\tOpção errada, tente novamente"ANSI_COLOR_RESET);
				return main(); //se a reposta for diferente de 1 e 2 ele recarrega a função (a mesma tela)
	}
}while(resposta!=1 && resposta!=2); //enquanto a resposta for diferente de  1 e 2 ele recarrega a pergunta
}
void inicio(){
	char login[30]; //variaveis para login e senha
	char senha[30];
	
	printf("----------------------------------------------------------------------------------\n\n\t\t");   
	printf("Tela de login\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\n\n\n\t\tInforme seu login: "); //captura o login
	scanf("%s", &login);
	printf("\t\tInforme sua senha: "); //captura a senha
	fflush(stdin);
	for (i = 0;i<8;i++) { //conta até 8 digitos de senha e transforma em "*"
		senha[i] = getch();
		printf("*");
		}
	senha[i] = '\0';
   	printf("\n");
	system("cls");
	return validar(login, senha); //manda os parametros de login e senha para a função de validar
	}
void cadastro(){
	static int linha;
	char emprego1[20]= "segurança"; 
	char emprego2[20]= "secretária(o)";
	char emprego3[20]= "serviços gerais"; //lista de variaveis com os cargos da empresa
	char emprego4[20]= "gerente";
	char emprego5[20]= "gerente de marketing";
	do{ //cadastro de pessoa
		system("cls");
		printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
		printf("Tela de cadastro de pessoas\n\n\n----------------------------------------------------------------------------------\n\n\n");
		printf("\nDigite o nome completo: ");
		fflush (stdin); gets(nome[linha]); strlwr(nome[linha]); //capturar " " dos nomes
		printf("\nDigite o Email: ");
		scanf("%s", &email[linha]); //atribui o email para o campo email[i(linha)]
		printf("\nDigite o CPF: ");
		scanf("%s", &cpf[linha]); //atribui o cpf para o campo cpf[i(linha)]
		printf("\nDigite a idade: ");
		scanf("%s", &idade[linha]); //atribui a idade para o campo idade[i(linha)]
			do{	//se digitar um numero diferente de 1, 2, 3, 4 ou 5 entra no loop do while
				printf("\nDigite a opção referente ao emprego \n1- Segurança\n2- Secretária(o)\n3- Serviços Gerais\n4- Gerente\n5- Gerente de marketing\n");
				printf("\n\t\tInsira a opção: ");
				fflush(stdin);
				scanf("%s", &resposta);	
			switch(resposta){ //captura a opção que o usuário escolher e atribui a opção para a variavel resposta
		
			case '1':	strcpy(funcao[linha],emprego1); //adiciona segurança no scanf
					break;
			case '2':	strcpy(funcao[linha],emprego2); //adiciona secretaria no scanf
					break;
			case '3':	strcpy(funcao[linha],emprego3); //adiciona serviços gerais no scanf
					break;
			case '4':	strcpy(funcao[linha],emprego4); //adiciona gerente no scanf
					break;
			case '5':	strcpy(funcao[linha],emprego5); //adiciona gerente de marketing no scanf
					break;			
			default:	system("cls"); 
					printf("\nOpção invalida, tente novamente!\n");
			}
	}while(resposta!='1' && resposta!='2' && resposta!='3' && resposta!='4'&& resposta!='5'); 
	
		strcpy(cadastrado[linha], "1"); //registro de cadastro, caso o cadastro seja feito, ele recebe 1
		system("cls"); //limpa a tela
		printf("\n----------------------------------------------------------------------------------\n\n\t\t");  
		printf("Cadastro realizado com sucesso!\n\n");
		printf("----------------------------------------------------------------------------------\n\n\t\t");   
		printf("Digite 1 para continuar, ou qualquer tecla para voltar para o menu: ");
		printf("\n\t\tInsira a opção: ");
		scanf("%d", &op); //captura a opção
		linha++; //variavel linha recebe +1
		}while(op==1); //enquanto o usuário inserir 1 ele pode adicionar mais uma pessoa
			if(op!=1){
				system("cls");
				if(j==2){
					printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);	
					return menufun(); //se inserir qualquer numero ele retorna para o menu do funcionario caso ele esteja na conta de funcionario
				}else if(j==3){
					printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);
					return menu(); //caso ele nao esteja na conta de funcionario entao ele retorna para o menu de administrador
				}
			}
}
void menu(){
 	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu do Administrador\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\t\t1-Cadastrar pessoa\n\t\t2-Pesquisar pessoa\n\t\t3-Exibir pessoa\n\t\t4-Editar pessoa\n\t\t5-Excluir\n\t\t6-Deslogar\n\t\t7-Inicio\n\t\t8-Relatorios\n");
	printf("\n\t\tInsira a opção: ");
   	scanf("%s", &resposta);//captura a opção do usuário
   	system("cls");
   	switch(resposta){
		case '1':	return cadastro(); //executa o menu de cadastro (a tela de cadastro de pessoas)				
		case '2':	return pesquisa(); //executa a função pesquisa (o menu de pesquisa)		
		case '3':	return exibir(); //executa a função de exibição de pessoas criadas				
		case '4':	return edicao(); //executa a função de alterar algum dado de alguma pessoa cadastrada				
		case '5':	return excluir(); //executa a função exclusiva do administrador de excluir e retorna para o menu de exclusão		
  		case '6':	return inicio(); //executa a função de mostrar o inicio, alem de deslogar do sistema
       		case '7':	return main(); //executa a função de deslogar do sistema
		case '8':	return relatorio(); //executa a função de menu de relatorios
        	default:	system("cls");
      				printf(ANSI_COLOR_RED"\nOpção inválida, retornando para o menu... \n"ANSI_COLOR_RESET);	
        			return menu(); 	//retorna para a propria tela e informa que a opção escolhida foi a incorreta
	}
}
void menufun(){
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu do Funcionario\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\t\t1-Cadastrar pessoa\n\t\t2-Pesquisar pessoa\n\t\t3-Exibir pessoa\n\t\t4-Editar pessoa\n\t\t5-Deslogar\n\t\t6-Inicio");
	printf("\n\t\tInsira a opção: ");
	scanf("%s", &resposta);//recebe a opção escolhida pelo funcionario
	system("cls");
	switch(resposta){//função de menu do funcionario
		case '1':	return cadastro();//executa o menu de cadastro (a tela de cadastro de pessoas)
		case '2':	return pesquisa(); //executa a função pesquisa (o menu de pesquisa)
		case '3':	return exibir(); //executa a função de exibição de pessoas criadas	
		case '4':	return edicao(); //executa a função de alterar algum dado de alguma pessoa cadastrada	    
        	case '5':	return inicio(); //executa a função de mostrar o inicio, alem de deslogar do sistema    
    		case '6':	return main();	//executa a função de deslogar do sistema			    
  		default:	system("cls");
       				printf(ANSI_COLOR_RED"\nOpção inválida, retornando para o menu... \n"ANSI_COLOR_RESET);
       				return menufun(); //retorna para a propria tela e informa que a opção escolhida foi incorreta
	}
}
void relatorio(){ //funçao de relatorios de cadastros
int totalCa = 0; //inicia valendo 0 cadastrados
int totalEx = 0; //inicia valendo 0 excluidos

	char criado[200] = "1"; //variavel de parametro para comparar com os cadastros criados
	char excluido[200] = "3"; //variavel de parametro para comparar com os cadastros excluidos
	
		for(i=0;i<200;i++){ //cria um loop de 200 repetições com a posição i sendo o parametro variavel
		if(strcmp(cadastrado[i],criado)==0){ //se a comparação der certo ("1"="1" retornará 0, se retornar 0 ele acrescenta 1 para o totalCa e repete o loop
		totalCa++; //total cadastrado recebe +1
		
		}else if(strcmp(cadastrado[i],excluido)==0){ //se a comparação der certo ("0"="0" retornará 0, se retornar 0 ele acrescenta 1 para o totalEx e repete o loop
		totalEx++;//total excluido recebe +1
		
		}else{
			printf(ANSI_COLOR_RED"\nTotal de pessoas cadastradas no sistema durante a execução do programa: %d\n"ANSI_COLOR_RESET,totalCa); 
			//imprime na tela usando totalCa de parametro para exibir o total de pessoas cadastradas em numero
			printf(ANSI_COLOR_RED"\nTotal de pessoas deletadas do sistema durante a execução do programa: %d\n"ANSI_COLOR_RESET,totalEx); 
			//imprime na tela usando totalCa de parametro para exibir o total de pessoas cadastradas em numero
			printf("\n\nRetornando para o menu principal...\n\n"); 
			//depois de mostrar quantas pessoas estao no sistema (cadastradas ou excluidas), ele retorna para o menu de administrador
			return menu();
		}
	
	}

}
void pesquisa(){ //função de pesquisar
	int idadePesquisa; 
	char emailPesquisa[50];
	char cpfPesquisa[50]; //variaveis para guardar a informação que o usuário inserir
	char nomePesquisa[50];
	char funcaoPesquisa[50];
	
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu de Pesquisa de pessoas cadastradas\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\n 1- Para pesquisar por email\n 2- Para pesquisar por CPF\n 3- Menu \n");
	printf("\n\t\tInsira a opção: ");
	scanf("%s", &resposta);
	switch(resposta){
	case '1':	system("cls");
			printf("\nDigite E-mail: "); 
			scanf("%s", &emailPesquisa); 
			for(i=0;i<200;i++){	//o email que o usuário inserir é comparado com os 200 espaços para email no sistema
				if(strcmp(email[i],emailPesquisa) == 0){ //caso exista um email igual ao inserido pelo usuário, sera impresso na tela a pessoa com o email igual ao inserido
					printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s\n\n", nome[i], email[i], cpf[i], idade[i],funcao[i]);
					return pesquisa(); //e depois de imprimir na tela a busca, ele retorna para o menu de pesquisam e tem a opção de escolher de novo
				}else{
					printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
					return pesquisa(); //caso não encontre nada igual, ele retorna para o menu de pesquisa
				}
			}	
	case '2':	system("cls");
			printf("\nDigite o CPF: ");
			scanf("%s", &cpfPesquisa);
			for(i=0;i<200;i++){ //o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
				if(strcmp(cpf[i],cpfPesquisa) == 0){ //caso exista um cpf igual ao inserido pelo usuário, sera impresso na tela a pessoa com o cpf igual ao inserido
					printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s\n\n", nome[i], email[i], cpf[i], idade[i],funcao[i]); 
					return pesquisa(); //e depois de imprimir na tela a busca, ele retorna para o menu de pesquisam e tem a opção de escolher de novo
				}else{
					system("cls");
					printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
					return pesquisa();	//caso não encontre nada igual, ele retorna para o menu de pesquisa
				}
			}
	case '3':	if(j==2){ //caso j estiver valendo 2, retornará para o menu de funcionario
				system("cls");
				printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);
				return menufun();
			}else if(j==3){ //caso j estiver valendo 3, retornará para o menu de administrador
				system("cls");
				printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);
				return menu();
			}
				default:	system("cls"); 
						printf(ANSI_COLOR_RED"\nOpção inválida, retornando para o menu de pesquisa... \n"ANSI_COLOR_RESET);
						return pesquisa();	//caso inserir algo diferente cairá de novo no menu de pesquisa
			}
}
void exibir(){
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Exibindo todas as pessoas cadastradas no sistema\n\n\n----------------------------------------------------------------------------------\n\n\n");
	char cadastrocmp[200] = "1"; //variavel para comparar
	for(i=0;i<200;i++){
		if(strcmp(cadastrado[i],cadastrocmp)==0){ //compara se o cadastro esta valendo 1 (que significa cadastrado)
			printf(	"Nome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s\n\n\n----------------------------------------------------------------------------------\n\n\n", nome[i], email[i], cpf[i], idade[i],funcao[i]);
			} //caso encontre algum cadastro que tenha valor 1, printa na tela a pessoa com todos os seus dados
		}
	printf("----------------------------------------------------------------------------------\n\n\n\t\t"); 
	printf("Insira qualquer número para voltar para o menu principal ");
	printf("\n\t\tInsira a opção: ");
	scanf("%d", &opp);
	if(opp!=""){ //se for inserido no scanf qualquer valor, a tela será limpa e retornará o seu menu correspondente à conta logada
		system("cls");
		if(j==2){
			printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);
			return menufun();
		}else if(j==3){
			printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);	
			return menu();
			}
			}
}
void edicao(){
	//variaveis do tipo char para armazenar a alteração do nome, email,cpf,idade ou cargo na empresa
	char nomeEditar[200][50]; 
	char emailEditar[200][50];
	char cpfEditar[200][50];
	char idadeEditar[200][50];
	char funcaoEditar[200][50];
	
	//listas de variaveis com os cargos da empresa
	char emprego1[20]= "segurança";
	char emprego2[20]= "secretária(o)";
	char emprego3[20]= "serviços gerais";
	char emprego4[20]= "gerente";
	char emprego5[20]= "gerente de marketing";
		 
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");
	printf("Menu de Edição\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\n\t\tO que deseja alterar\n\t\t1- Nome\n\t\t2- E-mail\n\t\t3- CPF\n\t\t4- Idade\n\t\t5- Função na empresa\n\t\t6- Menu\n ");
	printf("\n\t\tInsira a opção: ");
	scanf("%s", &resposta);
	do{ //enquanto a resposta for diferente de 1, 2, 3, 4, 5 ou 6 a função menu de edição será chamada novamente
	switch(resposta){
		case '1':	printf("\nDigite o CPF da pessoa que deseja alterar\n"); //caso a resposta for 1 pedirá um cpf para ser comparado com um cpf ja existente
				printf("\nInsira o CPF:");
				scanf("%s", &cpfEditar);//recebe a infromação e atribui para variavel cpfEditar
				system("cls");
				for(i=0;i<200;i++){ //o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){ //se encontrar um cpf igual, será printado a pessoa referente a posição do cpf comparado
						system("cls");
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s\n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						printf("----------------------------------------------------------------------------------\n\t\t");   
						printf("\nQual o nome para alterar: ");
						scanf("%s", nome[i]); //após ter validado os dados, o nome inserido vai substituir o nome que foi informado anteriormente
						system("cls");
						printf("\nA alteração ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao(); //printa a pessoa com os dados dela e retorna para o menu de edição
					}else{
						printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao(); //caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela 
						}
					}
	
		case '2':	printf("\nDigite o CPF da pessoa que deseja alterar\n");
				printf("\nInsira o CPF:");
				scanf("%s", &cpfEditar);
				system("cls");
				for(i=0;i<200;i++){//o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s\n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						printf("----------------------------------------------------------------------------------\n\t\t");   
						printf("\nQual o email para alterar: ");
						scanf("%s", email[i]);//após ter validado os dados, o email inserido vai substituir o email que foi informado anteriormente
						system("cls");
						printf("\nA alteração ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao(); //após alterar, retorna para o menu de edição
					}else{
						printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela
						}
						}
		
		case '3':	printf("digite o CPF da pessoa que deseja alterar\n");
				printf("\nInsira o CPF:");
				scanf("%s", cpfEditar);
				system("cls");
				for(i=0;i<200;i++){//o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){//o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s\n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						printf("----------------------------------------------------------------------------------\n\t\t"); 		
						printf("\nQual o email para alterar: ");
						scanf("%s", cpf[i]); //após ter validado os dados, o cpf inserido vai substituir o cpf que foi informado anteriormente
						system("cls");
						printf("\nA alteração ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao(); //após alterar, retorna para o menu de edição
					}else{
						printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela
					}
					}
		case '4':	printf("\nDigite o CPF da pessoa que deseja alterar\n");
				printf("\nInsira o CPF:");
				scanf("%s", &cpfEditar);
				system("cls");
				for(i=0;i<200;i++){//o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){ //função de comparar cpf
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \n", nome[i], email[i], cpf[i], idade[i]);
						printf("----------------------------------------------------------------------------------\n\t\t");   
						printf("\nQual a idade para alterar: ");
						scanf("%s", idade[i]); //transforma o que o usuario inserir para idade da pessoa cadastrada
						system("cls");
						printf("\nA alteração ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao();//caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela
					}else{
						printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela
					}
					}
		case '5':	printf("\nDigite o CPF da pessoa que deseja alterar\n");
				printf("\nInsira o CPF:");
				scanf("%s", &cpfEditar);
				system("cls");
				for(i=0;i<200;i++){//o cpf que o usuário inserir é comparado com os 200 espaços para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){ //função de comparar cpf
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						printf("----------------------------------------------------------------------------------\n\t\t"); 
					do{
						printf("\nDigite a opção referente ao emprego \n1- Segurança\n2- Secretária(o)\n3- Serviços Gerais\n4- Gerente\n5- Gerente de marketing\n");
						printf("\nInsira a opção: ");
						fflush(stdin);
						scanf("%s", &resposta);	 //recebe a resposta do usuario e se aplica em algum dos case e caso nao for igual as opçoes, cairá dentro do default
						switch(resposta){
						case '1':	strcpy(funcao[i],emprego1); //função de inserir emprego 1 para a string de funcao(cargo na empresa)
								break;
						case '2':	strcpy(funcao[i],emprego2); //função de inserir emprego 2 para a string de funcao(cargo na empresa)
								break;
						case '3':	strcpy(funcao[i],emprego3); //função de inserir emprego 3 para a string de funcao(cargo na empresa)
								break;
						case '4':	strcpy(funcao[i],emprego4); //função de inserir emprego 4 para a string de funcao(cargo na empresa)
								break;
						case '5':	strcpy(funcao[i],emprego5); //função de inserir emprego 5 para a string de funcao(cargo na empresa)
								break;
						default:	system("cls"); //caso a opção inserida nao exista ele retornará a perguntar
								printf("\nOpção invalida, tente novamente!\n");
					}
					}while(resposta!='1' && resposta!='2' && resposta!='3' && resposta!='4'&& resposta!='5');
						system("cls");
						printf("\nA alteração ficou \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao();//depois da alteração ser concluida, ela aparecerá na tela e retornará para o menu de função de editar
					}else{
						printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela
					}
					}
		case '6':	if(j==2){ //função de reotrnar ao menu
					system("cls");
					printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);
					return menufun();//caso j for igual a 2 ele retorna para o menu de funcionario
				}else if(j==3){
					system("cls");
					printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);
					return menu();//caso j for igual a 3 ele retorna para o menu de administrador
					}
	
		default:	system("cls");
				printf(ANSI_COLOR_RED"\nOpção invalida, digite novamente \n"ANSI_COLOR_RESET);
				return edicao();//caso as comparações não encontrem nada no sistema a tela de edição será retornada na tela
		}
	}while(resposta!='1' && resposta!='2' && resposta!='3' && resposta!='4'&& resposta!='5' && resposta!='6');
	}
void excluir(){ //função de excluir
	char emailExcluido[200][50];
	char nomeExcluido[200][50];
	char cpfExcluido[200][50];
	
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu de Exclusão\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("1- Exclusão por E-mail\n2- Exclusão por nome\n3- Exclusão por CPF\n4- Menu\n");
	printf("\nInserir opção: ");
	scanf("%s", &resposta); //atribui a opção que o usuario escolher para a variavel resposta
	printf("\n");
	switch(resposta){ 
		case '1':	system("cls"); //opção de exclusão por email
				printf("\t\tE-mail da pessoa que será excluida: ");
				printf("\n\t\tInsira o e-mail: "); 
				scanf("%s", &emailExcluido); //atribui o email digitado para o campo emailExcluido
				for(i=0;i<200;i++){ //o email que o usuario inserir é comparado com os 200 espaços para email no sistema
					if(strcmp(email[i],emailExcluido[i]) == 0){ //caso exista um email igual ao inserido pelo usuario, sera impresso na tela os dados da pessoa com o email igual ao inserido
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s", nome[i], email[i], cpf[i], idade[i],funcao[i]);
						printf("\n\nQuer excluir essa pessoa\n1- Sim \n2- Não\n");
						scanf("%d", &opp); //captura a opção escolhida "sim" ou "não"
						if(opp==1){ //caso a escolha seja "sim"
							strcpy(cadastrado[i], "3");
							system("cls");
							printf("\nExcluido com sucesso!\nRetornando para o menu de exclusão\n");
							return excluir(); //retorna ao menu de exclusão após ter excluido a pessoa com sucesso
						}else{ //caso a escolha seja "não"
							system("cls");
							printf("\nExclusão cancelada, retornando para o menu...\n\n");
							return excluir(); //retorna ao menu de exclusão após o cancelamento da exclusão
							}
						}else{ //caso não encontre o email
							printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
							return excluir();//retorna ao menu de exclusão após não ter encontrado o email
						}
					}
		
		
		case '2': 	system("cls"); //opção de exclusão por nome
				printf("\t\tNome e sobrenome da pessoa que será excluida");
				printf("\n\t\tInsira o nome e sobrenome: ");
				scanf("%s", &nomeExcluido);	//atribui o nome digitado para o campo nomeExcluido
				for(i=0;i<200;i++){ //o nome que o usuario inserir é comparado com os 200 espaços para nome no sistema
					if(strcmp(nome[i],nomeExcluido[i]) == 0){ //caso exista um nome igual ao inserido pelo usuario, sera impresso na tela os dados da pessoa com o nome igual ao inserido
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s", nome[i], email[i], cpf[i], idade[i],funcao[i]);
						printf("\n\nQuer excluir essa pessoa\n1- Sim \n2- Não\n");
						scanf("%d", &opp); //captura a opção escolhida "sim" ou "não"
						if(opp==1){ //caso a escolha seja "sim"
							printf("\nExcluindo essa pessoa...\n");
							strcpy(cadastrado[i], "3");
							system("cls");
							printf("\nExcluido com sucesso!\nRetornando para o menu de exclusão\n");
							return excluir(); //retorna ao menu de exclusão após ter excluido a pessoa com sucesso
							}else{ //caso a escolha seja "não"
								system("cls");
								printf("\nExclusão cancelada\nRetornando para o menu de exclusão...\n");
								return excluir(); //retorna ao menu de exclusão após o cancelamento da exclusão
								}
					}else{ //caso não encontre o nome
						printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return excluir(); //retorna ao menu de exclusão após não ter encontrado o nome
							}
					}
		
		case '3':	system("cls"); //opção de exclusão por cpf
				system("cls");	
				printf("\t\tCPF da pessoa que será excluida: ");
				printf("\n\t\tInsira CPF: ");
				scanf("%s", &cpfExcluido); //atribui o cpf digitado para o campo cpfExcluido
				for(i=0;i<200;i++){ //o cpf que o usuario inserir é comparado com os 200 espaços para cpf no sistema
					if(strcmp(cpf[i],cpfExcluido[i]) == 0){ //caso exista um cpf igual ao inserido pelo usuario, sera impresso na tela os dados da pessoa com o cpf igual ao inserido
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFunção: %s", nome[i], email[i], cpf[i], idade[i],funcao[i]);
						printf("\n\nQuer excluir essa pessoa\n1- Sim \n2- Não\n");
						scanf("%d", &opp); //captura a opção escolhida "sim" ou "não"
						if(opp==1){ //caso a escolha seja "sim", o cadastro da pessoa passa a valer 3 e some do sistema
							printf("\nExcluindo essa pessoa...\n");
							strcpy(cadastrado[i], "3");
							system("cls");
							printf("\nExcluido com sucesso!\nRetornando para o menu de exclusão\n");
							return excluir();	
							}else{ //caso a escolha seja "não"
								system("cls"); 
								printf("\nExclusão cancelada\nRetornando para o menu de exclusão...\n");
								return excluir(); //retorna ao menu de exclusão após o cancelamento da exclusão
							}
						}else{ //caso não encontre o cpf
							printf(ANSI_COLOR_RED"\n\n***************Não encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
							return excluir(); //retorna ao menu de exclusão após não ter encontrado o cpf
						}
				}
				
		case '4':	system("cls"); //opção de limpar a tela e retornar menu do administrador
                  		return menu();
                  
		default:	system("cls"); //caso seja escolhida uma opção diferente das permitidas, limpa a tela e informa que foi inválida a opção
                 		printf("Opção inválida, digite novamente \n");
                	 	return excluir(); //retorna o mesmo menu apos printar na tela a opção inválida
		}
}
