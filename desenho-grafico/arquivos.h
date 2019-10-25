#ifndef ARQUIVOS_H
#define ARQUIVOS_H

typedef struct
{
    int r, g, b;
} pixel;

pixel** criar_imagem(int width, int height, pixel **matriz);
void salvar(char nome[30], int width, int height, pixel **matriz);

#endif