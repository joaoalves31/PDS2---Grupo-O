# Variáveis
CC = g++
CFLAGS = -Wall -std=c++11 -lpthread -ldl -lm # Configurações para C++
INCLUDE = include
BUILD = build
SRC = src/main.cpp
EXEC = programa

# Alvo padrão para compilar o executável a partir do arquivo fonte
$(BUILD)/sqlite.o: $(INCLUDE)/sqlite/sqlite3.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/usuario.o: $(INCLUDE)/usuario.cpp $(INCLUDE)/usuario.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/main.o: $(SRC) $(INCLUDE)/usuario.hpp
	$(CC) $(CFLAGS) -c $< -o $@

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
