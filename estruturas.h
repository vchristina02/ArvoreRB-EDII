#include <stdio.h>
#include <stdlib.h>

#define RUB 0
#define NEG 1
#define N_MAX 1027

typedef struct tipoNo{
    int dado;
    char cor;
    struct tipoNo *noPai;
    struct tipoNo *noEsquerdo;
    struct tipoNo *noDireito;
}tipoNo;

typedef struct tipoArvore{
    tipoNo *topo;
}tipoArvore;

tipoArvore arvore;

void pausa(){//funçao de pausaro sistema
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n');//ja limpa o buffer antes
    printf ("\nPressione qualquer tecla para continuar...");
    scanf("%*c");//não PRECISO LIMPAR O BUFFER porque O USUARIO não VAI DIGITAR NADA
}