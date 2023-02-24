#ifndef __NODE_H__
#define __NODE_H__

typedef struct node node;

struct node
{
    int position; //node position on the stack
    char firstname[20]; //student's fisrt name  
    char lastname[20]; //student's last name
    char netid[20]; // student's netid
    // int value;
    node *next;
};

// list of operations on the stack 
int QueryOption();
void ExecuteOption(const int option, node** top);
void DisplayOptions();
void Push(const char *firstname, const char *lastname, const char *netid, node** top);
void Pop(node** top, char *firstname, char *lastname, char *netid);
void Peek(node *top, char *firstname, char *lastname, char *netid);
void DisplayStack(node* top);
void PrintNode(node* top);
void GetStackSize(node* top, int* stack_size);
void DeleteStack(node** top);

#endif