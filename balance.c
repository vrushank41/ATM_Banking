#include "atm.h"

void balance(char name[], char pin[])
    {
        char name_b[50];
        char pin_bb[10];
        char name_bb[50];
        strcpy(name_b,name);
        strcpy(name_bb,name);
        strcpy(pin_bb,pin);
        struct coustmer c;
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name_b);
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"rb");
        if (f == NULL)
        {
            printf("\033[31m");
            printf("\n                                      **************** Invalid username!!!! ****************");
            printf("\n");
        }
        while(fread(&c,sizeof(c),1,f))
            {    
                printf("\033[35m");
                printf("\n                                                           username: %s",c.username);
                printf("\n");
                printf("\033[33m");
                printf("\n                                                           Balance: %.2f",c.balance);
                printf("\n");
            }
        fclose(f);
    }