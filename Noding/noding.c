#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node first_element;

void AddNode(struct node **node, int value)
{
    if (*node == NULL)
    {
        *node = malloc(sizeof(struct node));
        (**node).value = value;
    }
    else
    {
        if (value <= (**node).value)
        {
            AddNode(&(**node).left, value);
        }
        else
        {
            AddNode(&(**node).right, value);
        }
    }
}

int main(void)
{
    first_element.value = 100;
    struct node *node = &first_element;

    AddNode(&node, 45);
    AddNode(&node, 145);
    AddNode(&node, 60);

    return 0;
}