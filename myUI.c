#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "myIO.h"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define LIGHT_BLUE "\033[36m"
#define RESET "\033[0m"
#define W_BACK "\033[47;"
#define HEART "❤"
#define HEART_BROKE "💔"
#define MUSIC "𝄞"
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
int button(int num,char *options[num]){
    int cur_choose = 0;
    char action;
    do{
        printf("PRESS E TO CONFIRM\n");
        for(int i =0;i< num;i++){
            if(i == cur_choose){
                printf(RED);
                printf("->");
                printf(" ");
            }
            printf("%s",options[i]);
            if(i == cur_choose){
                printf("");
            }
            printf("\n");
            printf(RESET);
        }
        action = getch();
        system("clear");
        switch(action){
            case 'w': 
                if(cur_choose > 0)
                    cur_choose--;
                break;
            case 's': 
                if(cur_choose < num -1)
                    cur_choose++;
                break;
        }
    }while(action != 'e');
    return cur_choose;
}
