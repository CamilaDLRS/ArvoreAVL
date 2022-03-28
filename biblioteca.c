#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void imprime (struct tNo *no)
{
	if (no != NULL){
		imprime(no->esq);
		printf("no:%d | fator:%d\n", no->chave, no->fator);
		imprime(no->dir);
	}
}

struct tNo *cria_no (struct tNo *pai, int c)
{
	struct tNo *no = malloc (sizeof(struct tNo));
	no->chave = c;
	no->fator = 0;
	no->esq = no->dir = NULL;
	no->pai = pai;

	return no;
}

struct tNo *insere_no (struct tNo *no, struct tNo *pai, int c)
{
	if (no == NULL)
		return cria_no(pai, c);

	if (c < no->chave)
		no->esq = insere_no(no->esq, no, c);
	else
		no->dir = insere_no(no->dir, no, c);

	return no;
}

int calcula_altura (struct tNo *no)
{
	if (no == NULL)
		return 0;

	int altE = calcula_altura (no->esq);
	int altD = calcula_altura (no->dir);

	if (altE > altD)
		return altE + 1;
	else
		return altD + 1;
}

struct tNo *rotacao_esq (struct tNo *no)
{	
	struct tNo *aux;

	aux = no->dir;
	no->dir = aux->esq;
	aux->pai = no->pai;
	no->pai = aux;
	aux->esq = no;

	return aux;
}

struct tNo *rotacao_dir (struct tNo *no)
{
	struct tNo *aux;
	aux = no->esq;
	no->esq = aux->dir;
	aux->pai = no->pai;
	no->pai = aux;
	aux->dir = no;

	return aux;
}

struct tNo *balanceia_arvore (struct tNo *no)//pos ordem: calcula fator(se chegar no 2 ja para e rotaciona), corrige fatores, recalcula fator
{
	if (no != NULL){

		balanceia_arvore(no->esq);
		balanceia_arvore(no->dir);
	
		no->fator = calcula_altura(no->dir) - calcula_altura(no->esq);//-1 para desconsiderar a raiz TALVEZ

		if (no->fator < -1 || no->fator > 1) {

			struct tNo *substituto; // na seguna rotação muda a subraiz

			if (no->esq != NULL) {
				if (no->esq->dir != NULL)
					no->esq = rotacao_esq(no->esq);

				substituto = rotacao_dir(no);
			
				if (substituto->pai != NULL)
					substituto->pai->esq = substituto;
			}else {
				if (no->dir->esq != NULL)
					no->dir = rotacao_dir(no->dir);
				
				substituto = rotacao_esq(no);
				if (substituto->pai != NULL)
					substituto->pai->dir = substituto;
			}

			return balanceia_arvore(substituto);
		}
	}
	return no;
}