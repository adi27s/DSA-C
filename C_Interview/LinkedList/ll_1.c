#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node
{
    int value;
    struct linked_list_node *next; // Self referential pointer
    struct linked_list_node *prev;
} node_t;

int main(int argc, char **argv)
{

    system("clear");
    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *temp = head;
    head->next = NULL;
    temp = head;
    for (int i = 1; i < 6; i++)
    {
        node_t *ll_node = (node_t *)malloc(sizeof(node_t));
        temp->next = ll_node;
        temp = ll_node;
        temp->value = i;
        temp->next = NULL;
    }

    temp = head->next;
    int size = 0;
    while (temp != NULL)
    {
        printf("temp->value = %d\n", temp->value);
        temp = temp->next;
        ++size;
    }

    printf("Size : %d\n", size);

    temp = head;
    while (temp->next != NULL)
    {
        node_t *next_node = temp->next; // Save next node before freeing
        free(temp);
        temp = next_node;
    }

    temp = NULL;
    return 0;
}