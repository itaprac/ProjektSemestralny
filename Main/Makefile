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

# Pliki źródłowe testów
TEST_SOURCES = test_biblioteka.cpp

# Pliki obiektowe testów
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Plik wykonywalny testów
TEST_EXECUTABLE = test_output

# Reguła domyślna
all: $(EXECUTABLE)

# Linkowanie
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Kompilacja każdego pliku źródłowego
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reguła kompilacji testów
test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(OBJECTS) $(TEST_OBJECTS) -lgtest -lgtest_main -pthread -o $(TEST_EXECUTABLE)

# Kompilacja każdego pliku źródłowego testów
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie plików obiektowych i pliku wykonywalnego
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(EXECUTABLE) $(TEST_EXECUTABLE)
