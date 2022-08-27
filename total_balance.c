#include "atm.h"


void totaladd(float total_amt)
    {
        struct atm a;
        FILE *pntr;
        pntr = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (pntr == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, pntr))
            {
                FILE *ptr5;
                ptr5 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat","ab");
                a.amount = a.amount + total_amt;
                fwrite(&a, sizeof(a), 1, ptr5);
                fclose(ptr5);
            }
            
        fclose(pntr);
        remove("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");
        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat", "C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");

    }

void totalsub(float total_amt)
    {
        struct atm a;
        FILE *ptnr1;
        ptnr1 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (ptnr1 == NULL)
            {
                printf("Error Occured while opening the FILE...!");
            }
        while(fread(&a, sizeof(a), 1, ptnr1))
            {
                FILE *ptr7;
                ptr7 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat","ab");
                a.amount = a.amount - total_amt;
                fwrite(&a, sizeof(a), 1, ptr7);
                fclose(ptr7);
            }
            
        fclose(ptnr1);
        remove("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");
        rename("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\details.dat", "C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat");

    }

void display()
    {
        struct atm a;
        FILE *ptr6;
        ptr6 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
        if (ptr6 == NULL)
            {
                printf("\nError Occured while opening a file...!");
            }
        while(fread(&a, sizeof(a), 1, ptr6))
            {
                printf("\ntotalamount: %.2f", a.amount);
            }
        fclose(ptr6);
    }

float transfer()
    {
        struct atm a;
        FILE *ptr6;
        float temp;
        ptr6 = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "rb");
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