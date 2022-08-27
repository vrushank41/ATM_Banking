#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<dirent.h>

void create();
void password(char[]);
void login();
void balance(char[], char[]);
void change(char[], char[]);
void withdraw(char[], char[]);
void statement(char[], char[]);
void deposit(char[], char[]);
void totaladd(int, int, int, int, int);
void totalsub(int, int, int, int, int);
void display();
int transfer();
int username_verify(char*);


struct coustmer
    {
        int balance;
        char pin[10];
        char username[10];
        char date_time[9000];
        int i;
        char statement[1000][150];   
    };

struct atm
    {
        int amount;
        int thous;
        int fives;
        int twos;
        int hunds;
        int fiftys;
    };

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
                                    fflush(stdin);
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

void create()
    {
        struct coustmer c;
        struct atm a;
        char u_name[50];
        printf("\nEnter username: ");
        scanf("%s",c.username);
        strcpy(u_name, c.username);
        if(username_verify(u_name))
            {
                printf("\033[31m");
                printf("                                              sorry, username already taken");
                Sleep(3000);
                system("cls");
                main();
            }
        else
            {
                char name[50];
                strcpy(name, c.username);
                printf("\nEnter your 4-digit pin:");
                char pin[5];
                password(pin);
                strcpy(c.pin, pin);
                printf("\033[37m");
                c.balance = 0;
                c.i = 0;
                char filename[100];
                strcat(filename, name);
                strcpy(c.date_time,"\n");
                FILE *f;
                f = fopen(strcat(filename, ".dat"),"ab");
                fwrite(&c,sizeof(c),1,f);
                fclose(f);
                printf("\033[32m");
                printf("\n                         ******************* Successfully Created...! **********************");
                Sleep(2000);
                printf("\033[37m");
                printf("\n");
            }
    }

void password(char pass[])
    {
        char ch;
        int i=0;
        while(i < 4)
            {
                ch = getch();
                if(ch == 13) // Enter key
                    {
                        break;
                    }
                else if(ch == 32 || ch == 9) // space or tab key
                    {
                        continue;
                    }
                else if(ch == 8 && i > 0) // backspace key
                    {
                        i--;
                        printf("\b \b");
                    }
                else if(ch != 8)
                    {
                        pass[i] = ch;
                        printf("*");
                        i++;
                    }    
            }
        pass[i] = '\0';
        
    }

void login()
    {
        char name[50];
        char pin[10];
        char name1[50];
        printf("\nEnter username:");
        scanf("%s",name);
        printf("\nEnter your PIN: ");
        //scanf("%s",pin);
        char pass[5];
        password(pass);
        strcpy(pin, pass);
        strcpy(name1,name);
        struct coustmer c;
        char filename[100];
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
                if(strcmp(pass , c.pin) == 0 && strcmp(name1, c.username) == 0)
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
                                                        break;
                                                    }
                                                    
                                            default: {
                                                        fflush(stdin);
                                                        system("cls");
                                                        printf("\033[31m");
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
                        printf("\033[36m");
                        printf("\n                                                         Available Options                    ");
                        printf("\033[37m");
                        printf("\n                                        ======================================================");
                        printf("\033[32m");
                        printf("\n                                                             [1] Retry                             ");
                        printf("\033[35m");
                        printf("\n");
                        printf("\n                                                             [0] Home Page                              ");
                        printf("\033[37m");
                        printf("\n                                        ======================================================");
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
                                        break;
                                    }
                            default: {
                                        fflush(stdin);
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

void balance(char name[], char pin[])
    {
        char name_b[50];
        char pin_bb[10];
        char name_bb[50];
        strcpy(name_b,name);
        strcpy(name_bb,name);
        strcpy(pin_bb,pin);
        struct coustmer c;
        char filename[100];
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
                printf("\n                                                           Balance: %d",c.balance);
                printf("\n");
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
        char filename[100];
        strcat(filename, name_c);
        FILE *f;
        f = fopen(strcat(filename,".dat"),"rb");
        if (f == NULL)
            {
                printf("\033[31m");
                printf("\n                                   ******************* username not found!!! ********************");
                printf("\n");
            }
        while(fread(&c,sizeof(c),1,f))
            {
                
                char newpin[10];
                char newpin1[10];
                int balance;
                char pass[5];
                printf("\n");
                printf("\nPlease Enter your new PIN: ");
                password(pass);
                strcpy(newpin, pass);
                printf("\033[37m");
                printf("\nPlease Re-Enter your new PIN: ");
                password(pass);
                strcpy(newpin1, pass);
                printf("\033[37m");
                if(strcmp(newpin, newpin1) == 0)
                    strcpy(c.pin, newpin);
                else
                    {
                        printf("\033[31m");
                        printf("\n                                                  Please Enter the same pin as above...!");
                        Sleep(2000);
                        printf("\033[37m");
                        fclose(f);
                        change(name_cc, pin_cc);
                    }
                system("cls");
                FILE *fp;
                fp = fopen("filename","ab");
                fwrite(&c,sizeof(c),1,fp);
                fclose(fp);
                printf("\033[32m");
                printf("\n                               ***************** Successfully your new pin has updated...! *******************");
                Sleep(2000);
                system("cls");
                printf("\033[37m");

                printf("\n");
                printf("\033[37m");
                printf("\n                            ==================================================================================");
                printf("\033[33m");
                printf("\n                                                       -: Important Note :-                                ");
                printf("\033[37m");
                printf("\n                            ==================================================================================");
                printf("\n");
                printf("\033[36m");
                printf("\n                                         After changing to New PIN please Login again...!");
                printf("\033[37m");
                printf("\n");
                fclose(f);
                remove(filename);
                rename("temp.dat",filename);
                login();
        
            }
        fclose(f);
        
    }   

void withdraw(char name[], char pin[])
    {
        char name_w[50];
        char name_ww[50];
        char pin_ww[20];
        struct coustmer c;
        struct atm a;
        strcpy(name_w, name);
        strcpy(name_ww, name);
        strcpy(pin_ww, pin);
        char filename[100];
        strcat(filename, name_w);
        int user_amt;
        printf("\nEnter amount to be withdraw: ");
        scanf("%d",&user_amt);
        int amt = user_amt;
        int atm_amt = transfer();
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
                if(user_amt > atm_amt)
                    {
                        system("cls");
                        printf("\033[33m");
                        printf("\n                                   sorry for the Inconvenience, Insufficient balance in ATM...!"); 
                        Sleep(2000);
                        printf("\033[37m");
                        system("cls");
                        printf("\n"); 
                    }
                else
                    {
                        if (user_amt > c.balance)
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
                                if(user_amt%50 == 0)
                                    {
                                        char str1[10];
                                        char str2[10] = ": ";
                                        char str[120] = "Statement ";
                                        char time1[30];
                                        char str4[20] = " Rs Debited on ";
                                        char str3[10];
                                        int aa = 0,b = 0,cc = 0,d = 0,e = 0,a1 = 0,b1 = 0,c1 = 0,d1 = 0;
                                        FILE *f1;
                                        f1 = fopen("totalamount.dat", "rb");
                                        while(fread(&a, sizeof(a), 1, f1))
                                            {
                                                
                                                if(user_amt >= 2000 && a.thous != 0)
                                                        {
                                                            a1 = user_amt%2000;
                                                            aa = (user_amt - a1)/2000;
                                                            user_amt = a1;
                                                        }
                                                if((user_amt >= 500 || a1 >= 500) && a.fives != 0 )
                                                    {
                                                        b1 = user_amt%500;
                                                        b = (user_amt - b1)/500;
                                                        user_amt = b1;
                                                    }
                                                if((user_amt >= 200 || b1 >= 200) && a.twos != 0 )
                                                    {
                                                        c1 = user_amt%200;
                                                        cc = (user_amt - c1)/200;
                                                        user_amt = c1;
                                                    }
                                                if((user_amt >= 100 || c1 >= 100) && a.hunds != 0 )
                                                    {
                                                        d1 = user_amt%100;
                                                        d = (user_amt - d1)/100;
                                                        user_amt = d1;
                                                    }
                                                if((user_amt >= 50 || c1 >= 50) && a.fiftys != 0 )
                                                    {
                                                        e = user_amt/50;
                                                    }
                                            }
                                                fclose(f1);
                                                c.i =  c.i + 1;
                                                FILE *fp;
                                                fp = fopen("temp.dat","ab");
                                                strcpy(c.username, name_ww);
                                                strcpy(c.pin, pin_ww);
                                                c.balance = c.balance - amt;
                                               // struct coustmer c;
                                                totalsub(aa, b, cc, d, e);
                                                time_t now;
                                                time(&now);
                                                //struct coustmer c;
                                                strcpy(time1, ctime(&now));
                                                sprintf(str1,"%d",c.i);
                                                sprintf(str3, "%d", amt);
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
                                                printf("\n                                        Transaction of Rs %d is completed successfully...!",amt);
                                                printf("\n");
                                                printf("\033[36m");
                                                printf("\n                                        Remaining amount in your account Rs %d",c.balance);
                                                printf("\n");
                                                fclose(f);
                                                remove(filename);
                                                rename("temp.dat",filename);
                                            
                                    }
                                else
                                    {
                                        system("cls");
                                        printf("\033[31m");
                                        printf("\n                                  Enter amount in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n");
                                        Sleep(2000);
                                        system("cls");
                                        printf("\033[37m");
                                        printf("\n");
                                    }
                            }
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
        char filename[100];
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

void deposit(char name[], char pin[])
    {
            char name_d[50];
            char name_dd[50];
            char pin_dd[20];
            int user_amt;
            struct coustmer c;
            strcpy(name_d, name);
            strcpy(name_dd, name);
            strcpy(pin_dd, pin);
            char filename[100];
            strcat(filename, name_d);
            int thous, fives, twos, hunds, fiftys;
            FILE *f;
            f = fopen(strcat(filename,".dat"),"rb");
            if (f == NULL)
                {
                    printf("\033[31m");  // red
                    printf("\n                                 ******************** user not found...! **********************");
                    Sleep(2000);
                    system("cls");
                    printf("\033[37m");  // white
                    printf("\n");
                }
            while(fread(&c,sizeof(c),1,f))
                {
                    
                    int balance;
                    int amt;
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
                    printf("\033[36m"); // light blue
                    printf("                                       Enter amount only in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n");
                    printf("\033[37m"); // white
                    printf("\nEnter amount to be deposited: ");
                    scanf("%d",&amt);
                    user_amt = amt;
                       
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
                        
                            if(amt%50 == 0)
                                {
                                    
                                    fflush(stdin);
                                    printf("Enter no. of 2000's: ");
                                    scanf("%d", &thous);
                                    fflush(stdin);
                                    printf("Enter no. of 500's: ");
                                    scanf("%d", &fives);
                                    fflush(stdin);
                                    printf("Enter no. of 200's: ");
                                    scanf("%d", &twos);
                                    fflush(stdin);
                                    printf("Enter no. of 100's: ");
                                    scanf("%d", &hunds);
                                    fflush(stdin);
                                    printf("Enter no. of 50's: ");
                                    scanf("%d", &fiftys);
                                    
                                    if(amt == ((thous*2000) + (fives*500) + (twos*200) + (hunds*100) + (fiftys*50)))
                                        {
                                            FILE *fp;
                                            fp = fopen("temp.dat","ab");
                                            strcpy(c.username, name_dd);
                                            strcpy(c.pin, pin_dd);
                                            c.balance = c.balance + amt;
                                            totaladd(thous, fives, twos, hunds, fiftys);
                                            time_t now;
                                            time(&now);
                                            strcpy(time1, ctime(&now));
                                            sprintf(str, "%d", amt);
                                            strcat(str2,str);
                                            strcat(str2,str1);
                                            strcat(str2,time1);
                                            strcat(c.date_time,str2);
                                            strcat(c.statement[c.i], str2);
                                            fwrite(&c,sizeof(c),1,fp);
                                            fclose(fp);
                                            printf("\033[36m");
                                            printf("\n                                        Amount of Rs %d is credited successfully...!",amt);
                                            printf("\n");
                                            printf("\033[33m");
                                            printf("\n                                        Remaining amount in your account Rs %d",c.balance);
                                            printf("\n");
                                            fclose(f);
                                            remove(filename);
                                            rename("temp.dat",filename);
                                        }
                                    else
                                        {
                                            printf("\033[31m");  // red
                                            printf("                                          Enter correct Denominations...!\n");
                                            printf("\033[37m");  // white
                                        }
                                    
                                        
                                }
                            else
                                {
                                    printf("\033[31m");  // red
                                    printf("                                Enter amount only in multiples of 50's (or) 100's (or) 200's (or) 500's (or) 2000's\n"); 
                                    printf("\033[37m");  // white
                                }  
                        }
            
                }
        fclose(f);
   
    }

void totaladd(int thous, int fives, int twos, int hunds, int fiftys)
    {
        struct atm a;
        FILE *pntr;
        pntr = fopen("totalamount.dat", "rb");
        if (pntr == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, pntr))
            {
                FILE *ptr5;
                ptr5 = fopen("details.dat","ab");
                a.thous = a.thous + thous;
                a.fives = a.fives + fives;
                a.twos = a.twos + twos;
                a.hunds = a.hunds + hunds;
                a.fiftys = a.fiftys + fiftys; 
                a.amount = (a.thous*2000) + (a.fives*500) + (a.twos*200) + (a.hunds*100) + (a.fiftys*50);
                fwrite(&a, sizeof(a), 1, ptr5);
                fclose(ptr5);
            }
            
        fclose(pntr);
        remove("totalamount.dat");
        rename("details.dat", "totalamount.dat");

    }

void totalsub(int thous, int fives, int twos, int hunds, int fiftys)
    {
        struct atm a;
        FILE *ptnr1;
        ptnr1 = fopen("totalamount.dat", "rb");
        if (ptnr1 == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, ptnr1))
            {
                FILE *ptr7;
                ptr7 = fopen("details.dat","ab");
                a.thous = a.thous - thous;
                a.fives = a.fives - fives;
                a.twos = a.twos - twos;
                a.hunds = a.hunds - hunds;
                a.fiftys = a.fiftys - fiftys; 
                a.amount = (a.thous*2000) + (a.fives*500) + (a.twos*200) + (a.hunds*100) + (a.fiftys*50);
                fwrite(&a, sizeof(a), 1, ptr7);
                fclose(ptr7);
            }
            
        fclose(ptnr1);
        remove("totalamount.dat");
        rename("details.dat", "totalamount.dat");

    }

void display()
    {
        struct atm a;
        FILE *ptr6;
        ptr6 = fopen("totalamount.dat", "rb");
        if (ptr6 == NULL)
            {
                printf("\nError Occured while opening a file...!");
            }
        while(fread(&a, sizeof(a), 1, ptr6))
            {
                printf("\ntotalamount: %d\n", a.amount);
                printf("\nno of 2000's are %d\n", a.thous);
                printf("\nno of 500's are %d\n", a.fives);
                printf("\nno of 200's are %d\n", a.twos);
                printf("\nno of 100's are %d\n", a.hunds);
                printf("\nno of 50's are %d\n", a.fiftys);
            }
        fclose(ptr6);
    }

int transfer()
    {
        struct atm a;
        FILE *ptr6;
        int temp;
        ptr6 = fopen("totalamount.dat", "rb");
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

int username_verify(char* name_verify)
    {
        DIR* dir = opendir("E:\RISHI\Atm");
        char name[150];
        //Sleep(2000);
        strcpy(name, name_verify);
        if(dir == NULL)
            {
                printf("No such directory found...!\n");
            }
        else 
            {
                struct dirent* file;
                file = readdir(dir);
                while(file != NULL)
                    {
                        
                        char name1[150];
                        strcpy(name1, file->d_name);
                        char ch = '.';
                        char *file_name = name1;
                        char name2[150];
                        char *new_name = name2;
                        int i = 0;
                        while(*file_name != ch)
                            {
                                *new_name = *file_name;
                                file_name++;
                                new_name++;
                                i++;
                            }
                            name2[i] = '\0';
                            if(strcmp(name2, name) == 0)
                                {
                                    return 1;
                                }
                        file = readdir(dir); 
                    }
                closedir(dir);              
                
            }
        return 0;
    }

