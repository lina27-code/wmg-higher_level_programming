#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to head of list
 *
 * Return: pointer to new head
 */
listint_t *reverse_listint(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return (prev);
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to head of list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half;
    listint_t *first_half = *head;
    int result = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    /* Find middle of the list */
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    second_half = reverse_listint(slow);

    /* Compare first and second halves */
    while (second_half != NULL)
    {
        if (first_half->n != second_half->n)
        {
            result = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return (result);
}
