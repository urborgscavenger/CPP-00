#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

// C#-style convenience macros (similar to megaphone.cpp)
#define string std::string
#define Write(x) std::cout << x
#define var auto
#define c_char static_cast<char>

inline char ToChar(int i) { return static_cast<char>(i); }
inline char ToUnsignedChar(int i) { return static_cast<unsigned char>(i); }

static void ExitWithNewline(int code) {
    Write(std::endl);
    std::exit(code);
}

PhoneBook::PhoneBook() : _index(0), _totalCount(0) {}
PhoneBook::~PhoneBook() = default;

void PhoneBook::addContact() {
    string input;
    string errmsg = "cannot be empty. Please try again.";
    Contact newContact;

    // Prompt each field and repeat until a non-empty value is provided
    while (true) {
        Write("First Name: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << std::endl;
            continue;
        }
        newContact.setFirstName(input);
        break;
    }

    while (true) {
        Write("Last Name: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << std::endl;
            continue;
        }
        newContact.setLastName(input);
        break;
    }

    while (true) {
        Write("Nickname: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << std::endl;
            continue;
        }
        newContact.setNickname(input);
        break;
    }

    while (true) {
        Write("Phone: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << std::endl;
            continue;
        }
        newContact.setPhoneNumber(input);
        break;
    }

    while (true) {
        Write("Darkest Secret: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0); // Einfache Validierung
        if (input.empty()) {
            Write(errmsg) << std::endl;
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

// Hilfsfunktion für die 10-Zeichen-Regel (PascalCase)
string SetFormat(string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContacts() const {
    Write("|") << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < _totalCount; i++) {
        Write("|") << std::setw(10) << i
                  << "|" << std::setw(10) << SetFormat(_contacts[i].getFirstName())
                  << "|" << std::setw(10) << SetFormat(_contacts[i].getLastName())
                  << "|" << std::setw(10) << SetFormat(_contacts[i].getNickname()) << "|" << std::endl;
    }
}