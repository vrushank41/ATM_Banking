#include "atm.h"

void statement(char name[], char pin[])
    {
        char name_s[50];
        char name_ss[50];
        char pin_ss[10];
        strcpy(name_s,name);
        strcpy(name_ss,name);
        strcpy(pin_ss,pin);
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name_s);
        struct coustmer c;
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"rb");
        if (f == NULL)
        {
            system("cls");
            printf("\033[31m");
            printf("\n                                       **************** Something went wrong...! ****************");
            printf("\n");
            printf("\n                                        *************** Please try again later...! *************");
            Sleep(2000);
            system("cls");
            printf("\033[37m");

        }
        while(fread(&c,sizeof(c),1,f))
            {
                printf("\n                                                   ============================");
                printf("\n                                                          Mini statement ");
                printf("\n                                                   ============================");
                printf("\n");
                printf("\033[36m");
                printf("\n                                                         username: %s",c.username);
                    printf("\n");
                if (c.i != 0)
                    {
                        printf("\033[35m");
                        printf("\n                                                  Last Few Transactions Are...!");
                        printf("\n");
                        if(c.i >= 3)
                            {
                                for(int i=c.i; i != c.i-3; i--)
                                    {
                                    printf("\033[33m");
                                    printf("\n                                    %s", c.statement[i]);
                                    }
                            }
                        else
                            {
                                for(int i = 1; i <= c.i; i++)
                                    {
                                    printf("\033[33m");
                                    printf("\n                                    %s", c.statement[i]);
                                    }
                            }
                    }
                else
                    {
                    printf("\033[31m");
                    printf("\n                                                        No Transactions Yet...!");
                    }
                printf("\n");
                

            
        
            }
        fclose(f);
    }
