#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip> 
#include <cstdlib>
#include <iostream>
#include <string>

class PhoneBook {
private:
    Contact _contacts[8];
    int     _index;
    int     _totalCount;  

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;
    void displayFullContact(int index) const;
};

#endif