                        //A New Text Editor

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*MAX_F_L - Max length of the file name
  MAX_T_L - Max length of the text
  f_name - File name
  content - Content of the file
  */

#define MAX_F_L 100
#define MAX_T_L 1000


void save_file(const char* f_name, const char* content)
{
    FILE* file = fopen(f_name, "w");
    if (file == NULL) {
        printf("\n\n\n\t\t*Error: Unable to open file %s..\n", f_name);
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}



void main()
{
    //Declare the variable

    char f_name[MAX_F_L];
    char content[MAX_T_L];
    char c;
    int i = 0;

    printf("\n\t\t\t\t\t........CONSOLE TEXT EDITOR........");
    printf("\n\n\n\t\tEnter the filename(with extension & no spaces, ex: abc.txt) : ");
    scanf("%s",f_name);

    // Clear input buffer
    while((c = getchar()) != '\n' && c != EOF);

    printf("\n\n\t\tEnter the content\n\t\t(type 'exit' on a new line to save and exit) : \n\n");

    printf("...................................................................................\n\n");

    while(1)
    {

        c = getchar();

        //check the exit command
        if(c == 'e')
        {
            if (getchar() == 'x')
            {
                if (getchar() == 'i')
                {
                    if (getchar() == 't')
                    {
                        break;
                    }
                }
            }
        }


        //Check if the buffer is full
        if(i >=MAX_T_L - 1)
        {
            printf("\n\n\n\t\t*WARNING: Maximum string length reached. Save the current content.....");
            break;
        }


            // Append character to content
            content[i++] = c;

    }

        printf("\n...................................................................................\n");

        content[i] = '\0';

        save_file(f_name, content);

        printf("\n\n\n\t\tFile saved successfully. Exiting....\n");


getch();
}
