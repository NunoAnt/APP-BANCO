#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defenições
#define FICHEIRO "bd.dat"

/*	Função: Registar Contas
	Autor: AMIPCA
	Versão: 1.0
	 */

// estruturas
typedef struct conta
{
	char nome[30+ 1];
	char ccBI[15 + 1];
	int idade;
	int dataNascimento;
	int nif;
	int contacto;
	char pais[10 + 1];
	char morada[30 + 1];
	char codigoPostal[15 + 1];
	char estadoCivil[10 + 1];
	int numConta;
	int ativo;
	float saldo;
} Registar;

// declarar sub-rotinas
void GuardarTodos(Registar *contas, int n);
void MostraContasAtivas();
void GuardarEdicao(Registar *contas, int n, int indice);
float GetSaldo(Registar *contas, int numConta);
int GetIndice(Registar *contas, int numConta);

// subrotinas para executar procedimentos no Menu
void RegistarContas();
void EditarClientes();
void Levantamentos(Registar *contas);

int main(int argc, char *argv[]) {
	
	// declarar variaveis
	int opcao;
	Registar contas;
	
	// Apresentação do Ecra Principal
	printf("============ APLICACAO OLD BANK ===============\n\n");
	printf("=== Escolha uma Opcao ===\n\n");
	printf("1 - Registar Contas\n");
	printf("\t11 - Contas Activas\n");
	printf("\t12 - Editar Contas\n");
	printf("2 - Emprestimos\n");
	printf("3 - Levantamentos\n");
	printf("4 - Depositos\n");
	printf("5 - Transferencias\n");
	printf("6 - Pagamento de Servicos\n");
	printf("7 - Pedir Cheques\n");
	printf("8 - Carregar Telemoveis\n");
	printf("9 - Marketing\n\n");
	
	printf("Insira a sua opcao: ");
	scanf("%d", &opcao);
	
	// decidir a opção
	switch (opcao)
	{
		case 1:
				// apresentar contas activas
				RegistarContas();
				break;
		case 11:
				// apresentar contas activivas		
				MostraContasAtivas();
				break;
		case 12:
				// editar clientes
				EditarClientes();
				break;
		case 3:
			Levantamentos(&contas);
			break;
		case 4:
			
		case 5:
			
		case 6:
			
		case 7:
			
		case 8:
			
		case 9:
			
		case 10:
		
		default:
			printf("Categoria nao prevista");
			break;
	}
	
	// pausa
	getchar();

}

void RegistarContas()
{
	// declaracao de variaveis
	Registar contas;
	
	
		// solicitar dados ao utilizador
		printf("\n\n======= REGISTAR CONTA ===========\n");
		printf("by AMIPCA");
		printf("\n\n");
	
		// recolher informação para os campos do registo
		fflush(stdin);
		printf("Insira o Nome: ");
		gets(contas.nome);
		fflush(stdin);
		printf("Insira o BI: ");
		gets(contas.ccBI);
		fflush(stdin);
		printf("Insira a Idade: ");
		scanf("%d", &contas.idade);
		fflush(stdin);
		printf("Insira a Data de Nascimento: ");
		scanf("%d", &contas.dataNascimento);
		fflush(stdin);
		printf("Insira o NIF: ");
		scanf("%d", &contas.nif);
		fflush(stdin);
		printf("Insira o Contacto: ");
		scanf("%d", &contas.contacto);
		fflush(stdin);
		printf("Insira o Pais: ");
		gets(contas.pais);
		printf("Insira a Morada: ");
		gets(contas.morada);
		printf("Insira o Cogigo Postal: ");
		gets(contas.codigoPostal);
		printf("Insira o Estado Civil: ");
		gets(contas.estadoCivil);
		printf("Insira o Numero da Conta: ");
		scanf("%d", &contas.numConta);
		fflush(stdin);
		printf("Insira o Montante da Conta: ");
		scanf("%f", &contas.saldo);
		fflush(stdin);
		printf("Insira a Activacao da Conta 1 - SIM / 0 - NAO: ");
		scanf("%d", &contas.ativo);
		
		// verificar idade e sai do programa
		if (contas.idade > 65)
		{
			printf("\nNao e possivel criar conta no OLD BANK a idade e superior ao premitido");
			return;
		}
	
		// gravar dados
		GuardarTodos(&contas, 1);
		
		// Apresentar Mensagem que o Registo foi efectuado
		printf("\nO Registo foi efectuado com sucesso!");
		
}

// esta função premite editar clientes
void EditarClientes()
{
		// declarar variaveis
		int numConta, indice;
		Registar contas;
		
		// recolher conta que pretende editar
		printf("Insira o Numero da conta que pretende editar: ");
		scanf("%d", &numConta);
	
		// recolher indice da conta
		indice = GetIndice(&contas, numConta);
		
		// recolher o montante da conta
		contas.saldo = GetSaldo(&contas, numConta);
	
		// solicitar dados ao utilizador
		printf("\n\n======= EDITAR CONTA ===========\n");
		printf("by AMIPCA");
		printf("\n\n");
	
		// recolher informação para os campos do registo
		fflush(stdin);
		printf("Insira o Nome: ");
		gets(contas.nome);
		fflush(stdin);
		printf("Insira o BI: ");
		gets(contas.ccBI);
		fflush(stdin);
		printf("Insira a Idade: ");
		scanf("%d", &contas.idade);
		fflush(stdin);
		printf("Insira a Data de Nascimento: ");
		scanf("%d", &contas.dataNascimento);
		fflush(stdin);
		printf("Insira o NIF: ");
		scanf("%d", &contas.nif);
		fflush(stdin);
		printf("Insira o Contacto: ");
		scanf("%d", &contas.contacto);
		fflush(stdin);
		printf("Insira o Pais: ");
		gets(contas.pais);
		printf("Insira a Morada: ");
		gets(contas.morada);
		printf("Insira o Cogigo Postal: ");
		gets(contas.codigoPostal);
		printf("Insira o Estado Civil: ");
		gets(contas.estadoCivil);
		printf("Insira a Activacao da Conta 1 - SIM / 0 - NAO: ");
		scanf("%d", &contas.ativo);
		
		// inserir os valores que nao podem ser editados
		contas.numConta = numConta;
		
		// verificar idade e sai do programa
		if (contas.idade > 65)
		{
			printf("Nao e possivel editar a conta no OLD BANK a idade e supeor ao premitido");
			return;
		}
	
		// gravar dados
		GuardarEdicao(&contas, 1, indice);
		
		// Apresentar Mensagem que o Registo foi efectuado
		printf("O Registo foi editado com sucesso!");
}

// mostra dados existentes neste momento no ficheiro
void MostraContasAtivas()
{
	// declarar variaveis
	FILE *ficheiro;
	Registar conta;
	
	//  tentar abrir ficheiro
	ficheiro = fopen(FICHEIRO, "rb");
	
	// se não for possivel abrir o ficheiro, mostrar erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não  foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}
	
	// posicionar o inicio do ficheiro
	rewind(ficheiro);
	
	// inicio da listagem
	printf("\n ====== CONTAS REGISTADAS =========\n");
	printf("NUM DE CONTA          NOME DO TITULAR\n");
	
	// ler ficheiro
	while (fread(&conta, sizeof(Registar), 1, ficheiro) == 1)
	{
		// verifica se a conta esta activa
		if (conta.ativo = 1)
		{
			// mostrar na consola o contudo de <contas registadas> atual
			printf("%06d \t\t %s\n", conta.numConta, conta.nome);
		}
	}
	
	// fechar o ficheiro
	fclose(ficheiro);
	
	// fim da listagem
	printf("\n===== FIM ====== ");	
}

// esta função recebe um cliente e grava-o na base de dados
void GuardarTodos(Registar *contas, int n)
{
	// variaveis
	FILE *ficheiro;
	int i;
	
	// abrir o documento
	ficheiro = fopen(FICHEIRO, "a+b");
	
	// se não for possivel abrir o ficheiro (por exemplo: problema de premissões), mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não  foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}
	
	// meter o apontador no final do Ficheiro
	fseek(ficheiro, 0, SEEK_END);
	
	// gravar cada um dos clientes no final do ficheiro
	for (i = 0; i < n; i++)
	{
		
		// gravar os registos no ficheiro
		fwrite(&contas, sizeof(Registar), 1, ficheiro);
	}
	
	// fechar o ficheiro
	fclose(ficheiro);
}

// esta funcao encontra a conta do indice
int GetIndice(Registar *contas, int numConta)
{
	// variaveis
	FILE *ficheiro;
	Registar conta;
	int indice = -1, i = -1;
	
	// tentar abrir o ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO, "rb");
	
	// se não for possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}
	
	// posicionar no incio do ficheiro
	rewind(ficheiro);
	
	// procurar o registo da edicao da conta
	while (fread(&contas, sizeof(Registar), 1, ficheiro) == 1)
	{
		// incrementar o contdor de registos
		i++;
		
		// econtrou a num de Conta pretendida
		if (conta.numConta = numConta)
		{
			indice = i;
			return;
		}
	}
	
	// fechar o ficheiro
	fclose(ficheiro);
	
	// retornar valor
	return indice;
}

// esta funcao encontra a conta e recolhe o montante
float GetSaldo(Registar *contas, int numConta)
{
	// variaveis
	FILE *ficheiro;
	Registar conta;
	int  saldo;
	
	// tentar abrir o ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO, "rb");
	
	// se não for possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}
	
	// posicionar no incio do ficheiro
	rewind(ficheiro);
	
	// procurar o registo da edicao da conta
	while (fread(&contas, sizeof(Registar), 1, ficheiro) == 1)
	{
		// econtrou a num de Conta pretendida
		if (conta.numConta = numConta)
		{
			saldo = conta.saldo;
			return;
		}
	}
	
	// fechar o ficheiro
	fclose(ficheiro);
	
	// retornar valor
	return saldo;
}

// esta funcao vai guardar a edição efectuada
void GuardarEdicao(Registar *contas, int n, int indice)
{
	// variaveis
	FILE *ficheiro;
	int i, posicaoFicheiro;
	
	// abrir o documento
	ficheiro = fopen(FICHEIRO, "rb");
	
	// se não for possivel abrir o ficheiro (por exemplo: problema de premissões), mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não  foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}
	
	// calcular a posicao do ficheiro
	posicaoFicheiro = sizeof(Registar) * indice;
	
	// meter o apontador no final do Ficheiro
	fseek(ficheiro, posicaoFicheiro, SEEK_SET);
	
	// gravar cada um dos clientes no final do ficheiro
	for (i = 0; i < n; i++)
	{
		
		// gravar os registos no ficheiro
		fwrite(&contas, sizeof(Registar), 1, ficheiro);
	}
	
	// fechar o ficheiro
	fclose(ficheiro);
}

// esta função vai realizar um levantamento
void Levantamentos(Registar *contas)
{
	// declarar variaveis
	int numConta, indice;
	float levantamento, total;
	FILE *ficheiro;
	Registar conta;
	
	// recolher o numero da conta
	printf("Insira o Numero da Conta: ");
	scanf("%d", &numConta);
	
	// recolher indice da conta
	indice = GetIndice(&conta, numConta);
	
	// recolher o valor que pretende levantar
	printf("Insira o valor que pretende Levantar: ");
	scanf("%f", &levantamento);
	
	// tentar abrir o ficheiro (r = leitura b = binario)
	ficheiro = fopen(FICHEIRO, "rb");
	
	// se não for possivel abrir o ficheiro, mostra erro e sai
	if (ficheiro == NULL)
	{
		printf("!!!não foi possivel abrir o ficheiro %s!!!\n", FICHEIRO);
		return;
	}
	
	// posicionar no incio do ficheiro
	rewind(ficheiro);
	
	// procurar o registo da edicao da conta
	while (fread(&contas, sizeof(Registar), 1, ficheiro) == 1)
	{
		// econtrou a num de Conta pretendida
		if (conta.numConta = numConta)
		{
			if (conta.saldo < levantamento)
			{
				// apresentar mensagem 
				printf("Nao foi pssivel realizar o levantamento");
			}
			
			// Apresentar valor do saldo antes do levantamento
			printf("O seu saldo antes do levantamento e: %f", conta.saldo);
			
			// retirar o dinheiro da conta do cliente
			conta.saldo = conta.saldo - levantamento;
			
			// Apresentar valor do saldo antes do levantamento
			printf("O seu saldo depois do levantamento era: %f", conta.saldo);
			
			return;
		}
	}
	
	// apresentar mensagem que o processo foi Finalizado
	printf("O levantamento foi efectuado com sucesso!");
	
}

