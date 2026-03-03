
#include <stdio.h>
#include "screens.h"
#include "../includes/file.h"
#include "../includes/user.h"

int main() {
    int option;
    init_users();
    load_user();

    while(1) {
        show_menu_screen();
        scanf("%d",&option);

        switch (option) {
        case 1:
            show_register_screen();
            register_usr();
            pause_screen();
            break;
        
        case 2:
            show_login_screen();
            // login_usr();
            pause_screen();
            break;

        case 3:
            show_view_users_screen();
            view_usr();
            pause_screen();
            break;

        case 4: 
            exit_screen();
            return 0;
            break;
        default:
            break;
        }
    }
}