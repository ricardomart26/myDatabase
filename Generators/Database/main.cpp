#include "Database.hpp"

int createMenu(std::vector<std::string>& menuOptions)
{
    int menu_size = menuOptions.size();
    int opt = 0;

    system("clear");

    std::cout << "Choose an option: " << std::endl;

    for (size_t i = 0; i < menu_size; i++)
        std::cout << i + 1 << ". " << menuOptions[i] << std::endl;


    std::cin >> opt;

    if (opt <= 0 || opt >= menuOptions.size() + 1)
        return createMenu(menuOptions);

    return (opt - 1);
}



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

// int main(int argc, char **argv)
// {
//     (void)argc;
//     (void)argv;
    
//     std::string dbName;


//     while (1)
//     {
//         system("clear");
//         std::cout << "Choose a name for your db: ";
//         std::getline(std::cin, dbName);

//         try {
//             isDatabaseNameValid(dbName);
//             break;
//         } catch (const std::exception &e) {
//             std::cout << "Error: " << e.what() << std::endl;
//         }
//     }



//     std::string dbPath = DB_PATH + dbName;
//     std::cout << "Database path is " << (DB_PATH + dbName) << std::endl;

//     listDatabases();

//     // if (mkdir(dbPath.c_str(), 0777) == -1)
//     //     std::cerr << "Error: " << (DB_PATH + dbName) << std::endl;
// }