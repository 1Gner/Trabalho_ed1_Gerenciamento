#include "trab.h"

int main(){
    Livros *pacote = cria_no_cabeca();
    
    int x = 0,isbn;
    printf("Comandos disponiveis:\n");
    printf("1 - Imprimir livros de forma ordenada\n");
    printf("2 - Inserir novos livros \n");
    printf("3 - Busca livro no sistema\n");
    printf("4 - Retira um livro\n");
    printf("5 - Sair do programa\n");

    while(x != 6){
        printf("Digite o numero do comando: ");
        scanf("%d",&x);
        switch(x){
            case(1):
                imprime_livros_ordenados(pacote);
            break;

            case(2):
                insere_novos_livros(pacote);
            break;
            
            case(3):
                printf("Digite o isbn a ser proucurado: ");
                scanf("%d",&isbn);
                busca_isbn(pacote,isbn);
            break;

            case(4):
                excluir_livro(pacote);
            break;

            case(5):
                // sair do programa
                x = 6;
            break;

            default:
                printf("Comando invalido");
        }
    }
    return 0;     
}