// "Copyright [2018] <Copyright Owner>"  [legal/copyright]

#include "gtest/gtest.h"
#include "Nlinhas.h"

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
TEST(Stack, CreateStackSizeNull) {
    Structure_Stack * stack = CreateStack(StackSizeNull);
    ASSERT_EQ(StackSizeNull, Size(stack));
    DestroyStack(stack);
}
*/
