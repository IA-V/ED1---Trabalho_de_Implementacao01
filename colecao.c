#include "colecao.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

 typedef struct _colecao_{
    int numItens;
    int maxItens;
    int cur;
    void **item;
 }Colecao;

 typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

Colecao *colCriar(int max_itens)
{
    Colecao *c;
    if(max_itens > 0)
    {
        c = (Colecao *)malloc(sizeof(Colecao));
        if(c != NULL)
        {
            c->item	 = (void **)malloc(sizeof(void *)*max_itens);
            if(c->item != NULL)
            {
                c->numItens = 0;
                c->maxItens = max_itens;
                return c;
            }
            free(c->item);
        }
    }
    free(c);
    return NULL;
}

int colInserir(Colecao *c, void *item)
{
    if(c != NULL)
    {
        if(c->numItens < c->maxItens)
        {
            c->item[c->numItens] = item;
            c->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *colBuscar(Colecao *c,	void *chave, int (*cmp)(void *, void *))
{
    void *data;
    int i, stat;
    if(c != NULL)
    {
        if(c->numItens > 0)
        {
            i = 0;
            do
            {
                stat = cmp(chave, c->item[i]);
                if(stat == FALSE)
                {
                    i++;
                }
                else
                {
                    break;
                }
            }while(i < c->numItens);
            if(stat == TRUE)
            {
                data = c->item[i];
                return data;
            }
        }
    }
    return NULL;
}

void *colPegarPrimeiro(Colecao *c)
{
    if(c !=	NULL)
    {
        if (c->numItens > 0)
        {
            c->cur = 0;
            return c->item[c->cur];
        }
    }
    return NULL;
}

void *colPegarProximo(Colecao *c)
{
    if(c !=	NULL)
    {
        c->cur++;
        if (c->cur < c->numItens)
        {
            return c->item[c->cur];
        }
    }
    return NULL;
}

void *colRetirar(Colecao *c, void *chave, int (*cmp)(void *, void *))
{
    int	i, j, stat;
    void *dado;

    if(c != NULL)
    {
        if(c->numItens > 0)
        {
            i = 0;
            do
            {
                stat = cmp(chave, c->item[i]);
                if(stat == FALSE)
                {
                    i++;
                }
                else
                {
                    break;
                }
            }while(i < c->numItens);
            if(stat == TRUE)
            {
                dado = c->item[i];
                for(j=i; j < c->numItens; j++)
                {
                    c->item[j] = c->item[j+1];
                }
                c->numItens--;
                return dado;
            }
        }
    }
    return NULL;
}

int colEsvaziar(Colecao *c)
{
    int i;
    if(c != NULL)
    {
        if(c->numItens > 0)
        {
            for(i = 0; i < c->numItens; i++)
            {
                c->item[i] = NULL;
            }
            c->numItens = 0;
            return TRUE;
        }
    }
    return FALSE;
}

int colDestruir(Colecao *c)
{
    if(c != NULL)
    {
        if(c->numItens == 0)
        {
            free(c->item);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}

int cmpMat(void *chave, void *item)
{
    int *chave_mat;
    Aluno *item_col;

    chave_mat = (int *)chave;
    item_col = (Aluno *)item;

    if (*chave_mat == item_col->matricula)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int cmpNota(void *chave, void *item)
{
    float *chave_nota;
    Aluno *item_col;

    chave_nota = (float *)chave;
    item_col = (Aluno *)item;

    if (*chave_nota == item_col->nota)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
