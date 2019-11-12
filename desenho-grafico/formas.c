#include "formas.h"
#include <math.h>
#include <stdio.h>

void drawLine(int x1, int y1, int x2, int y2, pixel corAtual, pixel **imagem) {
    int i, j;
    double inclinacao = fabs((double)((y2 - y1) / (double)(x2 - x1)));
    double referencia = inclinacao;
    printf("%lf\n", inclinacao);

    if (x1 == x2) {
        if (y1 >= y2) {
            for (i = y1; i >= y2; i--) {
                imagem[i][x1] = corAtual;
            }
        } else {
            for (i = y2; i >= y1; i--) {
                imagem[i][x1] = corAtual;
            }
        }
    } else if (y1 == y2) {
        if (x1 >= x2) {
            for (i = x1; i >= x2; i--) {
                imagem[y1][i] = corAtual;
            }
        } else {
            for (i = x2; i >= x1; i--) {
                imagem[y1][i] = corAtual;
            }
        }
    } else if (inclinacao == 1 || inclinacao == -1) {
        if (x1 < x2) {
            if (y1 < y2) {
                j = y1;
                for (i = x1; i <= x2; i++) {
                    imagem[j][i] = corAtual;
                    j++;
                }
            } else {
                j = y1;
                for (i = x1; i <= x2; i++) {
                    imagem[j][i] = corAtual;
                    j--;
                }
            }
        } else {
            if (y1 < y2) {
                j = y2;
                for (i = x2; i <= x1; i++) {
                    imagem[j][i] = corAtual;
                    j--;
                }
            } else {
                j = y2;
                for (i = x2; i <= x1; i++) {
                    imagem[j][i] = corAtual;
                    j++;
                }
            }
        }
    } else {
        if (fabs(x1 - x2) > fabs(y1 - y2)) {
            if (x1 < x2) {
                if (y1 < y2) {
                    j = y1;
                    for (i = x1; i <= x2; i++) {
                        if (referencia >= 1) {
                            j++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += inclinacao;
                        imagem[j][i] = corAtual;
                    }
                } else if (y1 > y2) {
                    j = y1;
                    for (i = x1; i <= x2; i++) {
                        if (referencia >= 1) {
                            j--;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;
                    }
                }
            } else if (x1 > x2) {
                if (y1 < y2) {
                    j = y1;
                    for (i = x1; i > x2; i--) {
                        if (referencia >= 1) {
                            j++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;
                    }
                } else if (y1 > y2) {
                    j = y1;
                    for (i = x1; i > x2; i--) {
                        if (referencia >= 1) {
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
        } else if (fabs(x1 - x2) < fabs(y1 - y2)) {
            if (x1 < x2) {
                if (y1 < y2) {
                    i = x1;
                    inclinacao = fabs((double)((x2 - x1) / (double)(y2 - y1)));
                    referencia = inclinacao;
                    for (j = y1; j < y2; j++) {
                        if (referencia >= 1) {
                            i++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;
                    }
                } else if (y1 > y2) {
                    i = x1;
                    inclinacao = fabs((double)((x2 - x1) / (double)(y2 - y1)));
                    referencia = inclinacao;
                    for (j = y1; j > y2; j--) {
                        if (referencia >= 1) {
                            i++;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;
                    }
                }
            } else if (x1 > x2) {
                if (y1 < y2) {
                    i = x1;
                    inclinacao = fabs((double)((x2 - x1) / (double)(y2 - y1)));
                    referencia = inclinacao;
                    for (j = y1; j < y2; j++) {
                        if (referencia >= 1) {
                            i--;
                            referencia = inclinacao + (referencia - 1);
                            imagem[j][i] = corAtual;
                            continue;
                        }
                        referencia += fabs(inclinacao);
                        imagem[j][i] = corAtual;
                    }
                } else if (y1 > y2) {
                    i = x1;
                    inclinacao = fabs((double)((x2 - x1) / (double)(y2 - y1)));
                    referencia = inclinacao;
                    for (j = y1; j > y2; j--) {
                        if (referencia >= 1) {
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
void drawCircle(int x, int y, int raio, pixel corAtual, pixel **imagem, int width, int height) {
    int d = 1 - raio;
    int i = 0;
    int j = raio;
    if (y - j >= 0 && y - j < height) {
        imagem[y - j][x] = corAtual;
    }
    if (y + j >= 0 && y + j < height) {
        imagem[y + j][x] = corAtual;
    }
    //Octante 1
    while (fabs(i) <= fabs(j)) {
        if (d < 0) {
            d = d + (2 * (i - 1)) + 3;
        } else {
            d = d + (2 * ((i - j)) - 1) + 5;
            j--;
        }
        i++;
        if (y - j >= 0 && y - j < height) {
            if (x - i >= 0 && x - i < width) {
                imagem[y - j][x - i] = corAtual;
            }
            if (x + i >= 0 && x + i < width) {
                imagem[y - j][x + i] = corAtual;
            }
        }
        if (y + j > 0 && y + j < height) {
            if (x + i >= 0 && x + i < width) {
                imagem[y + j][x + i] = corAtual;
            }
            if (x - i >= 0 && x - i < width) {
                imagem[y + j][x - i] = corAtual;
            }
        }
    }
    //Octante 2
    while (j != 0) {
        if (d < 0) {
            d = d + (2 * (j - 1)) + 3;
        } else {
            d = d + (2 * ((j - i) - 1)) - 8;
            i++;
        }
        j--;
        if (y - j >= 0 && y - j < height) {
            if (x - i >= 0 && x - i < width) {
                imagem[y - j][x - i] = corAtual;
            }
            if (x + i >= 0 && x + i < width) {
                imagem[y - j][x + i] = corAtual;
            }
        }
        if (y + j >= 0 && y + j < height) {
            if (x + i >= 0 && x + i < width) {
                imagem[y + j][x + i] = corAtual;
            }
            if (x - i >= 0 && x - i < width) {
                imagem[y + j][x - i] = corAtual;
            }
        }
    }
    printf("Circulo desenhado!\n");
}
void drawRect(int x1, int y1, int x2, int y2, pixel corAtual, pixel **imagem) {
    drawLine(x1, y1, x2, y1, corAtual, imagem);
    drawLine(x2, y1, x2, y2, corAtual, imagem);
    drawLine(x2, y2, x1, y2, corAtual, imagem);
    drawLine(x1, y2, x1, y1, corAtual, imagem);
}
void drawPolygon(int total_coordenadas, int vertices[], pixel cor_atual, pixel **imagem) {
    int i;
    for (i = 0; i < total_coordenadas - 2; i += 2) {
        drawLine(vertices[i], vertices[i + 1], vertices[i + 2], vertices[i + 3], cor_atual, imagem);
    }
    drawLine(vertices[(total_coordenadas)-2], vertices[(total_coordenadas)-1], vertices[0], vertices[1], cor_atual, imagem);
}

void fill(int x, int y, pixel cor_atual, pixel cor_velha, pixel **imagem, int width, int height) {
    //verifica se x e y nao passaram dos limites da matriz e se ele está em pixel com uma cor diferente da atual (cor_atual) e igual a cor do pixel da primeira coordenada (cor_velha)
    if (x >= 0 && y >= 0 && x < width && y < height) {
        if(imagem[y][x].r == cor_velha.r && imagem[y][x].g == cor_velha.g && imagem[y][x].b == cor_velha.b){
            //pinta
            imagem[y][x] = cor_atual;
            //chama o fill recursivamente em todas as direcoes até tudo, dentro dos limites, estiver pintado
            fill(x + 1, y, cor_atual, cor_velha, imagem, width, height);
            fill(x - 1, y, cor_atual, cor_velha, imagem, width, height);
            fill(x, y + 1, cor_atual, cor_velha, imagem, width, height);
            fill(x, y - 1, cor_atual, cor_velha, imagem, width, height);
        }
    }
    return;
}
void clear(int r, int g, int b, int width, int height, pixel **imagem) {
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
