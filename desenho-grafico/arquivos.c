#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"

void criar_imagem(int width, int height, pixel **matriz) {
    int i, j;
    FILE *arqTeste;
    //ESCREVER
    if ((arqTeste = fopen("texte.ppm", "w")) == NULL) {
        printf("\nERRO: Arquivo teste.ppm nao pode ser aberto.");
    } else {
        fprintf(arqTeste, "P3\n%d %d\n255\n", width, height);
        fclose(arqTeste);
        printf("arquivo atualizado com suecesso!\n");
    }
    //MATRIZ
    matriz = (pixel**)calloc(width, sizeof(pixel*));
    for(i=0;i<width;i++){
        matriz[i] = (pixel*)calloc(height, sizeof(pixel));
    }
}
void salvar(char arquivo[30], int width, int height, pixel **matriz){

}