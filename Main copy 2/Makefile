# Makefile

# Kompilator i flagi
CXX = g++
CXXFLAGS = -Wall -std=c++20 -I .

# Plik wykonywalny
EXECUTABLE = output

# Pliki źródłowe
SOURCES = main.cpp Biblioteka.cpp Czytelnik.cpp funkcje.cpp Ksiazka.cpp RejestratorZdarzen.cpp

# Pliki obiektowe (zamiana .cpp na .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Reguła domyślna
all: $(EXECUTABLE)

# Linkowanie
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Kompilacja każdego pliku źródłowego
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie plików obiektowych i pliku wykonywalnego
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
