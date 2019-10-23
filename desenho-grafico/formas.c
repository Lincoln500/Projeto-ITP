#include "formas.h"
#include <stdio.h>

void drawLine(int linha_inicial, int linha_final, int coluna_inicial, int coluna_final, int corAtual){

}
void drawCircle(int linha_central, int coluna_central, int raio, int corAtual){

}
void drawRect(int x, int y, int width, int height){

}
void drawPolygon(int vertices){

}
// void clear(int r, int g, int b, int width, int height, pixel imagem[width][height]) {
//     FILE *arqTeste;
//     int i, j;
//     if ((arqTeste = fopen("texte.ppm", "w")) == NULL) {
//         printf("\nERRO: Arquivo teste.ppm nao pode ser aberto.");
//     } else {
//         fprintf(arqTeste, "P3\n%d %d\n255\n", width, height);
//         for (i = 0; i < width; i++) {
//             for (j = 0; j < height; j++) {
//                 imagem[i][j].r = r;
//                 imagem[i][j].g = g;
//                 imagem[i][j].b = b;
//             }
//         }        
//         for (i = 0; i < width; i++) {
//             for (j = 0; j < height; j++) {
//                 fprintf(arqTeste, "%d ", imagem[i][j].r);
//                 fprintf(arqTeste, "%d ", imagem[i][j].g);
//                 fprintf(arqTeste, "%d\n", imagem[i][j].b);
//             }
//         }        
//         fclose(arqTeste);
//         printf("arquivo atualizado com suecesso!\n");
//     }
// }