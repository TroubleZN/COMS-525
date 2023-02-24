#include "node.h"
#include<stdio.h>
#include<string.h>

void Peek(node *top, char *firstname, char *lastname, char *netid)
{   
    strcpy(lastname, top->lastname);
    strcpy(firstname, top->firstname);
    strcpy(netid, top->netid);
}

