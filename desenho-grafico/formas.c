#include "formas.h"
#include <stdio.h>
#include <math.h>

void drawLine(int x1, int y1, int x2, int y2, pixel corAtual, pixel **imagem){
    int i, j;
    double inclinacao = fabs((double)((y2-y1)/ (double)(x2-x1)));
    double referencia = inclinacao;
    printf("%lf\n", inclinacao);

    if(x1 == x2){
        if(y1 >= y2){
            for(i=y1;i>y2;i--){
                imagem[i][x1] = corAtual;
            } 
        }   
        else{
            for(i=y2;i>y1;i--){
                imagem[i][x1] = corAtual;
            }             
        }    
    }
    else if(y1 == y2){
        if(x1 >= x2){
            for(i=x1;i>x2;i--){
                imagem[y1][i] = corAtual;
            } 
        }   
        else{
            for(i=x2;i>x1;i--){
                imagem[y1][i] = corAtual;
            }             
        }         
    }
    else if(inclinacao == 1 || inclinacao == -1){
        if(x1<x2){
            if(y1<y2){
                j=y1;
                for(i=x1;i<x2;i++){
                    imagem[j][i] = corAtual;
                    j++;
                }                 
            }
            else{
                j=y2;
                for(i=x1;i<x2;i++){
                    imagem[j][i] = corAtual;
                    j++;
                }                     
            }
        }
        else{
            if(y1<y2){
                j=y2;
                for(i=x2;i<x1;i++){
                    imagem[j][i] = corAtual;
                    j--;
                    }   
                }               
            else{
                j=y1;
                for(i=x2;i<x1;i++){
                    imagem[j][i] = corAtual;
                    j--;
                    }                                
            }
        }      
    }
    else{
        if(fabs(x1-x2)>fabs(y1-y2)){
            if(x1<x2){
                if(y1<y2){
                    j = y1;
                    for(i=x1;i<=x2;i++){
                        if(referencia >= 1){
                            j++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += inclinacao;
                        imagem[j][i] = corAtual;
                    }
                }
                else if(y1>y2){               
                    j=y1;
                    for(i=x1;i<x2;i++){
                        if(referencia >= 1){
                            j--;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                    
                    }
                }
            }
            else if(x1>x2){
                if(y1<y2){
                    j=y1;
                    for(i=x1;i>x2;i--){
                        if(referencia >= 1){
                            j++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                     
                    }
                }
                else if(y1>y2){
                    j=y1;
                    for(i=x1;i>x2;i--){
                        if(referencia >= 1){
                            j--;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }   
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                     
                    }                
                }
            }
        }
        else if(fabs(x1-x2)<fabs(y1-y2)){
            if(x1<x2){
                if(y1<y2){
                    i=x1;
                    inclinacao = fabs((double)((x2-x1)/ (double)(y2-y1)));
                    referencia = inclinacao;
                    for(j=y1;j<y2;j++){
                        if(referencia >= 1){
                            i++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }   
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                    
                    }
                }
                else if(y1>y2){
                    i=x1;
                    inclinacao = fabs((double)((x2-x1)/ (double)(y2-y1)));
                    referencia = inclinacao;
                    for(j=y1;j>y2;j--){
                        if(referencia >= 1){
                            i++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }   
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                    
                    }                    
                }   
            }
            else if(x1>x2){
                if(y1<y2){
                    i=x1;
                    inclinacao = fabs((double)((x2-x1)/ (double)(y2-y1)));
                    referencia = inclinacao;
                    for(j=y1;j<y2;j++){
                        if(referencia >= 1){
                            i--;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }   
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                    
                    }                    
                }
                else if(y1>y2){
                    i=x1;
                    inclinacao = fabs((double)((x2-x1)/ (double)(y2-y1)));
                    referencia = inclinacao;
                    for(j=y1;j>y2;j--){
                        if(referencia >= 1){
                            i--;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }   
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;                    
                    }
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
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            imagem[i][j].r = r;
            imagem[i][j].g = g;
            imagem[i][j].b = b;
        }
    }              
    printf("Clear dado!\n");
}
