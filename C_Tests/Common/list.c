//Implements list data type
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

void Add(struct list *l, int data)
{
    struct list *p = l;

    while (p->next != NULL)
        p = p->next;

    p->next = malloc(sizeof(struct list));
    p->next->data = data;
    p->next->next = NULL;
}

unsigned Size(struct list *l)
{
    struct list *p = l;
    unsigned size = 1;

    while (p->next != NULL)
    {
        size++;
        p = p->next;
    }

    return size;
}

void Rem(struct list *l)
{
    struct list *p = l;

    for (unsigned i = 0; i < Size(l) - 2; i++)
        p = p->next;

    p->next = NULL;
}

int main(void)
{
    struct list l = {.data = 0, .next = NULL};
    char input;
    unsigned cnt = 3;

    do
    {
        printf("\nEnter + or - or p: ");
        scanf("%c", &input);

        if (input == '+')
        {
            Add(&l, cnt);
            cnt++;
        }

        if (input == '-')
        {
            Rem(&l);
        }

        if (input == 'p')
        {
            struct list *p = &l;

            printf("\n---\n");
            for (unsigned i = 0; i < Size(&l); i++)
            {
                printf("data:%d pointer:%x\n", p->data, (unsigned)p->next);
                p = p->next;
            }
        }

    } while (input != 'q');
}
