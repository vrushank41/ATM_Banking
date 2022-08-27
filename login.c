#include "atm.h"

void login()
    {
        char name[50];
        char pin[10];
        char name1[50];
        printf("\nEnter username:");
        scanf("%s",name);
        printf("\nEnter your PIN: ");
        scanf("%s",pin);
        strcpy(name1,name);
        struct coustmer c;
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name);
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"rb");
        if (f == NULL)
        {
            printf("\033[31m");
            printf("\n                                      **************** Invalid username!!!! ****************");
            Sleep(2000);
            printf("\033[37m");
            printf("\n");
        }
        while(fread(&c,sizeof(c),1,f))
            {
                if(strcmp(pin , c.pin) == 0 && strcmp(name1, c.username) == 0)
                    {    
                        int n;
                        printf("\033[32m");
                        struct coustmer c;
                        printf("\n                                                        Login Successful...!");
                        Sleep(2000);
                        printf("\033[37m");
                        system("cls");
                        printf("\n");
                        while(1)
                            {
                                printf("\033[37m");
                                printf("\n                                           ==========================================                                     ");
                                printf("\033[36m");
                                printf("\n                                                       Available Options                                                  ");
                                printf("\033[37m");
                                printf("\n                                           ==========================================                                     "); 
                                printf("\033[32m");
                                printf("\n                                                           [1] Check balance                                              \n");
                                printf("\033[33m");
                                printf("                                                           [2] Change PIN                                                 \n");
                                printf("\033[34m");
                                printf("                                                           [3] Withdraw                                                   \n");
                                printf("\033[35m");
                                printf("                                                           [4] Mini Statement                                             \n");
                                printf("\033[37m");
                                printf("                                                           [5] Deposit                                                    \n");
                                printf("\033[36m");
                                printf("                                                           [0] Home Page                                                       \n"); 
                                printf("\033[37m");
                                printf("                                           ===========================================                                  \n");
                                printf("Enter your choice: ");
                                scanf("%d",&n);
                                printf("\n");
                                
                                    switch(n)
                                        {
                                            case 1: {
                                                        fclose(f);
                                                        system("cls");
                                                        balance(name1, pin);
                                                        printf("\033[37m");
                                                        break;
                                                    }   
                                            case 2: {
                                                        fclose(f);
                                                        system("cls");
                                                        change(name1, pin);
                                                        printf("\033[37m");
                                                        break;
                                                    }
                                            case 3: {
                                                        fclose(f);
                                                        system("cls");
                                                        withdraw(name1, pin);
                                                        printf("\033[37m");
                                                        break;
                                                    }
                                            case 4: {
                                                        fclose(f);
                                                        system("cls");
                                                        statement(name1, pin);
                                                        printf("\033[37m");
                                                        break;
                                                    }
                                            case 5: {
                                                        fclose(f);
                                                        system("cls");
                                                        deposit(name1, pin);
                                                        printf("\033[37m");
                                                        break;
                                                    }
                                            case 6: {
                                                        fclose(f);
                                                        system("cls");
                                                        display();
                                                        break;
                                                    }
                                            case 0: {
                                                        fclose(f);
                                                        system("cls");
                                                        main();
                                                    }
                                                    
                                            default: {
                                                        system("cls");
                                                        printf("\033[32m");
                                                        printf("                                   **********************  Invalid Entry **********************\n");
                                                        Sleep(2000);
                                                        system("cls");
                                                        printf("\033[37m");
                                                        printf("\n");
                                                        break;
                                                    }
                                        }
                                   

                            }
                    }
                else
                    {
                        printf("\033[31m");
                        printf("\n                                        ****************** Inavlid PIN...! ******************");
                        Sleep(2000);
                        printf("\033[37m");
                        printf("\n");
                        printf("\n                                        ======================================================");
                        printf("\n                                                         Available Options                    ");
                        printf("\n                                        ======================================================");
                        printf("\n                                                             [1] Retry                             ");
                        printf("\n                                                             [0] Home Page                              ");
                        int num;
                        printf("\nPlease Enter your choice: ");
                        scanf("%d",&num);
                        switch(num)
                        {
                            case 1: {
                                        fclose(f);
                                        system("cls");
                                        login();
                                        break;
                                    }   
                            case 0: {
                                        fclose(f);
                                        main();
                                    }
                            default: {
                                        printf("\033[31m");
                                        printf("                                       ********************* Invalid choice *********************");
                                        Sleep(2000);
                                        printf("\033[37m");
                                        break;
                                    }
                        }
                        printf("\n");
                    }
            
            }
        fclose(f);
    }
