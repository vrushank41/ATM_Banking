#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>

int main();
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

