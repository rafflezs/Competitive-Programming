/**
** Questão H - Abobora 2022
** Rosa dos Ventos - Heverton
**
** Descrição - Descobrir qual a posição o aviador
** estara apontando (N,S,L,O) após virar 90º para
** cada lado.
**/


// PARA COMPILAR
//			gcc teste.c -o teste
// PARA EXECUTAR 
//			./teste < input.txt

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

char conv_Letra(int p){
	switch(p){
		case 0:
			return 'N';
		case 1:
			return 'L';
		case 2:
			return 'S';
		case 3:
			return 'O';
		default:
			printf("ERRO CONV.");
			exit(0);
	}
}

int conv_Num(char dir_ini){
	switch(dir_ini){
		case 'N':
			return 0;
		case 'L':
			return 1;
		case 'S':
			return 2;
		case 'O':
			return 3;
		default:
			printf("ERRO.");
			exit(0);
	}
}

char calc_dir(char *c, int qtd_com, char dir_ini){
	int i, qtd_D=0, qtd_E=0;
	int vlr_ini;
	int vlr;

	//obter qtd comandos
	for (i=0; i<qtd_com; i++){
		if (c[i] == 'D')
			qtd_D++;
		if (c[i] == 'E')
			qtd_E++;
	}

//	printf("qtd_D: %i\n", qtd_D);
//	printf("qtd_E: %i\n", qtd_E);
	
	vlr = qtd_D - qtd_E;

	vlr_ini = conv_Num(dir_ini);

	int tmp = (vlr_ini+vlr)%4;

	if (tmp >=0 ){
		return conv_Letra(tmp);
	}

	return conv_Letra(4 + tmp);
}

int main(){
	int qtd_com;	// quantidade de comandos
	char dir_ini;	// direção inicial
	char *c;	// sequencia de comandos
	char car;
	int i;

	while(1){
		car = getchar();
		if (car == EOF)
			break;
	
		ungetc(car, stdin);

		scanf("%i", &qtd_com);
		//printf("qtd_com: %i\n", qtd_com);
		
		if (qtd_com <= 0)
			break;

		//eliminando o espaço entre o número e a direção
		getchar();

		scanf("%c", &dir_ini);
		//printf("dir_ini: %c\n", dir_ini);
	
		//eliminando o \n
		getchar();

		c = (char *) malloc(qtd_com * sizeof(char));
		for (i=0; i<qtd_com; i++)
			scanf("%c", &c[i]);

		printf("%c\n", calc_dir(c, qtd_com, dir_ini));

		//eliminando o \n
		getchar();

		free(c);
	}
}
