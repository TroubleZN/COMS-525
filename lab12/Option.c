#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int QueryOption()
{   
    int option;
    printf(" ENTER CHOICE : ");
    scanf("%i", &option);
    return option;
}

void ExecuteOption(const int option, node** top)
{
    char firstname[20];
    char lastname[20];
    char netid[20];
    int value;
    switch(option)
    {
        case 0: // Display available options
            DisplayOptions();
            break;

        case 1: // Enter a new value then push new node to stack
            printf(" Enter first name of the student: ");
            scanf("%s", firstname);
            printf(" Enter last name of the student: ");
            scanf("%s", lastname);
            printf(" Enter netid of the student: ");
            scanf("%s", netid);
            Push(firstname, lastname, netid, top);
            break;

        case 2: // Pop top value off of stack
            if (*top!=NULL)
            {
                Pop(top, firstname, lastname, netid);
                printf(" Pop student first name: %s\n", firstname);
                printf(" Pop student last name: %s\n", lastname);
                printf(" Pop student NetID: %s\n", netid);
            }
            else
            { printf(" Stack is empty.\n"); }
            break;

        case 3: // Peek at top value on stack
            if((*top)!=NULL)
            {   
                Peek(*top, firstname, lastname, netid);
                printf(" Top student first name: %s\n", firstname);
                printf(" Top student last name: %s\n", lastname);
                printf(" Top student NetID: %s\n", netid);
            }
            else
            { printf(" Stack is empty.\n"); }
            break; 

        case 4: // Display the entire stack
            DisplayStack(*top);
            break;

        case 5: // Print stack size
            GetStackSize(*top, &value);
            printf(" Stack size is %i\n",value);
            break;

        case 6: // Do nothing here, but this causes code to end
            break;

        default:
            printf("Error: incorrect option. Try again.\n");
            break;
    }
}