#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void create();
void login();
void balance(char[], char[]);
void change(char[], char[]);
void withdraw(char[], char[]);
void statement(char[], char[]);
void deposit(char[], char[]);
void totaladd(float);
void totalsub(float);
void display();
float transfer();

struct coustmer
    {
        float balance;
        char pin[10];
        char username[10];
        char date_time[9000];
        int i;
        char statement[1000][150];   
    };

struct atm
    {
        float amount;
    };

int main()
    {
        int ch;
        struct coustmer c;
        while(1)
            {
            printf("\n                                           ==========================================                                     ");
            printf("\n                                                       Available Options                                                  ");
            printf("\n                                           ==========================================                                     "); 
            printf("\n                                                           [1] Create                                                     \n");
            printf("                                                           [2] login                                                        \n");
            printf("                                                           [0] Exit                                                       \n"); 
            printf("                                           ===========================================                                  \n");
            printf("Enter your choice: ");
            scanf("%d",&ch);
            printf("\n");        
                switch(ch)
                    {
                        case 1: create();
                                break;
                        case 2: login();
                                break;
                        case 0: exit(0);
                        
                        default: printf("                                   **********************  Invalid Entry **********************\n");
                                printf("\n");
                                break;
                    }
            }
        return 0;
    }

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
                printf("\nPlease Enter only 4-digit pin:");
                fflush(stdin);
                scanf("%s",c.pin);

            }
        c.balance = 0;
        c.i = 0;
        strcpy(c.date_time,"\n");
        FILE *f;
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name);
        f = fopen(strcat(filename, ".dat"),"ab");
        fwrite(&c,sizeof(c),1,f);
        fclose(f);
        printf("                                 ******************* Successfully Created...! **********************");
        printf("\n");
    }

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
        char filename[] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name);
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"rb");
        if (f == NULL)
        {
            printf("\n                                      **************** Invalid username!!!! ****************");
            printf("\n");
        }
        while(fread(&c,sizeof(c),1,f))
            {
                if(strcmp(pin , c.pin) == 0 && strcmp(name1, c.username) == 0)
                    {    
                        int n;
                        struct coustmer c;
                        printf("\n                                                        Login Successful...!");
                        printf("\n");
                        while(1)
                            {
                                printf("\n                                           ==========================================                                     ");
                                printf("\n                                                       Available Options                                                  ");
                                printf("\n                                           ==========================================                                     "); 
                                printf("\n                                                           [1] Check balance                                              \n");
                                printf("                                                           [2] Change PIN                                                 \n");
                                printf("                                                           [3] Withdraw                                                   \n");
                                printf("                                                           [4] Mini Statement                                             \n");
                                printf("                                                           [5] Deposit                                                    \n");
                                printf("                                                           [0] Home Page                                                       \n"); 
                                printf("                                           ===========================================                                  \n");
                                printf("Enter your choice: ");
                                scanf("%d",&n);
                                printf("\n");
                                
                                    switch(n)
                                        {
                                            case 1: {
                                                        fclose(f);
                                                        balance(name1, pin);
                                                        break;
                                                    }   
                                            case 2: {
                                                        fclose(f);
                                                        change(name1, pin);
                                                        break;
                                                    }
                                            case 3: {
                                                        fclose(f);
                                                        withdraw(name1, pin);
                                                        break;
                                                    }
                                            case 4: {
                                                        fclose(f);
                                                        statement(name1, pin);
                                                        break;
                                                    }
                                            case 5: {
                                                        fclose(f);
                                                        deposit(name1, pin);
                                                        break;
                                                    }
                                            case 6: {
                                                        fclose(f);
                                                        display();
                                                        break;
                                                    }
                                            case 0: {
                                                        fclose(f);
                                                        main();
                                                    }
                                                    
                                            default: printf("                                   **********************  Invalid Entry **********************\n");
                                                    printf("\n");
                                                    break;
                                        }
                                   

                            }
                    }
                else
                    {
                        printf("\n                                        ****************** Inavlid PIN...! ******************");
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
                                        login();
                                        break;
                                    }   
                            case 0: {
                                        fclose(f);
                                        main();
                                    }
                            default: printf("                                       ********************* Invalid choice *********************");
                        }
                        printf("\n");
                    }
            
            }
        fclose(f);
    }
   
void balance(char name[], char pin[])
    {
        char name_b[50];
        char pin_bb[10];
        char name_bb[50];
        strcpy(name_b,name);
        strcpy(name_bb,name);
        strcpy(pin_bb,pin);
        struct coustmer c;
        char filename[] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name_b);
        FILE *f;
        f = fopen(strcat(filename, ".dat"),"rb");
        if (f == NULL)
        {
            printf("\n                                      **************** Invalid username!!!! ****************");
            printf("\n");
        }
        while(fread(&c,sizeof(c),1,f))
            {
                if(strcmp(pin_bb , c.pin) == 0 && strcmp(name_bb, c.username) == 0)
                    {    
                        printf("\nusername: %s",c.username);
                        printf("\nBalance: %.2f",c.balance);

                    }
                else
                    {
                        printf("\n                                        ****************** Inavlid PIN!!! ******************");
                        printf("\n");
                    }
            
            }
        fclose(f);
    }

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
                    if(strcmp(pin_dd , c.pin) == 0 && strcmp(name_dd, c.username) == 0)
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
                                    printf("\n                                  ****************** Enter a valid amount...! ********************");
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
                                    printf("\n                                        Amount of Rs %.2f is credited successfully...!",amt);
                                    printf("\n");
                                    printf("\n                                        Remaining amount in your account Rs %.2f",c.balance);
                                    printf("\n");
                                    fclose(f);
                                    remove(filename);
                                    rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat",filename);

                                    
                                }
                            


                        }


                    else
                        {
                            printf("\n                          ********************  Sorry, you have entered wrong pin...!  ***********************");
                            printf("\n");

                        }
                }
            fclose(f);
   
    }

void change(char name[], char pin[])
    {
        char name_c[50];
        char pin_cc[20];
        char name_cc[50];
        struct coustmer c;
        strcpy(name_c, name);
        strcpy(name_cc, name);
        strcpy(c.username,name_c);
        strcpy(name_cc,c.username);
        strcpy(pin_cc, pin);
        char filename[100] = "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\";
        strcat(filename, name_c);
        printf("%s",filename);
        FILE *f;
        f = fopen(strcat(filename,".dat"),"rb");
        printf("%s",filename);
        if (f == NULL)
            {
                printf("\n                                   ******************* username not found!!! ********************");
                printf("\n");
            }
        while(fread(&c,sizeof(c),1,f))
            {
                if(strcmp(name_cc , c.username) == 0 && strcmp(pin_cc, c.pin) ==0)
                    {
                        char newpin[10];
                        char newpin1[10];
                        float balance;
                        printf("\n");
                        printf("\nPlease Enter your new PIN: ");
                        scanf("%s",newpin);
                        printf("\nPlease Re-Enter your new PIN: ");
                        scanf("%s",newpin1);
                        if(strcmp(newpin, newpin1) == 0)
                            strcpy(c.pin, newpin);
                        else
                            {
                                printf("\nPlease Enter the same pin as above...!");
                                fclose(f);
                                change(name_cc, pin_cc);
                            }
                        FILE *fp;
                        fp = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat","ab");
                        fwrite(&c,sizeof(c),1,fp);
                        fclose(fp);
                        printf("\n                               ***************** Successfully your new pin has updated...! *******************");
                        printf("\n");
                        printf("\n                            ==================================================================================");
                        printf("\n                                                       -: Important Note :-                                ");
                        printf("\n                            ==================================================================================");
                        printf("\n");
                        printf("\n                                         After changing to New PIN please Login again...!");
                        printf("\n");
                        fclose(f);
                        printf("%s",filename);
                        remove(filename);
                        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat",filename);
                        login();
                    }
                else
                    {
                        printf("\n                                *********** Sorry, Invalid username (or) Ivalid pin...! ************");
                        printf("\n");

                    }
            }
        fclose(f);
        
    }   
    
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
                printf("\n                                 ******************** user not found...! **********************");
                printf("\n");
            }
        while(fread(&c,sizeof(c),1,f))
            {
                if(strcmp(pin_ww , c.pin) == 0 && strcmp(name_ww, c.username) == 0)
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
                        float temp_amt;
                        temp_amt = transfer();
                        if(amt < temp_amt)
                            {
                                if (amt > c.balance)
                                    {
                                        printf("\n                                  ****************** Insufficient balance...! ********************");
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
                                        printf("\n                                        Transaction of Rs %.2f is completed successfully...!",amt);
                                        printf("\n");
                                        printf("\n                                        Remaining amount in your account Rs %.2f",c.balance);
                                        printf("\n");
                                        fclose(f);
                                        remove(filename);
                                        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\temp.dat",filename);
                                    }
                            }
                        else
                            {
                                printf("\n                                   sorry for the Inconvenience, Insufficient balance in ATM...!");  
                                printf("\n"); 
                            } 




                    }


                else
                    {
                        printf("\n                          ********************  Sorry, you have entered wrong pin...!  ***********************");
                        printf("\n");

                    }
            }
        fclose(f);

    }

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
            printf("\n                                       **************** Invalid username...! ****************");
        }
        while(fread(&c,sizeof(c),1,f))
            {
                if(strcmp(pin_ss , c.pin) == 0 && strcmp(name_ss, c.username) == 0)
                    {    
                        

                        printf("\n                                                   ============================");
                        printf("\n                                                          Mini statement ");
                        printf("\n                                                   ============================");
                        printf("\n");
                        printf("\n                                                         username: %s",c.username);
                            printf("\n");
                        if (c.i != 0)
                            {
                                printf("\n                                                  Last Few Transactions Are...!");
                                printf("\n");
                                if(c.i >= 3)
                                    {
                                        for(int i=c.i; i != c.i-3; i--)
                                            printf("\n                                    %s", c.statement[i]);
                                    }
                                else
                                    {
                                        for(int i = 1; i <= c.i; i++)
                                            printf("\n                                    %s", c.statement[i]);
                                    }
                            }
                        else
                            printf("\n                                                        No Transactions Yet...!");
                        printf("\n");
                        

                    }
                else
                    {
                        printf("\n                                      ****************** Inavlid PIN!!! ******************");
                        printf("\n");
                    }
            
            }
        fclose(f);
    }

void totaladd(float total_amt)
    {
        struct atm a;
        FILE *pntr;
        pntr = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat", "rb");
        if (pntr == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, pntr))
            {
                FILE *ptr5;
                ptr5 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\details.dat","ab");
                a.amount = a.amount + total_amt;
                fwrite(&a, sizeof(a), 1, ptr5);
                fclose(ptr5);
            }
            
        fclose(pntr);
        remove("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat");
        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\details.dat", "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat");

    }

void totalsub(float total_amt)
    {
        struct atm a;
        FILE *ptnr1;
        ptnr1 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat", "rb");
        if (ptnr1 == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, ptnr1))
            {
                FILE *ptr7;
                ptr7 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\details.dat","ab");
                a.amount = a.amount - total_amt;
                fwrite(&a, sizeof(a), 1, ptr7);
                fclose(ptr7);
            }
            
        fclose(ptnr1);
        remove("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat");
        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\details.dat", "C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat");

    }

void display()
    {
        struct atm a;
        FILE *ptr6;
        ptr6 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat", "rb");
        if (ptr6 == NULL)
            {
                printf("\nError Occured while opening a file...!");
            }
        while(fread(&a, sizeof(a), 1, ptr6))
            {
                printf("totalamount: %.2f", a.amount);
            }
        fclose(ptr6);
    }

float transfer()
    {
        struct atm a;
        FILE *ptr6;
        float temp;
        ptr6 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers\\totalamount.dat", "rb");
        if (ptr6 == NULL)
            {
                printf("\nError Occured while opening a file...!");
            }
        while(fread(&a, sizeof(a), 1, ptr6))
            {
                temp = a.amount;
            }
        fclose(ptr6);

        return temp;
    }