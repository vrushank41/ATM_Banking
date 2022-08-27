#include<stdio.h>
#include "atm.h"

int main()
    {
        int ch;
        struct coustmer c;
        while(1)
            {
            system("cls");
            printf("\033[37m");
            printf("\n                                           ==========================================                                     ");
            printf("\033[33m");
            printf("\n                                                       Available Options                                                  ");
            printf("\033[37m");
            printf("\n                                           ==========================================                                     "); 
            printf("\033[31m");
            printf("\n                                                           [1] Create                                                     \n");
            printf("\033[36m");
            printf("                                                           [2] login                                                        \n");
            printf("\033[35m");
            printf("                                                           [0] Exit                                                       \n"); 
            printf("\033[37m");
            printf("                                           ===========================================                                  \n");
            printf("Enter your choice: ");
            scanf("%d",&ch);
            system("cls");
            printf("\n");        
                switch(ch)
                    {
                        case 1: create();
                                break;
                        case 2: login();
                                break;
                        case 0: exit(0);
                        
                        default:{
                                    printf("\033[31m");
                                    printf("                                   **********************  Invalid Entry **********************\n");
                                    Sleep(2000);
                                    printf("\033[37m");
                                    printf("\n");
                                    break;
                                }
                    }
            }
        return 0;
    }

