#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
static int input[SIZE][SIZE];

static void GetInput(int arr[SIZE][SIZE])
{
    FILE *ptr;
    char ch;
    static int i, j;

    // Opening file in reading mode
    ptr = fopen("small_input.txt", "r");

    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }

    char str[10] = "\0";
    char add[2] = "\0";
    do
    {
        ch = fgetc(ptr);
        printf("%c", ch);

        add[0] = ch;
        strcat(str, add);
        if (ch == ',')
        {
            arr[i][j] = atoi(str);
            j++;
            memset(str, 0, 10);
        }
        else if (ch == '\n')
        {
            arr[i][j] = atoi(str);
            i++;
            j = 0;
            memset(str, 0, 10);
        }

        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);

    // Closing the file
    fclose(ptr);
}

int main(void)
{
    GetInput(input);
}