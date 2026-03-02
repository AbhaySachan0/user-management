#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/user.h"
#include "../includes/file.h"

#define MAX_USERS 10

User *users = NULL;
int usr_count = 0;
int capacity = 0;

void init_users() {
    capacity = 2;
    users = malloc(capacity * sizeof(User));
    if(users==NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void ensure_capacity() {
    if(usr_count>=capacity) {
        capacity *= 2;
        User *temp = realloc(users, capacity*sizeof(User));
        if(!temp) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        users = temp;
    }
}

void register_usr() {
    char username[30];
    char password[30];
    char role[10];

    printf("Enter username: ");
    scanf("%29s",username);

    if(check_usr(username)) {
        printf("Username already exist..\n");
        return;
    }

    printf("Enter password: ");
    scanf("%29s",password);


    printf("Enter role (admin/user): ");
    scanf("%9s",role);

    ensure_capacity();

    int new_id = (usr_count==0) ? 1 : users[usr_count-1].id+1;

    users[usr_count].id = new_id;
    strcpy(users[usr_count].username,username);
    strcpy(users[usr_count].password,password);
    strcpy(users[usr_count].role,role);

    users[usr_count].failed_attempts = 0;
    users[usr_count].locked = 0;

    save_usr_db(&users[usr_count]);

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