// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#include "gtest/gtest.h"
#include "Nlinhas.h"

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(QUANTIDADE_DE_LINHAS, sem_linhas_e_comentarios) {
    char name[]="sem_linhas_e_comentarios";
    ASSERT_EQ(0, Nline(name));
}

