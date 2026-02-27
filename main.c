
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

void register_usr();
int check_usr(char *);
void login_usr();
void display();

typedef struct {
    char username[30];
    char password[30];
}User;

User users[MAX_USERS];
int usr_count = 0;


int main() {
    int option;

    while(1) {

        printf( "\nWelcome to User Mangement");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an option.");
        
        scanf("%d",&option);

        switch (option) {
            case 1:
                register_usr();
                break;
            case 2:
                // login_usr();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
                break;

            default:
                printf("\nInvalid Option. Please try again");
                break;
        }
    }
    return 0; 

}

void register_usr() {
    char username[30];
    printf("Enter username: ");
    scanf("%s",username);

    if(check_usr(username)){
        printf("user already exist");
        return;
    }
    strcpy(users[usr_count].username,username);

    printf("password: ");
    scanf("%s",users[usr_count].password);
    usr_count++;

    display();
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
        printf("username : %s\npassword : %s",users[i].username, users[i].password);
    }
}

    