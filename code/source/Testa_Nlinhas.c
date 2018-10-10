// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#include "gtest/gtest.h"
#include "Nlinhas.h"

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(ABERTURA_ARQUIVO, arquivo_inexistente) {
    char name[]="arquivo_inexistente.cpp";
    ASSERT_EQ(-1, Nline(name));
}
TEST(QUANTIDADE_DE_LINHAS, apenas_linhas_em_branco) {
    char name[]="apenas_linhas_em_branco.cpp";
    ASSERT_EQ(0, Nline(name));
}
TEST(QUANTIDADE_DE_LINHAS, apenas_comentarios_barra_asterisco) {
    char name[]="apenas_comentarios_barra_asterisco.cpp";
    ASSERT_EQ(0, Nline(name));
}
TEST(QUANTIDADE_DE_LINHAS, apenas_comentarios_barra_barra) {
    char name[]="apenas_comentarios_barra_barra.cpp";
    ASSERT_EQ(0, Nline(name));
}
/*
TEST(QUANTIDADE_DE_LINHAS_Nlinhas, comentarios_diversificados) {
    char name[]="Nlinhas.c";
    ASSERT_EQ(9, Nline(name));
}

TEST(QUANTIDADE_DE_LINHAS_Testa_Nlinhas, comentarios_diversificados) {
    char name[]="Testa_Nlinhas.c";
    ASSERT_EQ(27, Nline(name));
}*/
