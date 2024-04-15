# Variáveis
CC = g++
CFLAGS = -Wall -Wextra -std=c++11  # Configurações para C++
SRC = src/main.cpp
EXEC = programa

# Alvo padrão para compilar o executável a partir do arquivo fonte
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

# Alvo "clean" para limpar o arquivo executável
clean:
	rm -f $(EXEC)

# Alvo "run" para executar o programa compilado
run: $(EXEC)
	@./$(EXEC)

# Alvo padrão
all: $(EXEC)
