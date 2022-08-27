#include "atm.h"

void deposit(char name[], char pin[])
    {
            char name_d[50];
            char name_dd[50];
            char pin_dd[20];
            struct coustmer c;
            strcpy(name_d, name);
            strcpy(name_dd, name);
            strcpy(pin_dd, pin);
            char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
            strcat(filename, name_d);
            FILE *f;
            f = fopen(strcat(filename,".dat"),"rb");
            if (f == NULL)
                {
                    printf("\n                                 ******************** user not found...! **********************");
                    printf("\n");
                }
            while(fread(&c,sizeof(c),1,f))
                {
                    
                    float balance;
                    float amt;
                    char str[100];
                    char time1[30];
                    char str1[20] = " Rs Credited on ";
                    c.i =  c.i + 1;
                    char str2[1000] = "statement ";
                    char str3[20];
                    char str4[10] = ": ";
                    sprintf(str3, "%d", c.i);
                    strcat(str2,str3);
                    strcat(str2,str4);
                    
                    
                    printf("\nEnter amount to be deposited: ");
                    scanf("%f",&amt);
                    if (amt < 0)
                        {
                            printf("\033[31m");
                            printf("\n                                  ****************** Enter a valid amount...! ********************");
                            Sleep(2000);
                            system("cls");
                            printf("\033[37m");
                            printf("\n");
                        }
                    else
                        {
                            FILE *fp;
                            fp = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat","ab");
                            strcpy(c.username, name_dd);
                            strcpy(c.pin, pin_dd);
                            c.balance = c.balance + amt;
                            totaladd(amt);
                            time_t now;
                            time(&now);
                            strcpy(time1, ctime(&now));
                            sprintf(str, "%.2f", amt);
                            strcat(str2,str);
                            strcat(str2,str1);
                            strcat(str2,time1);
                            strcat(c.date_time,str2);
                            strcat(c.statement[c.i], str2);
                            fwrite(&c,sizeof(c),1,fp);
                            fclose(fp);
                            printf("\033[36m");
                            printf("\n                                        Amount of Rs %.2f is credited successfully...!",amt);
                            printf("\n");
                            printf("\033[33m");
                            printf("\n                                        Remaining amount in your account Rs %.2f",c.balance);
                            printf("\n");
                            fclose(f);
                            remove(filename);
                            rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat",filename);

                            
                        }
                    }
                fclose(f);
   
    }