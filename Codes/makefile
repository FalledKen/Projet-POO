# --- Compilateur et options ---
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -IInclude -g

# --- Fichiers source dans Src + le main ---
SRC = $(wildcard Src/*.cpp)
MAIN = main.cpp

# --- Tous les fichiers à compiler ---
SRCS = $(SRC) $(MAIN)

# --- Transformation : .cpp -> .o ---
OBJ = $(SRCS:.cpp=.o)

# --- Nom de l'exécutable ---
EXEC = jeu_de_la_vie

# --- Règle principale ---
all: $(EXEC)

# --- Construction de l'exécutable ---
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# --- Compilation générique ---
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Nettoyage ---
clean:
	rm -f *.o Src/*.o main.o $(EXEC)

# --- Recompile tout ---
re: clean all

# --- Exécuter ---
run: $(EXEC)
	./$(EXEC)
