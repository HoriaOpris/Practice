#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BUF_SIZE 4

uint8_t res[BUF_SIZE];
// Circular Buffer
// Implement:
// for a circular buffer of 16 bytes.
// No dynamic memory.

// 5 -> 8 ->empty
// 6 ->9 ->empty
// 7
struct circular_buffer
{
    uint8_t *current;
    uint8_t writei;
    uint8_t readi;
};

struct circular_buffer buf = {res, 0u, 0u};

bool push(uint8_t value)
{
    buf.writei = ((buf.writei + 1) % BUF_SIZE);
    buf.current[buf.writei] = value;

    if (buf.writei == buf.readi)
    {
        // buffer overflow
        buf.readi = ((buf.readi + 1) % BUF_SIZE);
        printf("\tindex:%d\n", buf.readi);
    }
}

bool pop(uint8_t *value)
{
    if (buf.writei == buf.readi)
    {
        // buffer is empty
        return 0;
    }

    *value = buf.current[buf.readi];

    buf.readi = ((buf.readi + 1) % BUF_SIZE);

    return 1;
}

int main(void)
{

    uint8_t val = 1;

    while (1)
    {
        uint8_t popped;
        uint32_t option;
        printf("enter option: \n");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            push(val++);
            break;

        case 1:
        {
            bool isOk;
            isOk = pop(&popped);
            printf("ok: %d popped: %d\n", isOk, popped);
        }
        break;

        case 2:
            printf("Buffer is: ");

            for (uint32_t i = 0; i < BUF_SIZE; i++)
            {
                printf("%d ", res[i]);
            }
            printf("\n");
            break;

        default:
            break;
        }
    }

    return 0;
}
