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

TEST(QUANTIDADE_DE_LINHAS, apenas_comentarios) {
    char name[]="apenas_comentarios.cpp";
    ASSERT_EQ(0, Nline(name));
}

