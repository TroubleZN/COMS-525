#include <stdlib.h>
#include <stdio.h>
#include "node.h"

void DisplayStack(node* top)
{
    if (top==NULL)
    { printf(" Stack is emtpy.\n"); return; }

    printf(" ----------------------------------------------------------------------------\n");
    printf(" |Pos:|NetID: |First Name: |Last Name:  | Address:        | Next:           |\n");
    printf(" ----------------------------------------------------------------------------\n");
    PrintNode(top);
    printf(" ----------------------------------------------------------------------------\n");
}

void PrintNode(node* top)
{
    printf(" |%3i |%6s |%11s |%11s |%15p |%15p |\n",
    top->position , top->netid,top->firstname,top->lastname,top,top->next);
    if (top->next == NULL)
    { return; }
    PrintNode(top->next);
}