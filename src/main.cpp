#include <iostream>
#include "include/usuario.hpp"
#include <sqlite/sqlite3.h>

class Database
{
	private:
		sqlite3* db;
		// Construtor para prevenção da instanciação da db
		Database() {
        int rc = sqlite3_open("database.sqlite", &db);
        if (rc != SQLITE_OK) {
            std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            exit(1);
        }
    }

	public:
		// Função para que outros módulos acessem a db
		static Database& getInstancia()
		{
			static Database instance;
			return instance;
    	}

		// Método para facilitar a execução de queries
		void query(const std::string& sql_query) {
			char* errMsg;
			int rc = sqlite3_exec(db, sql_query.c_str(), nullptr, nullptr, &errMsg);
			if (rc != SQLITE_OK) {
				std::cerr << "SQL error: " << errMsg << std::endl;
				sqlite3_free(errMsg);
			} else {
				std::cout << "Query executed successfully" << std::endl;
			}
		}

	// Desconstrutor para não crashar a db
	~Database()
	{
		sqlite3_close(db);
    }
};

int main()
{
	std::cout << "Bem Vindo ao Banquinho!" << '\n';
	std::cout << "Primeiro, registre-se ou entre em nosso sistema." << '\n';
	std::cout << "[1] Entrar na Minha conta" << '\n';
	std::cout << "[2] Criar Conta" << '\n';
	std::cout << "[3] Sair do Sistema" << '\n';

	int opcao;
	std::cin >> opcao;

	if (opcao == 3)
	{
		std::cout << "Volte Sempre!" << std::endl; 
		exit(0);
	}

	Usuario usuarioAtual;
	if (opcao == 2)
	{
		usuarioAtual.criarConta();
	}
}
