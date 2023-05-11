#include <stdio.h>
#include <string.h>

static unsigned int compute_total_price(unsigned int unit_price, unsigned int macaron_count, char macarons[255][20])
{
    // sort alphabetically;
    for (int i = 0; i < macaron_count - 1; i++)
    {
        if (strcmp(macarons[i], macarons[i + 1]) > 0)
        {
            char temp[257];
            strcpy(temp, macarons[i]);
            strcpy(macarons[i], macarons[i + 1]);
            strcpy(macarons[i + 1], temp);
            i = -1;
        }
    }

    for (int i = 0; i < macaron_count; i++)
    {
        printf("%s ", macarons[i]);
    }
    printf("\n");

    int sets[10];
    int set_index = 0;
    for (int i = 0; i < macaron_count - 1; i++)
    {
        if (macarons[i][0] != 'v')
        {
            if(strcmp(macarons[i], macarons[i + 1]) == 0)
            {

            }
            else if (sets[set_index] == 5)
            {
                set_index++;
                i = 0;
            }
            else
            {
                macarons[i][0] = 'v';
                sets[set_index]++;
            }

            printf("%s ", macarons[i]);
        }
    }

    for (int i = 0; i <= set_index; i++)
    {
        printf("Set[%d] = %d\n", i, sets[i]);
    }
    printf("\n");

    return 0;
}

static void Test1(void)
{
    char macaron[6][20] = {"vanilla", "banana", "apple", "cherry", "peach", "lemon"};
    int total_price = compute_total_price(1, 6, macaron);

    if (total_price == 4)
    {
        printf("Test 1 passed\n");
    }
    else
    {
        printf("Test 1 failed: %d\n", total_price);
    }
}

static void Test2(void)
{
    char macaron[4][20] = {"vanilla", "apple", "vanilla", "apple"};
    int total_price = compute_total_price(2, 4, macaron);

    if (total_price == 14)
    {
        printf("Test 2 passed\n");
    }
    else
    {
        printf("Test 2 failed: %d\n", total_price);
    }
}

int main(void)
{
    Test1();
    Test2();

    return 0;
}