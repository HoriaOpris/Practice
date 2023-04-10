#include <stdio.h>
#include <string.h>

/* In text processing tasks, one of the first things to do is figure out how
 often each word appears in a give document. In this task, you will be
 completing a function that returns the unique word frequencies of a tokenized
 word document */

/* return an array of integers containing the number of occurences of each
word sorted alphabetically.

Example
['the', 'dog', 'got', 'the', 'bone']

Output: [1, 1, 1, 2] bone = 1, dog = 1, got = 1, the = 2
*/
static void count_frequencies(int n, char words[255][257], int *counts_count)
{
    // sort alphabetically;
    for (int i = 0; i < n - 1; i++)
    {
        if (strcmp(&words[i][0], &words[i + 1][0]) > 0)
        {
            char temp[257];
            strcpy(temp, &words[i][0]);
            strcpy(&words[i][0], &words[i + 1][0]);
            strcpy(&words[i + 1][0], temp);
            i = -1;
        }
    }

    // count occurences
    int count_position = 0;
    for (int i = 0; i < n; i++)
    {
        counts_count[count_position] = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(&words[i][0], &words[j][0]) == 0)
            {
                counts_count[count_position]++;
                i++;
            }
        }

        count_position++;
    }
}

#define SIZE_TEST_1 5

static void Test1(void)
{
    char words[SIZE_TEST_1][257] = {"the", "dog", "got", "the", "bone"};
    int counts_count[SIZE_TEST_1];

    count_frequencies(SIZE_TEST_1, words, counts_count);

    if ((counts_count[0] == 1) && (counts_count[1] == 1) && (counts_count[2] == 1) && (counts_count[3] == 2))
    {
        printf("Test 1 passed.\n");
    }
    else
    {
        printf("Test 1 failed! %d %d %d %d \n", counts_count[0], counts_count[1], counts_count[2], counts_count[3]);
    }
}

#define SIZE_TEST_2 8

static void Test2(void)
{
    char words[SIZE_TEST_2][257] = {"the", "dog", "got", "the", "bone", "vineyard", "truck", "vineyard"};
    int counts_count[SIZE_TEST_2];

    count_frequencies(SIZE_TEST_2, words, counts_count);

    if ((counts_count[0] == 1) && (counts_count[1] == 1) && (counts_count[2] == 1) && (counts_count[3] == 2) &&
        (counts_count[4] == 1) && (counts_count[5] == 2))
    {
        printf("Test 2 passed.\n");
    }
    else
    {
        printf("Test 2 failed! %d %d %d %d %d %d\n", counts_count[0], counts_count[1], counts_count[2], counts_count[3], counts_count[4], counts_count[5]);
    }
}

int main(void)
{
    Test1();
    Test2();

    return 0;
}