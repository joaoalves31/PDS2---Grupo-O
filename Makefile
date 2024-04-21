# Variáveis
CC = g++
CFLAGS = -Wall -std=c++11 # Configurações para C++
SQL = gcc -lpthread -ldl -lm # Configurações para API SQLite3
INCLUDE = include
BUILD = build
SRC = src/main.cpp
EXEC = programa

# Compilação da API SQLite3 deve ser feita pelo GCC por ser um arquivo .c
$(BUILD)/sqlite.o: $(INCLUDE)/sqlite/sqlite3.c
	$(SQL) -c $< -o $@

# Compilação de todos os módulos para arquivos .o
$(BUILD)/usuario.o: $(INCLUDE)/usuario.cpp $(INCLUDE)/usuario.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/main.o: $(SRC) $(INCLUDE)/usuario.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Linkagem de todos arquivos .o em um único executável
$(EXEC): $(BUILD)/main.o $(BUILD)/usuario.o $(BUILD)/sqlite.o
	$(CC) $(CFLAGS) -o $@ $^

# Alvo "clean" para limpar o arquivo executável
clean:
	rm -f $(EXEC)

# Alvo "run" para executar o programa compilado
run: $(EXEC)
	@./$(EXEC)

# Alvo padrão
all: $(EXEC)
