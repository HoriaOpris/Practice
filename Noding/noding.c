#include <stdlib.h>

struct node
{
    int value;
    struct node *next_element;
};

struct node first_element;

void AddNode(int value)
{
    struct node *current = &first_element;

    while (current->next_element != NULL)
    {
        current = current->next_element;
    }

    current->value = value;
    struct node *local = malloc(sizeof(struct node));

    if (local != NULL)
    {
        local->value = 0;
        local->next_element = NULL;
        current->next_element = local;
    }
}

int main(void)
{
    AddNode(1);
    AddNode(2);
    AddNode(3);

    return 0;
}