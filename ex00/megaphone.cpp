#include <iostream>
#include <string>
#include <cctype>
#define string std::string
#define Write(x) std::cout << x
#define var auto
#define c_char static_cast<char>

inline char ToChar(int i) { return static_cast<char>(i); }
inline char ToUnsignedChar(int i) { return static_cast<unsigned char>(i); }

int main(int argc, char **argv)
{
    if (argc == 1)
    {
		Write("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
		string str(argv[i]);
        
        for (char c : str)
        {
            Write(ToChar(std::toupper(ToUnsignedChar(c))));
        }
		Write(" ");
    }
    Write("\n");
    return 0;
}
