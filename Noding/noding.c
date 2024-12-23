#include <stdlib.h>

struct node
{
    int value;
    struct node *next_element;
};

struct node first_element;

void AddNode(struct node *node, int value)
{
    if(node->next_element == NULL)
    {
        node->value = value;

        node->next_element = malloc(sizeof(struct node));
        
        node->next_element->value = 0;
        node->next_element->next_element = NULL;
    }
    else
    {
        AddNode(node->next_element, value);
    }
}

int main(void)
{
    AddNode(&first_element, 1);
    AddNode(&first_element, 2);
    AddNode(&first_element, 3);

    return 0;
}