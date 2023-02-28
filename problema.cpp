#include <iostream>
#include "genetico.h"
#include "binario.h"
#include <windows.h>
using namespace std;

//Declara��o das constantes
const int pesos[] = { 12, 3, 5, 4, 9, 1, 2, 3, 4, 1, 2, 4, 5, 2, 4, 1 };
const int preco[] = { 4, 4, 8, 10, 15, 3, 1, 1, 2, 10, 20, 15, 10, 3, 4, 12 };

int main() {
	SetConsoleCP(1252); //muda a p�gina do chcp para permitir o uso de acentua��o padr�o
	SetConsoleOutputCP(1252); //muda a p�gina do chcp para permitir o uso de acentua��o padr�o
	
	// declara��o dos 6 valores e do retorno das fun��es gen�ticas 
	unsigned int n1, n2, n3, n4, n5, n6,
		retorno_avaliacao,
		retorno_cruzamento,
		retorno_aritmetico,
		retorno_mutacao,
		retorno_mutacao_d;      

	
	

	//chamada teste dos 6 valores principais
	cout << "Entre com 6 solu��es iniciais (n�meros entre 0 e 65535):\n";
	cin  >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
	system("cls"); //limpa a tela ap�s entrarmos com os 6 valores


	retorno_cruzamento = cruzamento(n1, n2);//chamando fun��o de cruzamento(genetico.cpp)

	retorno_aritmetico = aritmetico(n3, n4);//chamando fun��o de cruzamento aritmetico(genetico.cpp)

	retorno_mutacao = mutacao(n5);//chamando fun��o de muta��o simples(genetico.cpp)
	
	retorno_mutacao_d = mutacao_dupla(n6);//chamando fun��o de muta��o dupla(genetico.cpp)
			
	
	
	
	
	
	//Declara��o das variaveis a serem utilizadas para a associa��o entre bit e peso
	//Algumas delas tamb�m ser�o utilizadas para a associa��o entre bit e valor, ent�o
	//n�o h� necessidades de repeti-las novamente
	
	unsigned int valores[10] = {n1, n2, n3, n4, n5, n6, 
		         retorno_cruzamento, retorno_aritmetico,
				 retorno_mutacao   , retorno_mutacao_d };
	unsigned int resultado_peso[10] = {};//O RESULTADO DOS PESOS � GUARDADO NESSE VETOR
	unsigned int mascara;
	int pesoTotal = 0;

	// FOR para BIT e PESO
	for (int j = 0; j < 10; j++) {
		pesoTotal = 0;
		for (int i = 0; i < 16; i++) {
			mascara = 1 << (15 - i); //MASCARA
			if ((valores[j] & mascara) == mascara) {
				pesoTotal += pesos[i];
			}
		}
		resultado_peso[j] = pesoTotal;//O RESULTADO DOS PESOS � GUARDADO NESSE VETOR
	}
	
	
	
	
	
	// Declara��o de variaveis para associa��o entre bit e valor, algumas das variaveis
	// utilizadas nesse FOR foram declaras na linha 43 a 48, ent�o n�o h� necessidade de
	// repeti-las
	unsigned int resultado_valor[10] = {};//O RESULTADO DOS VALORES � GUARDADO NESSE VETOR
	int valorTotal;
	// FOR para BIT e VALOR
	for (int j = 0; j < 10; j++) {
		valorTotal = 0;
		for (int i = 0; i < 16; i++) {
			mascara = 1 << (15 - i); //MASCARA
			if ((valores[j] & mascara) == mascara) {
				valorTotal += preco[i];
			}
		}
		resultado_valor[j] = valorTotal;//O RESULTADO DOS VALORES
	}
	

		
	
	
	
	//Esse FOR e IF fazem com que apare�a OK(verde) ou X(vermelho), caso os pesos estejam ou n�o dentro da capacidade
	//de peso da mochila
	string pesos_OK_ou_X[10] = {};
	for (int i = 0; i < 10; i++) {
		if (resultado_peso[i] <= 20) {
			pesos_OK_ou_X[i] = "\033[32mOK\033[0m\n";
		}
		else {
			pesos_OK_ou_X[i] = "\033[31mX\033[0m\n";
		}
	}
		





//Aqui fica a sess�o que mostrar� as informa��es na tela

	cout << "Resultado da Avalia��o" << endl;
	cout << "-----------------------" << endl; 
	cout << n1 << "\t - " << "$" << resultado_valor[0] << "\t- " << resultado_peso[0] << "kg\t" << "-" << pesos_OK_ou_X[0] << endl;
	cout << n2 << "\t - " << "$" << resultado_valor[1] << "\t- " << resultado_peso[1] << "kg\t" << "-" << pesos_OK_ou_X[1] << endl;
	cout << n3 << "\t - " << "$" << resultado_valor[2] << "\t- " << resultado_peso[2] << "kg\t" << "-" << pesos_OK_ou_X[2] << endl;
	cout << n4 << "\t - " << "$" << resultado_valor[3] << "\t- " << resultado_peso[3] << "kg\t" << "-" << pesos_OK_ou_X[3] << endl;
	cout << n5 << "\t - " << "$" << resultado_valor[4] << "\t- " << resultado_peso[4] << "kg\t" << "-" << pesos_OK_ou_X[4] << endl;
	cout << n6 << "\t - " << "$" << resultado_valor[5] << "\t- " << resultado_peso[5] << "kg\t" << "-" << pesos_OK_ou_X[5] << endl;
	cout << "-----------------------" << endl;
	cout << retorno_cruzamento << "\t - " << "$" << resultado_valor[6] << "\t- " << resultado_peso[6] << "kg\t" << "-" << pesos_OK_ou_X[6] << endl;
	cout << retorno_aritmetico << "\t - " << "$" << resultado_valor[7] << "\t- " << resultado_peso[7] << "kg\t" << "-" << pesos_OK_ou_X[7] << endl;
	cout << retorno_mutacao    << "\t - " << "$" << resultado_valor[8] << "\t- " << resultado_peso[8] << "kg\t" << "-" << pesos_OK_ou_X[8] << endl;
	cout << retorno_mutacao_d  << "\t - " << "$" << resultado_valor[9] << "\t- " << resultado_peso[9] << "kg\t" << "-" << pesos_OK_ou_X[9] << endl;
	
	
	return 0;
}