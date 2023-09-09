#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP


#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include "Database.hpp"
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>

// #ifndef DB_PATH
// # define DB_PATH "/usr/lib/mydatabase/"
// #endif

const char *DB_PATH = "/usr/lib/mydatabase/";

class DatabaseManager {

    public:

        DatabaseManager()
        {
            DIR *pdir = opendir(DB_PATH);

            if (pdir == NULL)
            {
                if (mkdir(DB_PATH, 0777) == -1)
                    throw std::runtime_error("mkdir() of database root directory failed");
            }
            closedir(pdir);
            __getAllDatabases();
        }

        std::vector<Database *>   getAllDatabases() 
        {
            return _databases;
        }


        Database *getDatabaseByName(const std::string dbName)
        {
            for (size_t i = 0; i < _databases.size(); i++)
            {
                if (_databases[i]->getDatabaseName() == dbName)
                    return _databases[i];
            }
            return nullptr;
        }

        void    isDatabaseNameValid(const std::string& dbName)
        {
            if (dbName.empty())
                throw std::invalid_argument("Database name must not be empty");
            if (dbName.find("/\0") != std::string::npos)
                throw std::invalid_argument("Database name must not have a '/' or '\0'");

            for (size_t i = 0; i < _databases.size(); i++)
            {
                if (_databases[i]->getDatabaseName() == dbName)
                    throw std::invalid_argument("Database name " + dbName + " already exists");
            }

        }

        Database *getOrCreateDatabase(const std::string dbName)
        {
            Database *db = getDatabaseByName(dbName);

            if (db == nullptr)
                db = createDatabase(dbName);
            return db;
        }

        Database *createDatabase(const std::string name)
        {
            try {
                isDatabaseNameValid(name);
                if (mkdir(std::string(DB_PATH + name).c_str(), 0777) == -1)
                    throw std::runtime_error("Error creating database directory");
                Database *db = new Database(name);
                _databases.push_back(db);
                return db;
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
            return nullptr;
        }

        ~DatabaseManager() {}

    private:

        void   __getAllDatabases() {

            for (auto &db: std::filesystem::directory_iterator(std::string(DB_PATH)))
            {
                _databases.push_back(new Database(db.path()));
            }
        }

        std::vector<Database *> _databases;


};

#endif
