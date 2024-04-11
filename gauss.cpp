//Autor : Robson Rego
//Abril de 2020

#include <stdlib.h>
#include <stdio.h>

//Numero de linhas da matriz
const int lin=4;
//Numero de colunas da matriz + 1
const int con=5;

int main(void){
	FILE *fptr;
	float Mat[lin][con];
	int i,j,k;
	//Leitura da matriz
	for(i=0;i<lin;i++){
		for(j=0;j<con;j++){
			scanf("%f",&Mat[i][j]);
		}
	}
	//Exibicao da matriz
	for(i=0;i<lin;i++){
		for(j=0;j<con;j++){
			printf("%.4f  ",Mat[i][j]);
		}
		printf("\n");
	}
	//Escalonamento
	//Para cada linha (exceto a ultima)
	for(k=0;k<lin-1;k++){
		float pivor=Mat[k][k]; //Pivor de cada linha
		//Para cada linha da atual ate a penultima
		for(i=k;i<lin-1;i++){
			float sec=Mat[i+1][k]; //Numeros abaixo do pivor
			for(j=k;j<con;j++){
				Mat[i+1][j]=Mat[i+1][j]-(Mat[k][j]*(sec/pivor)); //L(i+1) = L(i+1) - L(k)*(sec/pivor)
			}
		}
		printf("\n");

		//Exibicao da matriz
		for(i=0;i<lin;i++){
			for(j=0;j<con;j++){
				printf("%.4f ",Mat[i][j]);
			}
			printf("\n");
		}
	}

	//Salva em um arquivo .txt
	fptr = fopen("saida.txt","w");
	for(i=0;i<lin;i++){
		for(j=0;j<con;j++){
			fprintf(fptr,"%.4f  ",Mat[i][j]);
		}
		fprintf(fptr,"\n");
	}
	fclose(fptr);

	return 0;
}

