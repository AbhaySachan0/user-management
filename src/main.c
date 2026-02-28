
#include <stdio.h>
#include "screens.h"
#include "../includes/file.h"
#include "../includes/user.h"

int main() {
    int option;

    while(1) {
        show_menu_screen();
        scanf("%d",&option);

        switch (option) {
        case 1:
            show_register_screen();
            register_usr();
            pause_screen();
            break;
        
        default:
            break;
        }
    }
}