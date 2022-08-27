#include<stdio.h>

int in(char*, char*);

int in(char *text1, char *text2)
    {
        int i = 0;
        while(*text1 && *text2)
            {
                if(*text1 == *text2)
                    {
                        if(i == 0)
                            {
                                text1++;
                                text2++;
                                i++;
                            }
                    }
                else
                    text2++;
            }
        return 0;
    }