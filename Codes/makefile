# --- Compilateur et options ---
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -IInclude -g

# --- Chemin vers SFML (adapter selon ton installation) ---
SFML_LIB = -lsfml-graphics -lsfml-window -lsfml-system

# --- Sources et objets ---
SRC = $(wildcard Src/*.cpp)
SRC += main.cpp

OBJ = $(SRC:.cpp=.o)

# --- Nom de l'exécutable ---
EXEC = jeu_de_la_vie

# --- Règle principale ---
all: $(EXEC)

# --- Compilation de l'exécutable ---
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(SFML_LIB)

# --- Compilation des .cpp en .o ---
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Nettoyage ---
clean:
	rm -f *.o Src/*.o main.o $(EXEC)

# --- Recompiler entièrement ---
re: clean all

# --- Lancer le programme ---
run: $(EXEC)
	./$(EXEC)
