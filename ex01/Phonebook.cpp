#include "PhoneBook.hpp"

static void exit_with_newline(int code) {
    std::cout << std::endl;
    std::exit(code);
}

PhoneBook::PhoneBook() : _index(0), _totalCount(0) {}
PhoneBook::~PhoneBook() = default;

void PhoneBook::addContact() {
    std::string input;
    std::string errmsg = "cannot be empty. Please try again.";
    Contact newContact;

    // Prompt each field and repeat until a non-empty value is provided
    while (true) {
        std::cout << "First Name: ";
        if (!std::getline(std::cin, input)) exit_with_newline(0);
        if (input.empty()) {
            std::cout << errmsg << std::endl;
            continue;
        }
        newContact.setFirstName(input);
        break;
    }

    while (true) {
        std::cout << "Last Name: ";
        if (!std::getline(std::cin, input)) exit_with_newline(0);
        if (input.empty()) {
            std::cout << errmsg << std::endl;
            continue;
        }
        newContact.setLastName(input);
        break;
    }

    while (true) {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, input)) exit_with_newline(0);
        if (input.empty()) {
            std::cout << errmsg << std::endl;
            continue;
        }
        newContact.setNickname(input);
        break;
    }

    while (true) {
        std::cout << "Phone: ";
        if (!std::getline(std::cin, input)) exit_with_newline(0);
        if (input.empty()) {
            std::cout << errmsg << std::endl;
            continue;
        }
        newContact.setPhoneNumber(input);
        break;
    }

    while (true) {
        std::cout << "Darkest Secret: ";
        if (!std::getline(std::cin, input)) exit_with_newline(0); // Einfache Validierung
        if (input.empty()) {
            std::cout << errmsg << std::endl;
            continue;
        }
        newContact.setDarkestSecret(input);
        break;
    }

    // Kontakt im Array speichern (Circular Index)
    _contacts[_index % 8] = newContact;
    _index++;
    if (_totalCount < 8) _totalCount++;
}

// Hilfsfunktion für die 10-Zeichen-Regel
std::string format(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContacts() const {
    std::cout << "|" << std::setw(10) << "Index" 
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < _totalCount; i++) {
        std::cout << "|" << std::setw(10) << i 
                  << "|" << std::setw(10) << format(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << format(_contacts[i].getLastName())
                  << "|" << std::setw(10) << format(_contacts[i].getNickname()) << "|" << std::endl;
    }
}