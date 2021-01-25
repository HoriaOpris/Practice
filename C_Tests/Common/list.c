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

int main(void)
{
    struct list l = {.data = 0, .next = NULL};

    Add(&l, 1);
    Add(&l, 2);
    Add(&l, 3);

    struct list *p = &l;

    for (unsigned i = 0; i < Size(&l); i++)
    {
        printf("data:%d pointer:%x\n", p->data, (unsigned)p->next);
        p = p->next;
    }
}
