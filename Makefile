# Variáveis
CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

TARGET := main
MAIN := program/main.cpp
TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

CFLAGS := -g --coverage -w -Wall -O3 -std=c++17
INC := -I include/ -I third_party/

# Regras

# Compilar arquivos .cpp em .o
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# Compilar o executável principal
main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

# Executar o programa principal
run: main
	$(BINDIR)/main

# Compilar o executável de testes
tests: $(OBJECTS) $(TSTSOURCES:.cpp=.o)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

# Alvo padrão
all: main

# Limpar arquivos objeto e executáveis
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

# Limpar diretórios de build e bin
distcheck:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: clean distcheck all main tests run
