#ifndef __ARVORE__
#define __ARVORE__

/*----------------------------------ARVORE--------------------------------------*/		
struct tNo{
	int fator;
	int chave;
	struct tNo *esq, *dir, *pai;
}tNo;


void imprime (struct tNo *no);
struct tNo *cria_no (struct tNo *pai, int c);
struct tNo *insere_no (struct tNo *no,struct  tNo *pai, int c);
struct tNo *rotacao_esq (struct tNo *no);
struct tNo *rotacao_dir (struct tNo *no);
int calcula_altura (struct tNo *no);
struct tNo *balanceia_arvore (struct tNo *no);//analisa os casos

/*void exclui_no (tNo *no, int c);
tNo *busca_antecessor (tNo *no);*/

#endif