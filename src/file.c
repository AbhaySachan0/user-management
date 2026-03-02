#include <stdio.h>
#include <sqlite3.h>

#include "../includes/user.h"
#include "../includes/database.h"

void save_usr_db(User *user) {
    sqlite3 *db;
    char *error_msg = 0;
    int rc;

    rc = sqlite3_open("user.db", &db);

    if(rc != SQLITE_OK) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    init_database(db);

    const char *sql =
        "INSERT INTO users "
        "(username, password, role, failed_attempts, locked) "
        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Prepare failed: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, user->username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, user->password, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, user->role, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, user->failed_attempts);
    sqlite3_bind_int(stmt, 5, user->locked);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Insert failed: %s\n", sqlite3_errmsg(db));
    } else {
        printf("User saved successfully!\n");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void view_usr() {

    FILE *fp = fopen("data/users.txt","r");

    if(fp == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), fp)!=NULL) {
        printf("%s",buffer);
    }

    fclose(fp);
}