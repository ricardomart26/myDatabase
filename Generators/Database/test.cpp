#include <gtest/gtest.h>
#include "main.cpp"



// TEST(createMenuTest, WrongSize)
// {
//     EXPECT_EQ(createMenu({"foo", "bar", "baz"}), );
// }

TEST(validateDatabaseNameTest, EmptyDatabaseName)
{
    EXPECT_THROW(isDatabaseNameValid(""), std::invalid_argument);
}

TEST(validateDatabaseNameTest, validDatabaseName)
{
    EXPECT_NO_THROW(isDatabaseNameValid("valid"));
}

int main(void)
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
