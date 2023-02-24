#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

void Push(const char *firstname, const char *lastname, const char *netid, node** top)
{
    if (*top == NULL)
    {   
        *top =(node*)malloc(sizeof(struct node));
        (*top)->next = NULL;
        strcpy((*top)->firstname, firstname);
        strcpy((*top)->lastname, lastname);
        strcpy((*top)->netid, netid);
        (*top)->position = 1;
    }
    else
    {
        node* temp;
        temp =(node*)malloc(sizeof(struct node));
        temp->next = *top;
        strcpy(temp->firstname, firstname);
        strcpy(temp->lastname, lastname);
        strcpy(temp->netid, netid);
        temp->position = 1;
        *top = temp;

        node* ptr = (*top)->next;
        while (ptr!=NULL)
        {
        ptr->position = ptr->position+1;
        ptr = ptr->next;
        }
    }
}