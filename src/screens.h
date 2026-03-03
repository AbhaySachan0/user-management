#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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


void show_menu_screen(void) {
    // clear_screen();

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


// void exit_screen(void) {

//     printf("Exiting program .....\n\n");
// }


void loading_animation(const char *message, int seconds) {
    printf("%s", message);
    fflush(stdout);

    for (int i = 0; i < seconds; i++) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
}

void exit_screen(void) {
    clear_screen();

    printf("\n");
    printf("====================================================\n");
    printf("                 EXITING SYSTEM                     \n");
    printf("====================================================\n\n");

    loading_animation("  Saving user data", 2);
    loading_animation("  Closing database connection", 2);
    loading_animation("  Cleaning up resources", 2);

    printf("\n");
    printf("  ---------------------------------------------------------\n");
    printf("               SYSTEM CLOSED SUCCESSFULLY  ✓\n");
    printf("                   Thank you for using it!\n");
    printf("  ---------------------------------------------------------\n\n");

    sleep(1);
    clear_screen();
}