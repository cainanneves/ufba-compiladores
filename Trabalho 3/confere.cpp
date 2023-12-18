#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

int main(){
	FILE* saida = fopen("diff.txt", "w");
	int conta = 0;
	for (int num = 1; num<=1000; num++){
		string nome_arq = "teste/";
		string meu_arq = nome_arq;


		string n = "";

		if (num<10){
			n += num+'0';
			nome_arq += "000" + n;
			meu_arq += n;
		} else if (num<100){
			n += (num/10)+'0';
			n += (num%10)+'0';
			nome_arq += "00" + n;
			meu_arq += n;
		} else if (num<1000){
			n += (num/100)+'0';
			n += ((num%100)/10)+'0';
			n += (num%10)+'0';
			nome_arq += "0" +  n;
			meu_arq += n;
		} else {
			n = "1000";
			nome_arq += n;
			meu_arq += n;
		}

		nome_arq += ".out";

		FILE* correto = fopen(nome_arq.c_str(), "r");
		FILE* meu = fopen(meu_arq.c_str(), "r");

		char aux1[4];
		char aux2[4];
		char aux3[4];
		char aux4[4];
		char aux5[4];
		char aux6[4];
		char aux7[4];
		char aux8[4];
		char aux9[4];
		char aux10[4];

		fgets(aux1, 4, correto);
		fgets(aux2, 4, correto);
		fgets(aux3, 4, correto);
		fgets(aux4, 4, correto);
		fgets(aux5, 4, correto);
		fgets(aux6, 4, meu);
		fgets(aux7, 4, meu);
		fgets(aux8, 4, meu);
		fgets(aux9, 4, meu);
		fgets(aux10, 4, meu);

		if (aux1[0]!=aux6[0]||aux2[0]!=aux7[0]||aux3[0]!=aux8[0]||aux4[0]!=aux9[0]||aux5[0]!=aux10[0]){
			n+='\n';
			fputs(n.c_str(), saida);
		} else {
			conta++;
		}

		fclose(correto);
		fclose(meu);
	}
	char auxi[7];
	sprintf(auxi,"%d",conta);
	//itoa(conta, auxi, 10);
	string quant(auxi);
	quant += " corretos";
	fputs(quant.c_str(), saida);
	fclose(saida);
}
