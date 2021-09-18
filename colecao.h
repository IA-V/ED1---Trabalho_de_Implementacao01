#ifndef COLECAO_H
#define	COLECAO_H
typedef struct _colecao_ Colecao;
typedef struct _aluno_ Aluno;

Colecao *colCriar(int max_itens);
int colInserir(Colecao *c, void *item);
void *colRetirar(Colecao *c, void *chave, int (*cmp)(void *, void *));
void *colBuscar(Colecao *c, void *chave, int (*cmp)(void *, void *));
void *colPegarPrimeiro(Colecao *c);
void *colPegarProximo(Colecao *c);
int colEsvaziar(Colecao *c);
int colDestruir(Colecao *c);
int cmpMat(void *chave, void *item);
int cmpNota(void *chave, void *item);

#endif
