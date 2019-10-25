#include "formas.h"
#include <stdio.h>

void drawLine(int linha_inicial, int linha_final, int coluna_inicial, int coluna_final, pixel corAtual){
    // float inclinacao = (float) ((coluna_final-linha_final)/ (float)(coluna_inicial-linha_inicial));
    // float referencia = inclinacao;

    // for(i=linha_inicial;i<linha_final;i++){
    //     for(j=coluna_inicial;j<coluna_final;j++){

    //     }
    // }

    printf("Linha desenhada!\n");
}
void drawCircle(int linha_central, int coluna_central, int raio, int corAtual){

}
void drawRect(int x, int y, int width, int height){

}
void drawPolygon(int vertices){

}
void clear(int r, int g, int b, int width, int height, pixel** imagem) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            imagem[i][j].r = r;
            imagem[i][j].g = g;
            imagem[i][j].b = b;
        }
    }              
    printf("Clear dado!\n");
}
