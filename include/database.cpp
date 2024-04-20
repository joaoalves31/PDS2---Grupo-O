#include "database.hpp"
#include <iostream>
#include "sqlite/sqlite3.h"

Database::Database()
{
    int rc = sqlite3_open("database.sqlite", &cursor);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Não foi possível abrir database: " << sqlite3_errmsg(cursor) << std::endl;
        sqlite3_close(cursor);
        exit(1);
    }
};