#include "genetico.h"
#include "binario.h"
#include <iostream>//usado para possibilitar o uso do COUT e CIN na fun��o de avalia��o
using namespace std;
#include <cstdlib> //usado para obter valores aleat�rios de 1 a 16 na muta��o
#include <time.h>  //usado para obter seed pro randomizer
#include <windows.h>

#define MASCARA_MAIOR 65280 //65280 em bin�rio = 1111111100000000
#define MASCARA_MENOR 255   //255   em bin�rio = 0000000011111111
#define MASCARA_mutacao_dupla 4104 //4104 em bin�rio = 0001000000001000


//Fun��o de avalia��o-----------------------------------------------------------
bool avaliacao(unsigned int v7)
{
	const int pesos[] = { 12, 3, 5, 4, 9, 1, 2, 3, 4, 1, 2, 4, 5, 2, 4, 1 };
	const int preco[] = { 4, 4, 8, 10, 15, 3, 1, 1, 2, 10, 20, 15, 10, 3, 4, 12 };
	unsigned int mascara;
	int peso_total = 0;
	int numero_avaliacao; //essa � a vari�vel do valor que ser� avaliado 
	int preco_total = 0;
	string pesos_OK_ou_X;
	
	cout << "Digite o valor para a avalia��o: \n";
	cin  >> numero_avaliacao;
	system("cls");


	peso_total = 0;
	for (int i = 0; i < 16; i++) {
		mascara = 1 << (15 - i); //MASCARA :)
		if ((numero_avaliacao & mascara) == mascara) {
			preco_total += preco[i];
			peso_total += pesos[i];	
		}
	}

	if (peso_total <= 20) {
		pesos_OK_ou_X = "\033[32mOK\033[0m\n";
	}
	else {
		pesos_OK_ou_X = "\033[31mX\033[0m\n";
	}


	cout << numero_avaliacao << "\t - " << "$" << preco_total << "\t- " << peso_total << "kg\t" << "-" << pesos_OK_ou_X << endl;


	if (peso_total <= 20) {
		return true;
	}
	else {
		return false;
	}
}	
	


//Fun��o de cruzamento ponto �nico----------------------------------------------
int cruzamento(unsigned int entrada_1, unsigned int entrada_2)
{
	unsigned int bits_maiores, 
		         bits_menores,
		         resultado_cruzamento;

	bits_maiores = Balto(entrada_1);
	bits_menores = Bbaixo(entrada_2);
	resultado_cruzamento = ORbinario(bits_maiores, bits_menores);
	
	return resultado_cruzamento;
}


//Fun��o de cruzamento aritm�tico-----------------------------------------------
int aritmetico(unsigned int entrada_3, unsigned int entrada_4)
{
	unsigned int resultado_aritmetico;
	resultado_aritmetico = ANDbinario(entrada_3, entrada_4); //operador AND

	return resultado_aritmetico;
}


//Fun��o de muta��o simples-----------------------------------------------------
int mutacao(unsigned int entrada_5)
{
	const int indice = 10;
	return trocaBit(entrada_5, indice);
}



//Fun��o de muta��o dupla-------------------------------------------------------
int mutacao_dupla(unsigned int entrada_6) 
{
	return entrada_6 ^ MASCARA_mutacao_dupla;
}
	


