#include <stdio.h>
#include <stdlib.h>
#include "tipoNo.h"

void criarArvore(tipoArvore *arvore){
    arvore->topo = NULL;
}

void rotacaoEsquerdaRR(tipoNo **x){

    tipoNo *y;
    y = *x;
    *x = (*x)->noDireito;
    (*x)->noPai = y->noPai;
    y->noDireito = (*x)->noEsquerdo;
    if(y->noDireito)    y->noDireito->noPai = y;
    (*x)->noEsquerdo = y;
    y->noPai = *x;

}

void rotacaoDireitaRR(tipoNo **x){
    tipoNo *y;
    y = *x;
    *x = (*x)->noEsquerdo;
    (*x)->noPai = y->noPai;
    y->noEsquerdo = (*x)->noDireito;
    if(y->noEsquerdo)   y->noEsquerdo->noPai = y;
    (*x)->noDireito = y;
    y->noPai = *x;
}

int verificaCor(tipoNo* n){
    if(n == NULL){
        return NEG;
    }else{
        return n->cor;
    }
}

void inserirArvore(int numero, tipoArvore* arvore){
    arvore->topo = inserirElemento(numero, arvore->topo);
}


void removerDaArvore(int numero, tipoArvore *arvore){
    arvore->topo = removerElemento(numero, arvore->topo);
}

void lerArquivo(tipoArvore *arvore, char *nomeArquivo){
    FILE *arquivo;
    int valor;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == 0){
        printf("\nNao existe o arquivo na pasta do programa.\n\n");
    }else {
        while((fscanf(arquivo,"%d",&valor) != EOF)){
            inserirArvore(valor, arvore);
        }
        printf("\nOs elementos do arquivo foram inseridos na arvore com sucesso.\n\n");
    }
    //fclose(arquivo);
}

int maior(int numeroA, int numeroB){
    if(numeroA > numeroB){
        return numeroA;
    } else {
        return numeroB;
    }
}

int calculaAltura(tipoNo *raiz){
    if(raiz == NULL){
        return 0;
    }else {
        return (maior(calculaAltura(raiz->noEsquerdo),calculaAltura(raiz->noDireito)) + 1);
    }
}

int imprimirArvoreInterno(tipoNo *raiz, int e_esquerda, int distancia, int nivelAtual, int alt, char str[][N_MAX*7]){
    char strAux[alt];
    int i, esquerda, direita, tamanhoNo = 7;

    if (!raiz) return 0;

    if(raiz->cor == RUB){
        sprintf(strAux,"%04d(V)",raiz->dado);
    }else{
        sprintf(strAux,"%04d(P)",raiz->dado);
    }

    esquerda  = imprimirArvoreInterno(raiz->noEsquerdo,  1, distancia, nivelAtual + 1, alt, str);
    direita = imprimirArvoreInterno(raiz->noDireito, 0, distancia + esquerda + tamanhoNo, nivelAtual + 1, alt, str);

    for (i = 0; i < tamanhoNo; i++)
        str[nivelAtual][distancia + esquerda + i] = strAux[i];

    if (nivelAtual && e_esquerda) {
        for (i = 0; i < tamanhoNo + direita; i++)
            str[nivelAtual - 1][distancia + esquerda + tamanhoNo/2 + i] = '-';
        str[nivelAtual - 1][distancia + esquerda + tamanhoNo/2] = '.';

    }else if (nivelAtual && !e_esquerda) {
        for (i = 0; i < esquerda + tamanhoNo; i++)
            str[nivelAtual - 1][distancia - tamanhoNo/2 + i] = '-';
        str[nivelAtual - 1][distancia + esquerda + tamanhoNo/2] = '.';
    }

    return esquerda + tamanhoNo + direita;
}

void imprimirArvore(tipoNo *raiz){
    int i, alt = calculaAltura(raiz);
    char string[alt][N_MAX*7];

    for (i = 0; i < alt; i++)
        sprintf(string[i], "%80s", " ");

    imprimirArvoreInterno(raiz, 0, 0, 0, alt, string);

    for (i = 0; i < alt; i++)
        printf("%s\n", string[i]);
}

void imprimirOrdem(tipoNo *raiz, int op) {//funçao que imprime em pos,in ou pre ordem
	if (raiz == NULL) 
		return;

	if(op == 1){
	    printf("Chave: %d / Cor: %d\n\n", raiz->dado, raiz->cor);
		imprimirOrdem(raiz->noEsquerdo, op);
		imprimirOrdem(raiz->noDireito, op);
	}else if(op == 2){
	   imprimirOrdem(raiz->noEsquerdo, op);
	   printf("Chave: %d / Cor: %d\n\n", raiz->dado, raiz->cor);
	   imprimirOrdem(raiz->noDireito, op);
	}else if(op == 3){
	   imprimirOrdem(raiz->noEsquerdo, op);
	   imprimirOrdem(raiz->noDireito, op);
       printf("Chave: %d / Cor: %d\n\n", raiz->dado, raiz->cor);
	}else
	   printf("Opcao invalida, voltando ao menu...");
}
