#include <stdio.h>
#include <sqlite3.h>
#include "../includes/database.h"

void init_database(sqlite3 *db) {
    const char *sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE NOT NULL,"
        "password TEXT NOT NULL,"
        "role TEXT NOT NULL,"
        "failed_attempts INTEGER DEFAULT 0,"
        "locked INTEGER DEFAULT 0);";

    char *err_msg = 0;

    if (sqlite3_exec(db, sql, 0, 0, &err_msg) != SQLITE_OK) {
        printf("Table creation failed: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}