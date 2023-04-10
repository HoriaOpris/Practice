#include <stdio.h>

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
    char sorted[255][257];

    for (int i = 0; i < n; i++)
    {
        counts_count[i] = i;
    }
}

int main(void)
{
    // Test 1
    char words[4][257] = {"the", "dog", "the", "bone"};
    int counts_count[4];

    count_frequencies(4, words, counts_count);

    if ((counts_count[0] == 1) && (counts_count[1] == 1) && (counts_count[2] == 1) && (counts_count[3] == 2))
    {
        printf("Test 1 passed.\n");
    }
    else
    {
        printf("Test 1 failed! %d %d %d %d \n", counts_count[0], counts_count[1], counts_count[2], counts_count[3]);
    }

    return 0;
}