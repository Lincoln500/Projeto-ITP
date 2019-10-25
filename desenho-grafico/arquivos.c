#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"

pixel** criar_imagem(int width, int height, pixel **matriz) {
    int i, j;
    //MATRIZ
    matriz = (pixel**)calloc(width, sizeof(pixel*));
    for(i=0;i<width;i++){
        matriz[i] = (pixel*)calloc(height, sizeof(pixel));
    }
    return matriz;
}
void salvar(char nome[30], int width, int height, pixel **matriz){
    int i, j;
    FILE *arqTeste;
    if ((arqTeste = fopen(nome, "w")) == NULL) {
        printf("\nERRO: Arquivo teste.ppm nao pode ser aberto.");
    } else{
        fprintf(arqTeste, "P3\n%d %d\n255\n", width, height);
        for(i=0;i<width;i++){
            for(j=0;j<height;j++){
                fprintf(arqTeste, "%d %d %d\n", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
        }
    }
    printf("Arquivo salvo com sucesso!\n");
    }
}