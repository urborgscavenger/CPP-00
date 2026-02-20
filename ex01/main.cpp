#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static void exit_with_newline(int code) {
    Write(newLine);
    std::exit(code);
}

int main(int argc, char **argv) {
    PhoneBook book; 
    string command;

    if(argc != 1)
    {
        WriteLine("No arguments expected");
        return 1;
    }
    (void)argv;
    while (true) {
        Write("Enter command (ADD, SEARCH, EXIT): ");
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