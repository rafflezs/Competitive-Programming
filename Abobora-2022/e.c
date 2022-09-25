/**
** Questão E - Abobora 2022
** A Mudança - Douglas
**
** Descrição - Problema da Mochila, distribuindo 
** C computadores igualmente (ou mais proximo)
** para N voluntarios
**/


#include <stdio.h>
#include <stdlib.h>

// nodes = voluntarios V
// threads = cadeiras C

int main(int argc, char* argv[]){
	int n_nodes, n_threads;
	scanf("%d %d", &n_nodes, &n_threads);
	int result[n_nodes];
	int pc=0;

	for (int i=0; i<n_nodes; i++)
		result[i] = 0;

	#if DEBUG
	printf("N nodes: %d\n", n_nodes);
	printf("N threads: %d\n", n_threads);
	printf("Node distrib: ");
	#endif
	while (n_threads-- > 0) {
		result[pc++]++;
		pc = pc % n_nodes;
	}

	for (int i=0; i<n_nodes-1; i++)
		printf("%d ", result[i]);
	printf("%d\n", result[n_nodes-1]);
	
	return 0;
}
