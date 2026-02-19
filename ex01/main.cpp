#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static void exit_with_newline(int code) {
    std::cout << std::endl;
    std::exit(code);
}

int main(int argc, char **argv) {
    PhoneBook book; 
    std::string command;

    if(argc != 1)
    {
        std::cout << "No arguments expected" << std::endl;
        return 1;
    }
    (void)argv;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) 
            exit_with_newline(0);

        if (command == "ADD") {
            book.addContact();
        } else if (command == "SEARCH") {
            book.searchContacts();
        } else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}