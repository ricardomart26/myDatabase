#include <gtest/gtest.h>
#include "DatabaseManager.hpp"


// #ifndef DB_PATH
//  #define DB_PATH "/usr/lib/mydatabase/testing/"
// #endif

TEST(DatabaseManagerClass, getAllDatabases)
{
    DatabaseManager db;

    db.getAllDatabases();

    EXPECT_EQ(1, 1);
}


int main(int ac, char **av)
{
    const char *rm = "sudo rm -rf /usr/lib/mydatabase/testing";
    system(rm);
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}