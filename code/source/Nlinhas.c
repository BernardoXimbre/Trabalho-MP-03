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
    char caractere;
    int numero_linhas;
    if (!(file = fopen(nome_programa, "r"))) {
        return -1;
    }/* if */
    for (numero_linhas= 0 ; (caractere = Readchar(file)) != EOF;) {
        if (caractere == '/') {
            if ( (caractere = Readchar(file)) == '*') {
                Comentario_Barra_Asterisco(file);
            }
        }
        
        /*if (fgetc(file) == '/') {
            if (fgetc(file) == '/') {
                do {
                    caractere = fgetc(file);
                } while (caractere!= '\0');
            }
        }*/
    }/* for */

    fclose(file);
    return numero_linhas;
}
/***************************************************************************
* Função: ReadLine
* Descrição
*   Lê um char do arquivo.
* Parâmetros
*   file - ponteiro do tipo FILE.
* Valor retornado
*   retorna EOF quando for  fim do arquivo.
*   retorna char  quando NÃO for fim do arquivo.
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   return = EOF 
*   return = char 
****************************************************************************/ 
char ReadChar(FILE* file) {
    return fgetc(file);
}
/***************************************************************************
* Função: Comentario_Barra_Asterisco
* Descrição
*   Lê um comentário do arquivo até o final dele.
* Parâmetros
*   file - ponteiro do tipo FILE.
* Valor retornado
*   nenhum
* Assertiva de entrada
*   nome_arquivo == file
* Assertiva de saída
*   não possui retorno 
****************************************************************************/ 
void Comentario_Barra_Asterisco(FILE* file) {
    while (Readchar(file) != EOF) {
        if (Readchar(file) == '*') {
            if (Readchar(file) == '/') {
                break;
            }
        }/* if */
    }/* while */
}
