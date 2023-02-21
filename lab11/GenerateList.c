#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"


void GenerateList(node** head, const int num_nodes)
{
    node* temp; srand( time(NULL) );
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };

    for (int i=0; i<num_nodes; i++)
    {
        temp = (node*)malloc(sizeof(node));
        temp->value = alphabet[rand()%num_nodes]; 
        temp->position = 0;
        printf("%4c",temp->value);

        if (*head == NULL)
        {
            *head = temp;
            (*head)->next = NULL;
        }
        else
        {
            temp->next = *head;
            *head = temp;
        }
    }

    printf("\n");

    node* ptr = *head; int pos = 1;
    while(ptr!=NULL)
    {
        ptr->position = pos;
        pos = pos+1;
        ptr = ptr->next;
    }
}