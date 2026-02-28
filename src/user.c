#include <stdio.h>
#include <string.h>
#include "../includes/user.h"
#include "../includes/file.h"

#define MAX_USERS 10

typedef struct {
    char username[30];
    char password[30];
} User;

User users[MAX_USERS];
int usr_count = 0;

void register_usr() {
    if(usr_count == MAX_USERS) {
        printf("Maximum number of users reached\n");
        return;
    }

    char username[30];
    printf("Enter username: ");
    scanf("%29s",username);

    if(check_usr(username)){
        printf("Username already exists\n");
        return;
    }

    strcpy(users[usr_count].username, username);

    printf("Enter password: ");
    scanf("%29s", users[usr_count].password);

    save_usr(username, users[usr_count].password);

    usr_count++;
}

int check_usr(char *username) {
    for(int i=0;i<usr_count;i++) {
       if(strcmp(username,users[i].username)==0){
            return 1;
       }
    }
    return 0;
}

void display() {
    for(int i=0;i<usr_count;i++) {
        printf("Username: %s\nPassword: %s\n",
               users[i].username,
               users[i].password);
    }
}