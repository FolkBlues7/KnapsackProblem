#include "binario.h"

int ligarBit(int valor, int bit_escolhido)
{
	return  valor | (1 << (bit_escolhido - 1)); // 1 = 0000'0000'0000'0001
}

int desligarBit(int valor, int bit_escolhido)
{
	int mascara = 1 << (bit_escolhido -1);// 1 = 0000'0000'0000'0001
	return valor & ~mascara;
}

bool testarBit(int valor, int bit_escolhido)
{
	
	int mascara = 1 << (bit_escolhido - 1);
	return  (valor & mascara) == 0;
    	
}

int ANDbinario(int valor_1, int valor_2) {
		return valor_1 & valor_2;
}

int ORbinario(int valor1, int valor2)
{
	return valor1 | valor2;
	}

int Bbaixo(int valor1)
{
	return valor1 & 255; //225 = 0000 0000 1111 1111
}



int Balto(int valor) {
	return valor & 65280; // 65290 = 1111 1111 0000 0000;
}

int trocaBit(int valor, int indiceBit) {
		     bool ligado = testarBit(valor, indiceBit);
		        if (ligado) {
			         return ligarBit(valor, indiceBit);
			
		}
		     return desligarBit(valor, indiceBit);
		
	}






