# Variáveis
CC = g++
CFLAGS = -Wall -std=c++11 -fPIE # Configurações para C++
SQL = gcc -lpthread -ldl -lm -fPIE  # Configurações para API SQLite3
INCLUDE = include
BUILD = build
SRC = $(wildcard src/*.cpp) $(wildcard $(INCLUDE)/*.cpp) # Alterado para procurar arquivos-fonte em src e include
OBJ = $(SRC:.cpp=.o)
EXEC = programa

# Compilação da API SQLite3 deve ser feita pelo GCC por ser um arquivo .c
$(BUILD)/sqlite.o: $(INCLUDE)/sqlite/sqlite3.c
	$(SQL) -c $< -o $@

# Compilação de todos os módulos para arquivos .o
$(BUILD)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Linkagem de todos arquivos .o em um único executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Alvo "clean" para limpar o arquivo executável e os arquivos objeto
clean:
	rm -f $(EXEC) $(OBJ)

# Alvo "run" para executar o programa compilado
run: $(EXEC)
	@./$<

# Alvo padrão
all: $(EXEC)
