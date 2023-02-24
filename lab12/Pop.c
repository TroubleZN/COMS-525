#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include <string.h>

void Pop(node** top, char *firstname, char *lastname, char *netid)
{
    node* temp = *top;

    if (temp==NULL)
    { return; }
    else
    { temp = temp->next; }
    strcpy(firstname, (*top)->firstname);
    strcpy(lastname, (*top)->lastname);
    strcpy(netid, (*top)->netid);
    free(*top);
    *top = temp;

    node* ptr = *top;
    while (ptr!=NULL)
    {
        ptr->position = ptr->position -1;
        ptr = ptr->next;
    }
}