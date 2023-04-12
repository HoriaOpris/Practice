#include <stdio.h>

static unsigned int compute_total_price(unsigned int unit_price, unsigned int macaron_count, char macarons[255][20])
{
    return 0;
}

static void Test1(void)
{
    char macaron[6][20] = {"vanilla", "banana", "apple", "cherry", "peach", "lemon"};

    if (compute_total_price(1, 6, macaron) == 4)
    {
        printf("Test 1 passed\n");
    }
    else
    {
        printf("Test 1 failed: %d\n", compute_total_price(1, 6, macaron));
    }
}

static void Test2(void)
{
    char macaron[4][20] = {"vanilla", "apple", "vanilla", "apple"};

    if (compute_total_price(2, 4, macaron) == 14)
    {
        printf("Test 2 passed\n");
    }
    else
    {
        printf("Test 2 failed: %d\n", compute_total_price(2, 4, macaron));
    }
}

int main(void)
{
    Test1();
    Test2();

    return 0;
}