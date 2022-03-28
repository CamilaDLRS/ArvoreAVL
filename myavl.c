#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
	char entrada;
	int chave;
	struct tNo *raiz;

	scanf("%c %d\n", &entrada, &chave);

	if (entrada == 'r'){
		fprintf(stderr, "Entrada invalida.\n");
		exit(1);
	}
	else if (entrada != 'i') {
		fprintf(stderr, "Entrada invalida. Opcoes de entrada sao somente 'r' e 'i'.\n");
		exit(1);
	}
	else {
		raiz = cria_no(NULL, chave);

		do {
			scanf("%c %d\n", &entrada, &chave);

			if (entrada == 'i'){
				insere_no (raiz, NULL, chave);
				printf("chave: %d\n", chave);
			}
			/*else if (entrada == 'r')
				exclui_no (raiz, chave);
*/			else
				exit(1);

			//	imprime(raiz);
			raiz = balanceia_arvore(raiz);//pos ordem: calcula fator(se chegar no 2 ja para e rotaciona), corrige fatores, recalcula fator 

			printf("raiz: %d\n", raiz->chave);
			imprime(raiz);
			printf("------------------------------\n");
		} while (!feof(stdin));
	}

	return 0;
}