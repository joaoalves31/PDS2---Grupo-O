# Variáveis
CC = g++
CFLAGS = -Wall -std=c++11  # Configurações para C++
INCLUDE = include
BUILD = build
SRC = src/main.cpp
EXEC = programa

# Alvo padrão para compilar o executável a partir do arquivo fonte
$(BUILD)/sqlite.o: $(INCLUDE)/sqlite/sqlite3.c $(INCLUDE)/sqlite/shell.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD)/database.o: $(INCLUDE)/database.hpp $(INCLUDE)/database.cpp
	$(CC) $(CFLAGS) -c $(INCLUDE)/database.cpp -o $@

$(BUILD)/usuario.o: $(INCLUDE)/usuario.hpp $(INCLUDE)/usuario.cpp
	$(CC) $(CFLAGS) -c $(INCLUDE)/usuario.cpp -o $@

$(BUILD)/main.o: $(SRC) $(INCLUDE)/database.hpp $(INCLUDE)/usuario.hpp
	$(CC) $(CFLAGS) -c $(SRC) -o $@

$(EXEC): $(BUILD)/main.o $(BUILD)/database.o $(BUILD)/usuario.o
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)/main.o $(BUILD)/database.o $(BUILD)/usuario.o

# Alvo "clean" para limpar o arquivo executável
clean:
	rm -f $(EXEC)

# Alvo "run" para executar o programa compilado
run: $(EXEC)
	@./$(EXEC)

# Alvo padrão
all: $(EXEC)
