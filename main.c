#include "colecao.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

int main()
{
    int qtd_insercoes = 0, opcao;
    Colecao *colecao = NULL;

    do
    {
        printf("Selecione uma opcao:\n1 - Criar a colecao\n2 - Inserir um item na colecao\n3 - Buscar um item da colecao\n4 - Remover um item da colecao\n5 - Listar os itens da colecao\n6 - Esvaziar a colecao\n7 - Destruir a colecao\n8 - Sair do programa\n");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch(opcao)
        {
            case 1:
                if(colecao == NULL)
                {
                    int max_itens;
                    printf("Insira o numero total de alunos que a colecao tera:\n");
                    scanf("%d", &max_itens);
                    colecao = colCriar(max_itens);
                    if(colecao != NULL)
                    {
                        printf("Colecao criada com sucesso!\n");
                    }
                    else
                    {
                        printf("Erro ao criar colecao!\n");
                    }
                }
                else
                {
                    printf("A colecao ja foi criada!\n");
                }
                break;
            case 2:
                if(colecao != NULL)
                {
                    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
                    if(aluno != NULL)
                    {
                        printf("Insira um nome para o aluno:\n");
                        fgets(aluno->nome, 30, stdin);
                        printf("Insira uma matricula para o aluno:\n");
                        scanf("%d", &aluno->matricula);
                        printf("Insira uma nota para o aluno:\n");
                        scanf("%f", &aluno->nota);
                        if(colInserir(colecao, (void *)aluno) == FALSE)
                        {
                            printf("A colecao esta cheia!\n");
                        }
                        else
                        {
                            printf("Aluno adicionado com sucesso!\n");
                            qtd_insercoes++;
                        }
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 3:
                if(colecao != NULL)
                {
                    Aluno *a;
                    int opcao_interna;
                    printf("Deseja buscar o item pela matricula ou pela nota?\n1 - Matricula\n2 - Nota\n");

                    scanf("%d", &opcao_interna);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            int mat;

                            printf("Digite a matricula:\n");
                            scanf("%d", &mat);

                            a = (Aluno *)colBuscar(colecao, (void *)&mat, cmpMat);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("Aluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 2: ;
                            float nota;

                            printf("Digite a nota:\n");
                            scanf("%f", &nota);

                            a = (Aluno *)colBuscar(colecao, (void *)&nota, cmpNota);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("Aluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 4:
                if(colecao != NULL)
                {
                    Aluno *a;
                    int opcao_interna;
                    printf("Deseja remover o item pela matricula ou pela nota?\n1 - Matricula\n2 - Nota\n");

                    scanf("%d", &opcao_interna);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            int mat;

                            printf("Digite a matricula:\n");
                            scanf("%d", &mat);

                            a = (Aluno *)colRetirar(colecao, (void *)&mat, cmpMat);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("Aluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 2: ;
                            float nota;

                            printf("Digite a nota:\n");
                            scanf("%f", &nota);

                            a = (Aluno *)colRetirar(colecao, (void *)&nota, cmpNota);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("Aluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 5:
                if(colecao != NULL)
                {
                    Aluno *a;

                    a = (Aluno *)colPegarPrimeiro(colecao);
                    if(a != NULL)
                    {
                        printf("Informacoes do aluno 1:\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                        for(int i = 1; i < qtd_insercoes; i++)
                        {
                            a = (Aluno *)colPegarProximo(colecao);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno %d:\nNome: %sMatricula: %d\nNota: %.1f\n", i+1, a->nome, a->matricula, a->nota);
                            }
                        }
                    }
                    else
                    {
                        printf("A lista esta vazia!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 6:
                if(colecao != NULL)
                {
                    if(colEsvaziar(colecao) == FALSE)
                    {
                        printf("A colecao ja esta vazia!\n");
                    }
                    else
                    {
                        qtd_insercoes = 0;
                        printf("Colecao esvaziada com sucesso!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 7:
                if(colecao != NULL)
                {
                    if(colDestruir(colecao) == FALSE)
                    {
                        printf("A colecao nao esta vazia! Esvazie-a antes de destruir\n");
                    }
                    else
                    {
                        colecao = NULL;
                        printf("Colecao destruida com sucesso!\n");
                    }
                }
                else
                {
                    printf("A colecao nao foi criada!\n");
                }
                break;
            case 8:
                colEsvaziar(colecao);
                colDestruir(colecao);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }while(opcao != 8);

    return 0;
}
