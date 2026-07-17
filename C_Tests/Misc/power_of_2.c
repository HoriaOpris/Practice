#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
uint32_t power_of_2_loop(uint32_t n)
{
    if (n > 0)
    {
        uint32_t count_set_bits = 0;

        for (uint32_t i = 0; i < 32; i++)
        {
            if (((n >> i) & 1) == 1)
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
    if (n > 0)
    {
        return ((n & (n - 1)) == 0);
    }
    else
    {
        return 0;
    }
}

#define CLAMP(n, min, max) ((n < min) ? min : ((n > max) ? max : n))

// Input   00000000000000000000000000001101
// Output  10110000000000000000000000000000
uint32_t reverse_bits(uint32_t x)
{
    uint32_t reversed = 0U;
    uint32_t shift;
    uint32_t mask;
    for (uint32_t i = 31U; i > 0U; i--)
    {
        shift = (x << i);
        mask = (1U << 31U);
        reversed |= (shift & mask) >> (31U - i);
    }

    return reversed;
}

float temperature_from_adc(uint16_t adc);
static bool fan_control(float temperature);

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

    printf("%d\n", CLAMP(15, 0, 10));
    printf("%d\n", CLAMP(-5, 0, 10));
    printf("%d\n", CLAMP(5, 0, 10));

    printf("\nReverse of %x is %x\n\n", 0x0000000D, reverse_bits(0x0000000D));

    printf("Interpolate %d, %f\n", 500, temperature_from_adc(500));
    printf("Interpolate %d, %f\n", 750, temperature_from_adc(750));
    printf("Interpolate %d, %f\n", 1750, temperature_from_adc(1750));
    printf("Interpolate %d, %f\n", 2000, temperature_from_adc(2000));
    printf("Interpolate %d, %f\n", 2500, temperature_from_adc(2500));
    printf("Interpolate %d, %f\n\n", 1100, temperature_from_adc(1100));

    printf("Temperature is %f, Fan is:%d\n", 22.0f, fan_control(22.0f));
    printf("Temperature is %f, Fan is:%d\n", 26.0f, fan_control(26.0f));
    printf("Temperature is %f, Fan is:%d\n", 36.0f, fan_control(36.0f));
    printf("Temperature is %f, Fan is:%d\n", 19.0f, fan_control(19.0f));
}

// find every bug
int max(int *arr, int size)
{
    int max = 0;

    // no input checking.
    // for example, size could be negative. size could be changed to size_t
    // or arr could be null
    // or size could be max int and then you'd have an infinite loop below
    for (int i = 0; i <= size; i++) // overflow arr due to <= sign of size
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

struct lookup_table
{
    uint16_t ADC_count;
    float temperature;
};

#define TABLE_SIZE (5u)

struct lookup_table table[TABLE_SIZE] =
    {
        {0, -40},
        {500, 0},
        {1000, 40},
        {1500, 80},
        {2000, 120},
};

static void GetXCoordinates(uint16_t adc, uint16_t *c1, uint16_t *c2)
{
    for (uint32_t i = 0; i < TABLE_SIZE - 1; i++)
    {
        if ((adc >= table[i].ADC_count) && ((adc <= table[i + 1].ADC_count)))
        {
            *c1 = i;
            *c2 = i + 1;
            return;
        }
    }
}

float interpolate(uint16_t x1, uint16_t x2, float y1, float y2, uint16_t x)
{
    uint16_t dx = x2 - x1;
    float dy = y2 - y1;
    float t = (float)(x - x1) / (float)dx;

    return (t * dy) + y1;
}

float temperature_from_adc(uint16_t adc)
{
    uint16_t c1, c2;
    if (adc > 2000)
    {
        adc = 2000; // clamp to 2000 max. explicit 0 clamp not needed as adc is unsigned
    }

    GetXCoordinates(adc, &c1, &c2);
    return interpolate(table[c1].ADC_count, table[c2].ADC_count, table[c1].temperature, table[c2].temperature, adc);
}

// 7. Hysteresis
// A fan should:
// * turn ON at 30°C
// * turn OFF at 25°C
static bool fan_control(float temperature)
{
    static bool isFanOn = false;

    if (temperature >= 30)
    {
        isFanOn = true;
    }
    else if (temperature <= 25)
    {
        isFanOn = false;
    }

    return isFanOn;
}

