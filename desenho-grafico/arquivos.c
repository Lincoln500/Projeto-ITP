#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"

pixel** criar_imagem(int width, int height, pixel **matriz) {
    int i, j;
    height++;
    //MATRIZ
    matriz = (pixel**)calloc(height, sizeof(pixel*));
    for(i=0;i<height;i++){
        matriz[i] = (pixel*)calloc(width, sizeof(pixel));
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
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                fprintf(arqTeste, "%d %d %d\n", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
        }
    }
    printf("Arquivo salvo com sucesso!\n");
    }
}