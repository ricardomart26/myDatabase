#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <iostream>
#include <sys/stat.h>
#include <filesystem>
#include <vector>
#include <algorithm>


#ifndef DB_PATH
# define DB_PATH "/usr/lib/mydatabase/"
#endif

class Database {

    public:
        Database() {};


        void    listDatabases()
        {
            for (const auto &file: std::filesystem::directory_iterator(DB_PATH))
            {
                std::cout << file.path() << std::endl;
            }
        }


        std::vector<std::string>    getDatabases()
        {
            std::vector<std::string> databasesList;
            for (const auto &file: std::filesystem::directory_iterator(DB_PATH))
            {
                databasesList.push_back(file.path());
            }
            return databasesList;
        }

        void    isDatabaseNameValid(const std::string& dbName)
        {
            if (dbName.empty())
                throw std::invalid_argument("Database name must not be empty");
            if (dbName.find("/\0") != std::string::npos)
                throw std::invalid_argument("Database name must not have a '/' or '\0'");

            std::vector<std::string> databases = getDatabases();

            if (std::find(databases.begin(), databases.end(), dbName) != databases.end())
                throw std   ::invalid_argument("Database name " + dbName + " already exists");
        }
    
    private:

};

#endif