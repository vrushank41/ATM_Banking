#include "atm.h"
void create()
    {
        struct coustmer c;
        struct atm a;
        char name[50];
        printf("\nEnter username: ");
        scanf("%s",c.username);
        strcpy(name, c.username);
        printf("\nEnter your 4-digit pin:");
        scanf("%s",c.pin);
        while(strlen(c.pin) != 4)
            {
                printf("\033[31m");
                printf("\nPlease Enter only 4-digit pin:");
                fflush(stdin);
                scanf("%s",c.pin);

            }
        printf("\033[37m");
        c.balance = 0;
        c.i = 0;
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name);
        strcpy(c.date_time,"\n");
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"ab");
        fwrite(&c,sizeof(c),1,f);
        fclose(f);
        printf("\033[32m");
        printf("                                 ******************* Successfully Created...! **********************");
        Sleep(2000);
        printf("\033[37m");
        printf("\n");
    }