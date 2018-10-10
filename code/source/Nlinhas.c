// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#include <stdlib.h>
#include <stdio.h>
#include "Nlinhas.h"

/***************************************************************************
* Função: Contar numero de linhas de arquivo C++
* Descrição
*   Conta o numero de linhas do arquivo em C++.
*   Comentarios e linhas em branco não contam.
* Parâmetros
*   nome_programa - nome do arquivo que será aberto.
* Valor retornado
*   retorna -1 quando não for possível abrir arquivo.
*   retorna 0  quando  o programa NÃO possuir linhas válidas.
*   retorna n   o programa possuir linhas válidas.
* Assertiva de entrada
*   nome_programa == String
*   nome_programa == "Nlinhas.c"
* Assertiva de saída
*   numero_linhas == -1
*   numero_linhas == -0
*   numero_linhas == n 
****************************************************************************/ 
int Nline(char nome_programa[]) {
    FILE *file;
    int n_line = 0;
    char char_next;
    if (!(file = fopen(nome_programa, "r"))) {
        return -1;
    }/* if */

    for (char_next = fgetc(file); char_next != EOF; char_next = fgetc(file)) {
        if (char_next = '/') {
            if ((char_next = fgetc(file)) == '*') {
         fseek (file, Comentario_Barra_Asterisco(file)*sizeof(char), SEEK_CUR);
            }
        }
        fseek (file, Espaco_em_branco(file)*sizeof(char), SEEK_CUR);
    }/* for */

    fclose(file);
    return n_line;
}
/***************************************************************************
* Função: Espaco_em_branco
* Descrição
*   Lê uma linha até encontrar um caractere diferente de ' '.
* Parâmetros
*   file - ponteiro do tipo FILE.
* Valor retornado
*   retorna int
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   retorna um inteiro que é o numero de espaços em branco ate o \0.
****************************************************************************/ 
int Espaco_em_branco(FILE* file) {
    int espaco_branco;
    char char_next;
    if ((char_next = fgetc(file)) == ' ') {
        for (espaco_branco = 0; ; espaco_branco++) {
            char_next = fgetc(file);
            if (char_next != ' ') {
                return 0;
            }/* if */
            if (char_next == '\0') {
                return espaco_branco;
            }/* if */
        }/* for */
    }
    return 0;
}
/***************************************************************************
* Função: Comentario_Barra_Asterisco
* Descrição
*   Lê um comentário do tipo /* do arquivo até o final do comentário.
* Parâmetros
*   file - ponteiro do tipo FILE.
* Valor retornado
*   retorna int
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   retorna um inteiro que o numero de caracteres até o fim do comentário.
****************************************************************************/ 
int Comentario_Barra_Asterisco(FILE* file) {
    char char_next, char_back;
    int n_coment = 0;

    if ((char_next = fgetc(file)) == '/') {
        if ((char_next = fgetc(file)) == '*') {
            for (n_coment = 2; ; char_next = fgetc(file) , n_coment++) {
                if (char_next == '/' && char_back == '*') {
                    break;
                }
                char_back = char_next;
            }/* for */
        }/* if */
    }/* if */
    return n_coment;
}
