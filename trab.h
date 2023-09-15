#ifndef __TRAB_H__
#define __TRAB_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livros{
    int isbn;
    char titulo[50];
    char autor[50];
    int numblivros;
    struct livros *prox, *ant;
}Livros;

Livros *cria_livros(int isbn, char *titulo, char *autor, int copias);
Livros *cria_no_cabeca();
Livros *busca_livro(Livros *pacote, int isb);
void imprime_livro(Livros *pacote);
void busca_isbn(Livros *pacote, int isbn);
Livros *insere_novos_livros(Livros *pacote);
Livros *excluir_livro(Livros *pacote);
int menor_isbn(Livros *pacote);
void imprime_livros_ordenados(Livros *pacote);
void imprime_isbn(Livros *pacote,int isbn);

#endif