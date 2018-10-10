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
    char char_next, char_back;
    if (!(file = fopen(nome_programa, "r"))) {
        return -1;
    }/* if */
    char_back = fgetc(file);
    char_next = fgetc(file);
    for (; char_back != EOF; char_back = fgetc(file), char_next = fgetc(file)) {
        if (char_back == '\n') {
            Espaco_em_branco(file);
        } else if (char_back == '/' && char_next == '*') {
            Comentario_Barra_Asterisco(file);
        } else if (char_back == '/' && char_next == '/') {
            Comentario_Barra_Barra(file);
        } else {
            n_line++;
        }
    }
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
*   retorna void
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   retorna uma nova posiçao do ponteiro file onde acaba a linha em branco.
****************************************************************************/ 
void Espaco_em_branco(FILE* file) {
    char char_next;
    for (char_next = fgetc(file); ; char_next = fgetc(file)) {
        if (char_next != ' ' && char_next != '\n') {
            return;
        }/* if */
    }/* for */
}
/***************************************************************************
* Função: Comentario_Barra_Asterisco
* Descrição
*   Lê um comentário do tipo /* do arquivo até o final do comentário.
* Parâmetros
*   file - ponteiro do tipo FILE.
* Valor retornado
*   retorna void
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   retorna uma nova posiçao do ponteiro file onde acaba o comentario.
****************************************************************************/ 
void Comentario_Barra_Asterisco(FILE* file) {
    char char_next, char_back;
    for (char_back = '0', char_next = fgetc(file); ; char_next = fgetc(file)) {
        if (char_back == '*' && char_next == '/') {
            break;
        }
        char_back = char_next;
    }/* for */
}
/***************************************************************************
* Função: Comentario_Barra_Barra
* Descrição
*   Lê um comentário do tipo // do arquivo até o final da linha.
* Parâmetros
*   file - ponteiro do tipo FILE.
* Valor retornado
*   retorna void
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   retorna uma nova posiçao do ponteiro file onde acaba a linha.
****************************************************************************/ 
void Comentario_Barra_Barra(FILE* file) {
    char char_next;
    for (char_next = fgetc(file); ; char_next = fgetc(file)) {
        if (char_next == '\n') {
            return;
        }/* if */
    }/* for */
}
