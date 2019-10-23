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
    int width = 2, height = 5, r, g, b, i, j;
    FILE *instrucoes;
    char linha[100], *resultado, nome_arquivo[30];
    pixel cor, **imagem;

    cor.r = 0;
    cor.g = 0;
    cor.b = 0;

    //Ler Instrucao
    if ((instrucoes = fopen("instrucoes.txt", "r")) == NULL) {
        printf("\nERRO: Arquivo instrucoes.txt nao pode ser aberto.");
    } else {
        while(!feof(instrucoes)){
            resultado = fgets(linha, 100, instrucoes);
            if(resultado != NULL){
                //IMAGE
                if(strstr(linha, "image")){
                    rewind(instrucoes);
                    fscanf(instrucoes, "image %d %d\n", &width, &height);
                    criar_imagem(width, height, imagem);
                }
                //SAVE
                if(strstr(linha, "save")){
                    fscanf(instrucoes, "save %s", nome_arquivo);
                    //salvar(nome_arquivo, width, height, imagem);
                }                
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
