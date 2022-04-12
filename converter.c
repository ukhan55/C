// Usman Khan
// CS 2211a
// October 11, 2020
// 251036415
#include <stdio.h> 

int main()
{
int a,j,input,d;
while(1) { //while true
    a=0;
    printf("Input? ");
    scanf("%d",&input); //returns the memory location of the variable "input" and interprets it as a integer value
        if (input==0) break; //this will "break" the code if input==0
            for (int i=i;i<=input;i++){ //i will loop through the inputted vales until i is greated than the input
                d = 0; 
                for (j=2; j <= i; j++) //nested inner for loop that will run behind the last i value
                    if (i%j==0) d++; //if i mod j is an even number, increment d by 1
                        if (d==1) a=a+i; //if d is equal to 1, then a=a+e
        }
printf("The final total is: %d\n",a); //final value of a is printed
}
return 0;
} 








