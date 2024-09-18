#include <stdio.h>
#include <stdlib.h>

int main() {
   int input_list[] = {1,2,4,5,6,7,8,9,10};
   int k = 4;
   int i;
   int length = sizeof(input_list)/sizeof(input_list[0]);
    
   for (i = 0; i < length - 1; i++)
   {
    if (input_list[i] + input_list[i+1] == k)
    {
        printf("True");
        return 0;
    }
    else
    {
        printf("False");
        return 0;
    }
    
   }
}