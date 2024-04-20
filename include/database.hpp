#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite/sqlite3.h"
#include <string>

class Database
{
	public:
        sqlite3* cursor;
        Database();
};

#endif