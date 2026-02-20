#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#define Write(x) std::cout << x
#define WriteLine(x) std::cout << x << std::endl
#define setWidth(x) std::setw(x)
#define var auto
#define newLine std::endl
typedef std::string string;

class Contact {
private:
    // Alles private – wie in der Aufgabe verlangt
    string _firstName;
    string _lastName;
    string _nick;
    string _phoneNumber;
    string _darkestSecret;

public:
    Contact();
    ~Contact();

    // Setter
    void setFirstName(string str);
    void setLastName(string str);
    void setNickname(string str);
    void setPhoneNumber(string str);
    void setDarkestSecret(string str);

    // Getter (const, weil sie das Objekt nicht verändern)
    string getFirstName() const;
    string getLastName() const;
    string getNickname() const;
    string getPhoneNumber() const;
    string getDarkestSecret() const;
};

#endif