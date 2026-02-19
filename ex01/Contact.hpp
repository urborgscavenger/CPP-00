#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    // Alles private – wie in der Aufgabe verlangt
    std::string _firstName;
    std::string _lastName;
    std::string _nick;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    ~Contact();

    // Setter
    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setNickname(std::string str);
    void setPhoneNumber(std::string str);
    void setDarkestSecret(std::string str);

    // Getter (const, weil sie das Objekt nicht verändern)
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif