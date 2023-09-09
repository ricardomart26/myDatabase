#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <fcntl.h>
#include <fstream>
#include <unistd.h>
#include "EntityBase.hpp"
#include <memory>
#include <vector>
#include <filesystem>

// TODO: Check if its possibel to open a file for both reading and writing
// TODO: Create a executable for creating Cpp classes for each entity
// TODO: Check if unique is well written

// #ifndef DB_PATH
// # define DB_PATH "/usr/lib/mydatabase/"
// #endif


// const char *DB_PATH = "/usr/lib/mydatabase/";

enum class DatabaseEntityTypes {
    STRING,
    INT,
    BOOLEAN,
    PRIMARY_KEY_ID,
};

enum class DatabaseEntityOptions {
    MIN_LENGTH,
    MAX_LENGTH,
    UNIQUE,
    DEFAULT_VALUE
};

enum class DbStatus {
    FAILED,
    NOT_FOUND,
    SUCCESS,
};

class Database {

    public:

        Database(const std::string dbName, char sep = ':') 
        {
            _sep = sep;
            _dbName = dbName;

        }

        void openConnection()
        {
            _fd = std::fstream(_dbName);
            if (_fd.is_open())
                throw std::runtime_error("openConnection() failed: connection already open");
            if (access(_dbName.c_str(), F_OK) == -1)
                _fd.open(_dbName.c_str(), std::fstream::out);
            else
                _fd.open(_dbName.c_str(), std::fstream::app);
        
        }

        // DbStatus getDatabase() {

        // }

        std::string getDatabaseName() const {
            return _dbName;
        }

        void    writeInformation(const std::string &info)
        {
            if (info.empty())
                std::__throw_invalid_argument("Info send to writeInformation is empty");
            _fd.write(info.c_str(), info.size());
        }

        void updateInformation(const std::string key, const std::string value) 
        {

        }

        void loadEntities(std::vector<std::unique_ptr<EntityBase> > entities)
        {
            _entities.clear();
            _entities = std::move(entities);
        }

        ~Database() {
            _fd.close();
        }

    private:

        std::string     _dbName;
        std::fstream    _fd;
        char            _sep;
        std::vector<std::unique_ptr<EntityBase>> _entities;
};


#endif 