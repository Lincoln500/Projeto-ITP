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

void drawLine(int linha_inicial, int linha_final, int coluna_inicial, int coluna_final, pixel corAtual, pixel **imagem);
void drawCircle(int x, int y, int raio, pixel corAtual, pixel **imagem, int width, int height);
void drawRect(int x1, int y1, int x2, int y2, pixel corAtual, pixel **imagem);
void drawPolygon(int qtd_vertices, int total_vertices, int vertices[], pixel cor_atual, pixel **imagem);
void fill();
void clear(int r, int g, int b, int width, int height, pixel **imagem);

#endif