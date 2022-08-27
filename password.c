#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

int main()
    {
        char pass[5];
        //printf("\nlength is %d\n", strlen(pass));
        printf("Enter your password: ");
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
                         //printf("\033[33m");
                        printf("%c", 1);
                        i++;
                    }
                    //printf("\nlength is %d\n", strlen(pass));

                
            }
        pass[i] = '\0';
        //printf("\nlength outside of while is %d\n", strlen(pass));
        printf("\nEntered password is %s", pass);
        return 0;

    }