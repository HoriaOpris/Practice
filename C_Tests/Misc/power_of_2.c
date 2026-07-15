#include<stdio.h>
#include<stdint.h>

uint32_t power_of_2_loop(uint32_t n)
{
    if(n > 0)
    {
        uint32_t count_set_bits = 0;
        
        for(uint32_t i = 0; i<32; i++)
        {
            if(((n>>i) & 1)==1)
            {
                count_set_bits++;
            }
        }

        return (count_set_bits == 1);
    }
    else
    {
        return 0;
    }
}

uint32_t power_of_2_bit(uint32_t n)
{
    if(n > 0)
    {
        return ((n & (n-1)) == 0);
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    printf("%d is power of 2? %d\n", 1, power_of_2_loop(1));
    printf("%d is power of 2? %d\n", 2, power_of_2_loop(2));
    printf("%d is power of 2? %d\n", 128, power_of_2_loop(128));
    printf("%d is power of 2? %d\n", 129, power_of_2_loop(129));
    printf("%d is power of 2? %d\n", 0, power_of_2_loop(0));
    printf("%d is power of 2? %d\n\n", 512, power_of_2_loop(512));

    printf("%d is power of 2? %d\n", 1, power_of_2_bit(1));
    printf("%d is power of 2? %d\n", 2, power_of_2_bit(2));
    printf("%d is power of 2? %d\n", 128, power_of_2_bit(128));
    printf("%d is power of 2? %d\n", 129, power_of_2_bit(129));
    printf("%d is power of 2? %d\n", 0, power_of_2_bit(0));
    printf("%d is power of 2? %d\n\n", 512, power_of_2_loop(512));

    return 0;
}