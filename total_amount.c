#include<stdio.h>

struct atm
    {
        float amount;
    };

int main()
    {
        struct atm a;
        a.amount =1000000;
        FILE *p;
        p = fopen("C:\\Users\\vasuy\\OneDrive\\ATM\\totalamount\\totalamount.dat", "w");
        fwrite(&a, sizeof(a), 1, p);
        fclose(p);

        return 0;

    }