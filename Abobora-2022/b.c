/**
** Questão B - Abobora 2022
** Jogo da Vida - Heverton
**
** Jogo da vida de Conways
**/


//	PARA COMPILAR
//		gcc teste.c -o teste
// PARA EXECUTAR
//		./teste < input.txt


#include <stdio.h>
#include <stdlib.h>

void mostrar_mat(char **m, int qtd_lin, int qtd_col){
	int i, j;	
	for (i=0; i<qtd_lin;i++){
		for (j=0; j<qtd_col; j++){
			printf("%c ", m[i][j]);
		}
		printf("\n");
	}
}

void saida_mat(char **m, int qtd_lin, int qtd_col){
	int i, j;	
	for (i=0; i<qtd_lin;i++){
		for (j=0; j<qtd_col; j++){
			printf("%c", m[i][j]);
		}
	}
}

char aplicar_regra(char **m, int a, int b, int dim_i, int dim_j){
	int qtd_vivo=0;
	int i, j;

	// contar qtd de células vivas na vizinhança
	for (i=a-1; i<=a+1; i++){
		for (j=b-1; j<=b+1; j++){

			if (i < 0 || j < 0) //caso exceder a borda para menos continue
				continue;
			if (i >= dim_i || j >= dim_j) //caso exceder a borda para mais continue
				continue;

			if (i == a && j == b) // a própria célula não é contabilizada
				continue;

			if (m[i][j] == '1')
				qtd_vivo++;
//			printf("m[%i][%i]=%c\n",i,j,m[i][j]);
		}
	}

//	printf("vivo: %i\n", qtd_vivo);

	// aplicando as regras
	if (m[a][b] == '1'){ // se a célula é viva
		if (qtd_vivo < 2)
			return '0';

		if (qtd_vivo > 3)
			return '0';

		return '1';
	}else{	// se a célula é morta
		if (qtd_vivo == 3)
			return '1';
	}

	return '0';
}

void evol(char ***m, int qtd_lin, int qtd_col, int dim_i, int dim_j){
	int i, j;

	char **aux;

//	mostrar_mat(m, qtd_lin, qtd_col);

	aux = (char **) malloc(qtd_lin * sizeof(char *));
	for (i=0; i<qtd_lin; i++)
		aux[i] = (char *) malloc(qtd_col * sizeof(char));
	
	for (i=0; i<qtd_lin; i++){
		for (j=0; j<qtd_col; j++){
			aux[i][j] = aplicar_regra(*m, i, j, dim_i, dim_j);
//			printf("atualiza m[%i][%i]=%c\n", i, j, aux[i][j]);
		}
	}

	//apagando o espaço da matriz original
	for (i=0; i<qtd_lin; i++)
		free((*m)[i]);
	free(*m);

	//ajustando o ponteiro da matriz original para a nova matriz
	*m = aux;
}

int main(){
	int i, j;
	int qtd_ger;
	int qtd_lin;
	int qtd_col;
	char **m;
	char car;

	while(1){
		car = getchar();
		if (car == EOF)
			break;
	
		ungetc(car, stdin);

		scanf("%i", &qtd_ger);
		//printf("qtd_ger: %i\n", qtd_ger);

		if (qtd_ger <= 0)
			break;

		scanf("%i", &qtd_lin);
		//printf("qtd_lin: %i\n", qtd_lin);
		
		scanf("%i", &qtd_col);
		//printf("qtd_col: %i\n", qtd_col);
	
		//Alocando o espaço dinamicamente para a matriz
		m = (char **) malloc(qtd_lin * sizeof(char *));
		for (i=0; i<qtd_lin; i++)
			m[i] = (char *) malloc(qtd_col * sizeof(char));

		//eliminando o \n
		getchar();

		//lendo a entrada do arquivo
		for (i=0; i<qtd_lin; i++)
			for (j=0; j<qtd_col; j++)
				scanf("%c", &m[i][j]);

		// evoluindo as gerações
		for (i=0; i<qtd_ger; i++){
			evol(&m, qtd_lin, qtd_col, qtd_lin, qtd_col);
	//		mostrar_mat(m, qtd_lin, qtd_col);
		}
	
		//mostrar_mat(m, qtd_lin, qtd_col);
		saida_mat(m, qtd_lin, qtd_col);
		printf("\n");

		//apagando o espaço da matriz alocada
		for (i=0; i<qtd_lin; i++)
			free(m[i]);
		free(m);


		//eliminando o \n
		getchar();
	}
}
