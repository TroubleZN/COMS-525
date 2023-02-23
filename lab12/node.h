#ifndef __NODE_H__
#define __NODE_H__

typedef struct node node;

struct node
{
    int position;
    int stuid;
    char firstname;
    char lastname;
    node *next;
};


// list of operations on the stack 
int QueryOption();
void ExecuteOption(const int option, node** top);
void DisplayOptions();
void Push(const int input, node** top);
void Pop(node** top, int* output);
int Peek(node* top);
void DisplayStack(node* top);
void PrintNode(node* top);
void GetStackSize(node* top, int* stack_size);
void DeleteStack(node** top);

#endif