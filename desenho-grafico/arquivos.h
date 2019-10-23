#ifndef ARQUIVOS_H
#define ARQUIVOS_H

typedef struct{
    int x, y;
}image;

typedef struct{
    char arquivo[30];
}save;

typedef struct
{
    int r, g, b;
} pixel;

void criar_imagem(int width, int height, pixel **matriz);
void salvar(char arquivo[30], int width, int height, pixel **matriz);

#endif