#ifndef FORMAS_H
#define FORMAS_H
#include "arquivos.h"

typedef struct{
    int linha_inicial, linha_final, coluna_inicial, coluna_final;
}line;
typedef struct{
    int linha_central, coluna_central, raio;
} circle;
typedef struct{
    int x, y, width, height;
} rect;
typedef struct{
    int vertices;
} polygon;

void drawLine(int linha_inicial, int linha_final, int coluna_inicial, int coluna_final, pixel corAtual);
void drawCircle(int linha_central, int coluna_central, int raio, int corAtual);
void drawRect(int x, int y, int width, int height);
void drawPolygon(int vertices);
void clear(int r, int g, int b, int width, int height, pixel **imagem);

#endif