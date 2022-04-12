// Usman Khan
// CS 2211a
// October 11, 2020
// 251036415

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array[] = {12,63,44,89,3,55,73,27,37,18};
	int lengthBits = sizeof(array);
	printf("Size of the array : %d bytes",lengthBits);
	int lengthArray = sizeof(array) / sizeof (array [0]);
      	printf("\nLength of the array : %d elements ",lengthArray);
	printf("\n\nPART 1:");	
	printf("\nThe values store into the array are :\n");
	int i = 0;
	for (i = 0; i < lengthBits; i++);
	{
	printf("%d ",array[i]);
	}























return 0;
}
