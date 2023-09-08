#ifndef DATABASE_HPP
#define DATABASE_HPP


#include <string>
#include <fcntl.h>
#include <fstream>
#include <unistd.h>


// TODO: Check if its possibel to open a file for both reading and writing
// TODO: Create a executable for creating Cpp classes for each entity
// TODO: Check if unique is well written



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


class Database {

    public:
        Database(const std::string filename, char sep = ':')
        {
            _sep = sep;
            _filename = filename;
            _fd = std::fstream(_filename);
            if (access(_filename.c_str(), F_OK) == -1)
                _fd.open(_filename.c_str(), std::fstream::out);
            else
                _fd.open(_filename.c_str(), std::fstream::app);
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

        ~Database() {
            _fd.close();
        }

    private:

        std::string     _filename;
        std::fstream    _fd;
        char            _sep;
};


#endif 