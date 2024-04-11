//Autor : Robson Rego
//Abril de 2020

#include <stdlib.h>
#include <stdio.h>

//Numero de linhas da matriz
const int lin=4;
//Numero de colunas da matriz + 1
const int con=5;

int main(void){
	float Mat[lin][con];
	int i,j,k,m;
	FILE *fptr;
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
	//Para cada linha
	for(k=0;k<lin;k++){
		float pivor=Mat[k][k]; //Pivor de cada linha
		//Para cada coluna 
		for(m=0;m<con;m++){
			Mat[k][m]=Mat[k][m]/pivor; //L(k) = L(k)/pivor
		}
		//Para cada linha
		for(i=0;i<lin;i++){
			if(i!=k){
				float sec=Mat[i][k];//Numeros abaixo e acima do pivor
				//Para cada coluna
				for(j=0;j<con;j++){
					Mat[i][j]=Mat[i][j]-(Mat[k][j]*sec); //L(i) = L(i) - L(k)*sec
				}	
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

