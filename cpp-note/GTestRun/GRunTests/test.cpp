#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gone.h"


namespace {
class classDeclaration: public testing::Test{
public:
    gone obj;
    classDeclaration()
    {
        obj;
    }

};
}
TEST_F(classDeclaration,test1){
    ASSERT_EQ("", "");
}

TEST_F(classDeclaration,test2){
    ASSERT_EQ("", "");
}
