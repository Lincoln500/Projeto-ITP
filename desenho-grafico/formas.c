#include "formas.h"
#include <stdio.h>

void drawLine(int x1, int y1, int x2, int y2, pixel corAtual, pixel **imagem){
    int i, j;
    
    float inclinacao = (float)((y2-y1)/ (float)(x2-x1));
    float referencia = inclinacao;
    printf("%f\n", inclinacao);

    if(x1 == x2){
        if(y1 >= y2){
            for(i=y1;i>y2;i--){
                imagem[i][x1].r = corAtual.r;
                imagem[i][x1].g = corAtual.g;
                imagem[i][x1].b = corAtual.b;
            } 
        }   
        else{
            for(i=y2;i>y1;i--){
                imagem[i][x1].r = corAtual.r;
                imagem[i][x1].g = corAtual.g;
                imagem[i][x1].b = corAtual.b;
            }             
        }    
    }
    else if(y1 == y2){
        if(x1 >= x2){
            for(i=x1;i>x2;i--){
                imagem[y1][i].r = corAtual.r;
                imagem[y1][i].g = corAtual.g;
                imagem[y1][i].b = corAtual.b;
            } 
        }   
        else{
            for(i=x2;i>x1;i--){
                imagem[y1][i].r = corAtual.r;
                imagem[y1][i].g = corAtual.g;
                imagem[y1][i].b = corAtual.b;
            }             
        }         
    }
    else if(inclinacao == 1 || inclinacao == -1){
        if(x1<x2){
            if(y1<y2){
                j=y1;
                for(i=x1;i<x2;i++){
                    imagem[i][j].r = corAtual.r;
                    imagem[i][j].g = corAtual.g;
                    imagem[i][j].b = corAtual.b;
                    j++;
                }                 
            }
            else{
                for(i=x1;i<x2;i++){
                    imagem[i][j].r = corAtual.r;
                    imagem[i][j].g = corAtual.g;
                    imagem[i][j].b = corAtual.b;
                    j++;
                }                     
            }
        }
        else{
            if(y1<y2){
                j=y2;
                for(i=x2;i<x1;i++){
                    imagem[i][j].r = corAtual.r;
                    imagem[i][j].g = corAtual.g;
                    imagem[i][j].b = corAtual.b;
                    j--;
                    }   
                }               
            else{
                j=y1;
                for(i=x2;i<x1;i++){
                    imagem[i][j].r = corAtual.r;
                    imagem[i][j].g = corAtual.g;
                    imagem[i][j].b = corAtual.b;
                    j--;
                    }                                
            }
        }      
    }

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
