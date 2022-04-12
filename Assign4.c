#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[] = "line of text";
    char * pname = name;
    printf("Enter a line of text:\n");
    fgets(name, 100, stdin); 
    pname = (char*) malloc(name *sizeof(char));
    
    
    printf("%s", name);
    return 0;
}