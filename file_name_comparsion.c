#include<dirent.h>
#include<stdio.h>
#include<string.h>

int main()
    {
        DIR* dir = opendir("C:\\Users\\vasuy\\OneDrive\\ATM\\coustmers");
        char name[50];
        printf("please Enter the text: ");
        scanf("%s", name);
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
                                    printf("sorry, username already taken...!\n");
                                    break;
                                }
                        file = readdir(dir); 
                    }
                closedir(dir);              
                
            }
        return 0;
    }