#include "atm.h"

void withdraw(char name[], char pin[])
    {
        char name_w[50];
        char name_ww[50];
        char pin_ww[20];
        struct coustmer c;
        strcpy(name_w, name);
        strcpy(name_ww, name);
        strcpy(pin_ww, pin);
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name_w);
        FILE *f;
        f = fopen(strcat(filename,".dat"),"rb");
        if (f == NULL)
            {
                printf("\033[32m");
                printf("\n                                 ******************** user not found...! **********************");
                printf("\n");
            }
        while(fread(&c,sizeof(c),1,f))
            {
                
                        float balance;
                        float amt;
                        c.i =  c.i + 1;
                        char str1[10];
                        char str2[10] = ": ";
                        char str[120] = "Statement ";
                        char time1[30];
                        char str4[20] = " Rs Debited on ";
                        char str3[10];
                        printf("\nEnter amount to be withdraw: ");
                        scanf("%f",&amt);
                        if (amt < 0)
                            {
                                printf("\033[31m");
                                printf("\n                                      ~~~~~~~~~~~~~~ Enter a valid amount...! ~~~~~~~~~~~~~~");
                                Sleep(2000);
                                printf("\033[37m");
                                system("cls");
                            }
                        else
                        {
                            float temp_amt;
                            temp_amt = transfer();
                            if(amt < temp_amt)
                                {
                                    if (amt > c.balance)
                                        {
                                            system("cls");
                                            printf("\033[31m");
                                            printf("\n                                  ****************** Insufficient balance...! ********************");
                                            Sleep(2000);
                                            system("cls");
                                            printf("\033[37m");
                                            printf("\n");
                                        }
                                    else
                                        {
                                            FILE *fp;
                                            fp = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat","ab");
                                            strcpy(c.username, name_ww);
                                            strcpy(c.pin, pin_ww);
                                            c.balance = c.balance - amt;
                                            totalsub(amt);
                                            time_t now;
                                            time(&now);
                                            strcpy(time1, ctime(&now));
                                            sprintf(str1,"%d",c.i);
                                            sprintf(str3, "%.2f", amt);
                                            strcat(str, str1);
                                            strcat(str,str2);
                                            strcat(str,str3);
                                            strcat(str,str4);
                                            strcat(str, time1);
                                            strcat(c.statement[c.i], str);
                                            strcat(c.date_time,str);
                                            fwrite(&c,sizeof(c),1,fp);
                                            fclose(fp);
                                            printf("\033[33m");
                                            printf("\n                                        Transaction of Rs %.2f is completed successfully...!",amt);
                                            printf("\n");
                                            printf("\033[36m");
                                            printf("\n                                        Remaining amount in your account Rs %.2f",c.balance);
                                            printf("\n");
                                            fclose(f);
                                            remove(filename);
                                            rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat",filename);
                                        }
                                    
                                }
                            else
                                {
                                    system("cls");
                                    printf("\033[33m");
                                    printf("\n                                   sorry for the Inconvenience, Insufficient balance in ATM...!"); 
                                    Sleep(2000);
                                    printf("\033[37m");
                                    system("cls");
                                    printf("\n"); 
                                } 
                            }




                    }
        fclose(f);

    }