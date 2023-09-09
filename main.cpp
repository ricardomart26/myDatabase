// #include <iostream>
// #include <string>
// #include <termios.h>
// #include <fstream>

// int main(void)
// {
//     bool optionChoosen = false;
//     std::string input;
//     int option = 0;

//     system("clear");

//     while (!optionChoosen)
//     {
//         std::cout << "1. Login" << std::endl;
//         std::cout << "2. Register" << std::endl;
//         std::cout << "Choose a number: " << std::endl;
//         std::cin >> input;
//         try {
//             option = stoi(input);
//             std::cout << option << std::endl;
//             if (option == 1 && option == 2)
//                 optionChoosen = true;
//         } catch (const std::exception &e) {
//             std::cout << e.what() << std::endl;
//         }
//         // system("clear");
//     }

//     std::fstream fs;

//     if (option == 1) {

//     } else if (option == 2) {
//         fs.open("users.txt", std::fstream::out | std::fstream::app);
        
//         std::cout << "Username: ";
//         std::cin >> input;
        
//         fs << input + "\n";
//         std::cout << "Password: ";
//         std::cin >> input;
//         fs << input + "\n";

//         fs.close();
//     }


//     return 0;
// }

#include "DatabaseManager.hpp"




int main(int argc, char **argv)
{
    DatabaseManager *dbManager = new DatabaseManager();

    dbManager->getAllDatabases();
}