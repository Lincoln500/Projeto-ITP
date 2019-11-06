#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "formas.h"

void corAtual(int r, int g, int b) {
    pixel cor;
    cor.r = r;
    cor.g = g;
    cor.b = b;
    printf("Cor modificada com sucesso\n");
}

int main() {
    int width = 2, height = 5, r, g, b, i, j, linha_atual = 0;
    FILE *instrucoes;
    char linha[100], *resultado, nome_arquivo[30];
    pixel cor_atual, **imagem, color;
    line linha_;
    cor_atual.r = 0;
    cor_atual.g = 0;
    cor_atual.b = 0;

    //Ler Instrucao
    if ((instrucoes = fopen("instrucoes.txt", "rb+")) == NULL) {
        printf("\nERRO: Arquivo instrucoes.txt nao pode ser aberto.");
    } else {
        while (!feof(instrucoes)) {
            resultado = fgets(linha, 100, instrucoes);
            if (resultado != NULL) {
                //IMAGE
                if (strstr(linha, "image")) {
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "image %d %d\n", &width, &height);
                    imagem = criar_imagem(width, height, imagem);
                }
                //CLEAR
                else if (strstr(linha, "clear")) {
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "clear %d %d %d\n", &color.r, &color.g, &color.b);
                    clear(color.r, color.g, color.b, width, height, imagem);
                }
                //COLOR
                else if (strstr(linha, "color")) {
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "color %d %d %d\n", &cor_atual.r, &cor_atual.g, &cor_atual.b);
                }
                //LINE
                else if (strstr(linha, "line")) {
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "line %d %d %d %d\n", &linha_.linha_inicial, &linha_.linha_final, &linha_.coluna_inicial, &linha_.coluna_final);
                    drawLine(linha_.linha_inicial, linha_.linha_final, linha_.coluna_inicial, linha_.coluna_final, cor_atual, imagem);
                }
                //POLYGON
                else if (strstr(linha, "polygon")) {
                    int qtd_vertices, *vertices;
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "polygon %d", &qtd_vertices);

                    int total_vertices = qtd_vertices * 2;

                    vertices = (int*)calloc(total_vertices, sizeof(int));

                    for (i = 0; i < total_vertices; i++) {
                        fscanf(instrucoes, "%d ", &vertices[i]);
                    }
                    drawPolygon(qtd_vertices, total_vertices, vertices, cor_atual, imagem);
                }
                //RECTANGLE
                else if (strstr(linha, "rect")) {
                    int x1, y1, x2, y2;
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "rect %d %d %d %d\n", &x1, &y1, &x2, &y2);
                    drawRect(x1, y1, x2, y2, cor_atual, imagem);
                }        
                //CIRCLE
                else if (strstr(linha, "circle")) {
                    int x, y, raio;
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "circle %d %d %d\n", &x, &y, &raio);
                    drawCircle(x, y, raio, cor_atual, imagem, width, height);
                }         
                //SAVE
                else if (strstr(linha, "save")) {
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "save %s", nome_arquivo);
                    salvar(nome_arquivo, width, height, imagem);
                }

                linha_atual += strlen(linha);
            }
        }
        printf("Arquivo Encerrado!\n");
    }
    return 0;
}
