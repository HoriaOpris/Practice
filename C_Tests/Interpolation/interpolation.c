#include<stdio.h>

float adc_lookup[4][4] = 
{
    {0, -40},
    {1000, 20},
    {2000, 60},
    {3000, 100}
};

float interpolate(float x1, float y1, float x2, float y2, float x)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float t = (x-x1)/dx;

    return (t * dy) + y1;
}

int main(void)
{   
    printf("ADC: %f = %f Degrees\n", adc_lookup[1][0], adc_lookup[1][1]);
    printf("ADC: %f = %f Degrees\n", 1127.996, interpolate(1000,20,2000,60,1127.996));
    printf("ADC: %f = %f Degrees\n", 1250.0, interpolate(1000,20,2000,60,1250));
    printf("ADC: %f = %f Degrees\n", 1500.0, interpolate(1000,20,2000,60,1500));
    printf("ADC: %f = %f Degrees\n", 1750.0, interpolate(1000,20,2000,60,1750));
    printf("ADC: %f = %f Degrees\n", adc_lookup[2][0], adc_lookup[2][1]);

    return 0;
}