#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

inline char ToChar(int i) { return static_cast<char>(i); }
inline char ToUnsignedChar(int i) { return static_cast<unsigned char>(i); }

static void ExitWithNewline(int code) {
    Write(newLine);
    std::exit(code);
}

PhoneBook::PhoneBook() : _index(0), _totalCount(0) {}
PhoneBook::~PhoneBook() = default;

void PhoneBook::addContact() {
    string input;
    string errmsg = "cannot be empty. Please try again.";
    Contact newContact;

    while (true) {
        Write("First Name: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << newLine;
            continue;
        }
        newContact.setFirstName(input);
        break;
    }

    while (true) {
        Write("Last Name: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << newLine;
            continue;
        }
        newContact.setLastName(input);
        break;
    }

    while (true) {
        Write("Nickname: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << newLine;
            continue;
        }
        newContact.setNickname(input);
        break;
    }

    while (true) {
        Write("Phone: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << newLine;
            continue;
        }
        newContact.setPhoneNumber(input);
        break;
    }

    while (true) {
        Write("Darkest Secret: ");
        if (!std::getline(std::cin, input)) ExitWithNewline(0);
        if (input.empty()) {
            Write(errmsg) << newLine;
            continue;
        }
        newContact.setDarkestSecret(input);
        break;
    }

    _contacts[_index % 8] = newContact;
    _index++;
    if (_totalCount < 8) _totalCount++;
}

string SetFormat(string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContacts() const {
    Write("|") << setWidth(10) << "Index"
              << "|" << setWidth(10) << "First Name"
              << "|" << setWidth(10) << "Last Name"
              << "|" << setWidth(10) << "Nickname" << "|" << newLine;

    for (int i = 0; i < _totalCount; i++) {
        Write("|") << setWidth(10) << i
                  << "|" << setWidth(10) << SetFormat(_contacts[i].getFirstName())
                  << "|" << setWidth(10) << SetFormat(_contacts[i].getLastName())
                  << "|" << setWidth(10) << SetFormat(_contacts[i].getNickname()) << "|" << newLine;
    }
}