#include "Contact.hpp"

Contact::Contact() = default;
Contact::~Contact() = default;

void Contact::setFirstName(string str) { _firstName = str; }
void Contact::setLastName(string str) { _lastName = str; }
void Contact::setNickname(string str) { _nick = str; }
void Contact::setPhoneNumber(string str) { _phoneNumber = str; }
void Contact::setDarkestSecret(string str) { _darkestSecret = str; }

string Contact::getFirstName() const { return _firstName; }
string Contact::getLastName() const { return _lastName; }
string Contact::getNickname() const { return _nick; }
string Contact::getPhoneNumber() const { return _phoneNumber; }
string Contact::getDarkestSecret() const { return _darkestSecret; }