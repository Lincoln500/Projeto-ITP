#include <stdio.h>
#include <stdlib.h>
#include "formas.h"
#include "arquivos.h"
#include <string.h>

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
    if ((instrucoes = fopen("instrucoes.txt", "r")) == NULL) {
        printf("\nERRO: Arquivo instrucoes.txt nao pode ser aberto.");
    } else {
        while(!feof(instrucoes)){
            resultado = fgets(linha, 100, instrucoes);
            if(resultado != NULL){
                //IMAGE
                if(strstr(linha, "image")){
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "image %d %d\n", &width, &height);
                    imagem = criar_imagem(width, height, imagem);  
                }
                //CLEAR
                else if(strstr(linha, "clear")){
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "clear %d %d %d\n", &color.r, &color.g, &color.b);
                    clear(color.r, color.g, color.b, width, height, imagem);
                }
                //COLOR
                else if(strstr(linha, "color")){
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "color %d %d %d\n", &cor_atual.r, &cor_atual.g, &cor_atual.b);                    
                }
                //LINE
                else if(strstr(linha, "line")){
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "line %d %d %d %d\n", &linha_.linha_inicial, &linha_.linha_final, &linha_.coluna_inicial, &linha_.coluna_final);
                    drawLine(linha_.linha_inicial, linha_.linha_final, linha_.coluna_inicial, linha_.coluna_final, cor_atual, imagem);
                }
                //SAVE
                else if(strstr(linha, "save")){
                    fseek(instrucoes, linha_atual, SEEK_SET);
                    fscanf(instrucoes, "save %s", nome_arquivo);
                    salvar(nome_arquivo, width, height, imagem);
                }           
                linha_atual += strlen(linha);   
            }
        }
        printf("Arquivo Encerrado!\n");
    }

    // do {
    //     scanf("%d", &op);
    //     switch (op) {
    //         case 1:
    //             criar_imagem(width, height);
    //             break;
    //         case 2:
    //             printf("Defina uma cor (r g b)\n");
    //             scanf("%d %d %d", &r, &g, &b);
    //             corAtual(r, g, b);
    //             break;
    //         case 3:
    //             printf("Digite as cores para limpar a tela (r g b)\n");
    //             scanf("%d %d %d", &r, &g, &b);
    //             clear(r, g, b, width, height, imagem);
    //             break;
    //         case 9:
    //             break;
    //         default:
    //             printf("Valor invalido\n");
    //             break;
    //     }
    // } while (op != 9);

    return 0;
}
