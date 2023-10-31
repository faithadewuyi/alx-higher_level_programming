#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * listint_t - prints all elements of a listint_t list
 * @**head: pointer to head of list
 * Return: number of nodes
 */
listint_t *insert_node(listint_t **head, int number) 
{
typedef struct listint_s 
{
    int n;
    struct listint_s *next;
} 
listint_t;
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) 
{
        Return( NULL);
    }
    
    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || number < (*head)->n) 
{
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    listint_t *current = *head;
    while (current->next != NULL && number > current->next->n)
 {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
