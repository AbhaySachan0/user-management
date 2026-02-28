#include <stdio.h>
#include <stdlib.h>

/* ============================
   Utility Functions
   ============================ */

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_screen(void) {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

/* ============================
   Screen Layout Functions
   ============================ */

void show_menu_screen(void) {
    clear_screen();

    printf("====================================\n");
    printf("        USER MANAGEMENT SYSTEM      \n");
    printf("====================================\n\n");

    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. View Users\n");
    printf("4. Exit\n\n");

    printf("Select an option: ");
}

void show_register_screen(void) {
    clear_screen();

    printf("====================================\n");
    printf("           REGISTER USER            \n");
    printf("====================================\n\n");
}

void show_login_screen(void) {
    clear_screen();

    printf("====================================\n");
    printf("              LOGIN USER            \n");
    printf("====================================\n\n");
}

void show_view_users_screen(void) {
    clear_screen();

    printf("====================================\n");
    printf("         REGISTERED USERS           \n");
    printf("====================================\n\n");
}