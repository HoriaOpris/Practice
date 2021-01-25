//Implements list data type
#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

void Add(int data)
{
}

int main(void)
{
    struct list l = {.data = 0, .next = NULL};

    l.next = malloc(sizeof(struct list));
    l.next->data = 1;

    l.next->next = malloc(sizeof(struct list));
    l.next->next->data = 2;

    struct list *p = &l;
    for(unsigned i = 0; i < 3; i++)
    {
        printf("data:%d pointer:%x\n", p->data, (unsigned)p->next);
        p = p->next;
    }

}
