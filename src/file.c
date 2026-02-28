#include <stdio.h>

void save_usr(char *username, char *password) {
    FILE *fp = fopen("data/users.txt","a");

    if(fp == NULL){
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%s %s\n",username,password);
    fclose(fp);
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