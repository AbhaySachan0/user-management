#ifndef USER_H
#define USER_H


typedef struct {
    int id;
    char username[30];
    char password[30];
    char role[10];
    int failed_attempts;   // no of failed attempts to lock or unlock 
    int locked;   // 0 -> unlocked , 1-> locked
} User;

extern User *users;
extern int capacity;
extern int usr_count;

void init_users();
void register_usr(void);
int check_usr(char *);
void display(void);
void ensure_capacity();

#endif