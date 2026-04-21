#include <stdio.h>
#include <stdlib.h>
#include "arq.h"

int main(){

    criarArvore(&arvore);
    tipoNo* aux;
    int opcao = -1, elemento, op, valor;
    char nomeDoArquivo[12];

    while(opcao != 0){
        
        printf("\n***************************** ARVORE RUBRO-NEGRA *****************************\n");
        printf("\nEscolha a opcao que gostaria de utilizar:\n");
        printf("1 - Inserir elementos na arvore.\n");
        printf("2 - Remover elementos na arvore.\n");
        printf("3 - Imprimir elementos da arvore.\n");
        printf("4 - Buscar um elemento na arvore.\n");
        printf("0 - Sair do programa.\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInserir elementos na árvore:\n");
                printf("1 - Arquivo\n");
                printf("2 - Digitar\n");
                scanf("%d", &op);

                if(op==1){
                    printf("\nDigite o nome do arquivo para a insercao de elementos na arvore:\nO arquivo deve ter no maximo 12 caracteres no nome\n");
                    scanf("%s", nomeDoArquivo);
                    lerArquivo(&arvore, nomeDoArquivo);
                }else if(op==2){
                     printf("\nDigite o elemento a ser inserido na arvore: \n");
                    scanf("%d", &valor);
                    inserirArvore(valor, &arvore);
                    printf("\nElemento inserido na árvore com sucesso.\n");
                }
                pausa();
                break;
            case 2:
                printf("\nEscolha um elemento para remover da arvore: ");
                scanf("%d", &elemento);
                aux = buscarNaArvore(elemento, arvore);
                if(aux){
                    removerDaArvore(elemento, &arvore);
                    printf("\nSucesso. O elemento foi removido.\n");
                }else printf("\nEste elemento nao esta na arvore.\n");
                pausa();
                break;
            case 3:
                printf("\nInserir elementos:\n");
                printf("1 - Pre-Ordem\n");
                printf("2 - In-Ordem\n");
                printf("3 - Pos-Ordem\n");
                printf("4 - Arvore\n");
                scanf("%d", &op);
                if(arvore.topo == NULL){
                    printf("Arvore vazia!\n");
                }else if(op==1){
                    imprimirOrdem(arvore.topo, op);
                }else if(op==2){
                    imprimirOrdem(arvore.topo, op);
                }else if(op==3){
                    imprimirOrdem(arvore.topo, op);
                }else if(op==4){
                    imprimirArvore(arvore.topo);
                }
                pausa();
                break;
            case 4:
                int elemento;
                tipoNo *aux;
                
                printf("\nEscolha um elemento para buscar: ");
                scanf("%d", &elemento);
                aux = buscarNaArvore(elemento, arvore);
                if(aux){
                    printf("\nElemento encontrado!\n");
                }else {
                    printf("\nElemento nao encontrado!\n");
                }
                pausa();
                break;
            case 0:
                break;
        default:
            printf("Opcao invalida.\n\n");
            pausa();
        }
        system("clear||cls");
    }

    return 0;
}
