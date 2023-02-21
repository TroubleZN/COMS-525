#include <stdio.h>

int GetKey()
{
    char key[1];
    printf("\n Enter key to search: ");
    scanf("%s", key);

    return key[0];
}