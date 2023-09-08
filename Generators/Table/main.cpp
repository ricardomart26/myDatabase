
#include <iostream>

#include "Table.hpp"


void    isTableNameValid(const std::string& tableName)
{
    if (tableName.empty())
        throw std::invalid_argument("table name must not be empty");
    if (tableName.find_first_of(':') != std::string::npos)
        throw std::invalid_argument("table name not contain a ':' character");
}


int main(int argc, char **argv)
{
    std::string tableName;

    while (1)
    {
        system("clear");
        std::cout << "Choose a name for your table: ";
        std::getline(std::cin, tableName);

        try {
            isTableNameValid(tableName);
            break;
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

}