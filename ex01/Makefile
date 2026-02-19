# Name des Endprodukts
NAME        = phonebook

# Compiler und Flags
# -std=c++17 für die modernen Features (oder c++98 falls die Schule es erzwingt)
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++17

# Dateien
SRCS        = main.cpp Contact.cpp Phonebook.cpp
OBJS        = $(SRCS:.cpp=.o)

# Befehl zum Löschen
RM          = rm -f

# Standard-Regel (wird bei 'make' ausgeführt)
all: $(NAME)

# Erstellt das Programm aus den Objekt-Dateien
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regel für .o Dateien (Kompiliert .cpp zu .o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Löscht nur die .o Dateien
clean:
	$(RM) $(OBJS)

# Löscht .o Dateien UND das Programm
fclean: clean
	$(RM) $(NAME)

# Alles löschen und neu bauen
re: fclean all

# Verhindert Konflikte mit Dateien gleichen Namens
.PHONY: all clean fclean re