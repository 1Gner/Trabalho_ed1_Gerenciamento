#include "trab.h"

Livros *cria_livros(int isbn, char *titulo, char *autor, int copias){
    Livros *novo = (Livros*) calloc(1,sizeof(Livros));
    if(novo == NULL){
        printf("Problema de alocacao");
        exit(1);
    }
    novo->isbn = isbn;
    strcpy(novo->titulo,titulo);
    strcpy(novo->autor,autor);
    novo->numblivros = copias;
    return novo;
}

Livros *cria_no_cabeca(){
    Livros *novo = (Livros*) calloc(1,sizeof(Livros));
    if(novo == NULL){
        printf("Problema de alocacao");
        exit(1);
    }
    return novo;
}

Livros *busca_livro(Livros *pacote, int isb){
    Livros *aux;
    aux = pacote;
    while(aux != NULL){
        if(aux->isbn == isb){
            return aux;
        }
        aux = aux->prox;
    }
    return aux;
     
}
void imprime_livro(Livros *pacote){
    printf("Isbn: %d\n",pacote->isbn);
    printf("Titulo: %s\n",pacote->titulo);
    printf("Autor: %s\n",pacote->autor);
    printf("Copias: %d\n",pacote->numblivros);

}

void busca_isbn(Livros *pacote,int isbn){
    Livros *aux;
    aux = pacote->prox;
    while(aux != NULL){
        if(aux->isbn == isbn){
           printf("Dados do isbn existente: \n");
           imprime_livro(aux);
           break;
        }
        aux = aux->prox;
    }
    if(aux == NULL)
        printf("Numero de isbn informado nao existe no sistema \n");
}


Livros *insere_novos_livros(Livros *pacote){
    int isbn;
    char titu[50];
    char autor[50];
    int numestoque;
    Livros *aux;
    

    printf("Digite o isbn: ");
    getc(stdin);
    scanf("%d",&isbn);
    
    aux = busca_livro(pacote,isbn);
    if(aux == NULL){
        printf("Digite o nome do titulo: ");
        getc(stdin);
        scanf("%s",titu);
        printf("Digite o nome do autor[a]: ");
        getc(stdin);
        scanf("%s",autor);
        printf("Digite o numero de copias: ");
        getc(stdin);
        scanf("%d",&numestoque);
        Livros *novolivro = cria_livros(isbn,titu,autor,numestoque);
        Livros *aux2 = pacote;
        while(aux2->prox != NULL){
            aux2 = aux2->prox;
        }
        aux2->prox = novolivro;
        novolivro->ant = aux2;

    }else{
        printf("Isbn ja exite no sistema\n");
        busca_isbn(pacote,isbn);
    }
    return pacote;

}

Livros *excluir_livro(Livros *pacote){
    int isbn;
    Livros *aux;
    printf("Digite o isbn do livro a ser retirado: ");
    scanf("%d", &isbn);
    aux = busca_livro(pacote,isbn);
    if(aux != NULL){
        aux->numblivros = aux->numblivros -1;
        if(aux->numblivros == 0){
            if(aux->prox == NULL){
                aux->ant->prox = aux->prox;
                free(aux);
            }else{
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
            }
        }
    }else{
        printf("O isbn nao consta no sistema\n");
    }
    return pacote;
}

int menor_isbn(Livros *pacote){
    Livros *aux = pacote->prox;
    int menor = aux->isbn;
    while(aux != NULL){
        if(aux->isbn < menor){
            menor = aux->isbn;
        }
        aux = aux->prox;
    }
    return menor;
}

void imprime_isbn(Livros *pacote,int isbn){
    Livros *aux;
    aux = pacote->prox;
    while(aux != NULL){
        if(aux->isbn == isbn){
           imprime_livro(aux);
           break;
        }
        aux = aux->prox;
    }
}

void imprime_livros_ordenados(Livros *pacote){
    Livros *aux = pacote->prox;
    Livros *aux2 = pacote->prox;
    Livros *aux3 = pacote->prox;
    int ant=0;
    int menor;
    //int mn;
    if(aux->prox != NULL){
        //mn = menor_isbn(pacote);
        //imprime_isbn(pacote,mn);
        //ant = mn;
        while(aux != NULL){
            aux2 = pacote->prox;
            aux3 = pacote->prox;
            while(aux2 != NULL){
                if(aux2->isbn > ant){
                    menor = aux2->isbn;
                    break;
                }
                aux2 = aux2->prox;
            }
            while(aux3 != NULL){
                if(aux3->isbn < menor && aux3->isbn > ant){
                     menor = aux3->isbn;
                }
                aux3 = aux3->prox;
            }
            printf("----------------------------\n");
            imprime_isbn(pacote,menor);
            ant = menor;
            aux = aux->prox;
           }
    }else{
        printf("Sistema vazio\n");
    }      
    
}
