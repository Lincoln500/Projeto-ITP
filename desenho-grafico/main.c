#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r, g, b;
} pixel;

void corAtual(int r, int g, int b) {
    pixel cor;
    cor.r = r;
    cor.g = g;
    cor.b = b;
    printf("Cor modificada com sucesso\n");
}

void image(int width, int height, pixel imagem[width][height]) {
    int i, j;
    FILE *arqTeste;

    if ((arqTeste = fopen("texte.ppm", "w")) == NULL) {
        printf("\nERRO: Arquivo teste.ppm nao pode ser aberto.");
    } else {
        fprintf(arqTeste, "P3\n%d %d\n255\n", width, height);
        printf("Digite as %d cores (r g b)\n", width * height);

        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                scanf("%d", &imagem[i][j].r);
                scanf("%d", &imagem[i][j].g);
                scanf("%d", &imagem[i][j].b);
            }
        }
        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                fprintf(arqTeste, "%d ", imagem[i][j].r);
                fprintf(arqTeste, "%d ", imagem[i][j].g);
                fprintf(arqTeste, "%d\n", imagem[i][j].b);
            }
        }

        fclose(arqTeste);
        printf("arquivo atualizado com suecesso!\n");
    }
}

void clear(int r, int g, int b, int width, int height, pixel imagem[width][height]) {
    FILE *arqTeste;
    int i, j;

    if ((arqTeste = fopen("texte.ppm", "w")) == NULL) {
        printf("\nERRO: Arquivo teste.ppm nao pode ser aberto.");
    } else {
        fprintf(arqTeste, "P3\n%d %d\n255\n", width, height);
        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                imagem[i][j].r = r;
                imagem[i][j].g = g;
                imagem[i][j].b = b;
            }
        }
        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                fprintf(arqTeste, "%d ", imagem[i][j].r);
                fprintf(arqTeste, "%d ", imagem[i][j].g);
                fprintf(arqTeste, "%d\n", imagem[i][j].b);
            }
        }
        fclose(arqTeste);
        printf("arquivo atualizado com suecesso!\n");
    }
}

int main() {
    int width, height, r, g, b;
    int op;
    printf("Digite o tamanho do arquivo (largura/coluna x altura/linha)\n");
    scanf("%d %d", &width, &height);
    pixel cor, imagem[width][height];
    cor.r = 0;
    cor.g = 0;
    cor.b = 0;

    do {
        scanf("%d", &op);
        switch (op) {
            case 1:
                image(width, height, imagem);
                break;
            case 2:
                printf("Defina uma cor (r g b)\n");
                scanf("%d %d %d", &r, &g, &b);
                corAtual(r, g, b);
                break;
            case 3:
                printf("Digite as cores para limpar a tela (r g b)\n");
                scanf("%d %d %d", &r, &g, &b);
                clear(r, g, b, width, height, imagem);
                break;
            case 9:
                break;
            default:
                printf("Valor invalido\n");
                break;
        }
    } while (op != 9);

    return 0;
}
