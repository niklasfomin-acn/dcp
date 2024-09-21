#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i, j;
    int input_list[] = {1, 2, 0, 3, 25, 0, 7, 8, 9};
    int length = sizeof(input_list) / sizeof(input_list[0]);
    int a;
    int smallest = input_list[length - 1] + 1;
    int found_one = 0;

    // sort the input list
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (input_list[i] > input_list[j])
            {
                a = input_list[i];
                input_list[i] = input_list[j];
                input_list[j] = a;
            }
        }
    }

    // print the sorted input list
    printArray(input_list, length);

    // find the smallest positive integer
    for (i = 0; i < length - 1; i++)
    {
        // check if the current element is positive
        if (input_list[i] <= 0)
        {
            continue;
        }

        if (input_list[i] == 1)
        {
            found_one = 1;
        }

        if (input_list[i] > 0 && input_list[i + 1] - input_list[i] > 1)
        {
            smallest = input_list[i] + 1;
            break;
        }
    }
    if (!found_one)
    {
        smallest = 1;
    }

    if (smallest == input_list[length - 1] && input_list[length - 1] > 1)
    {
        smallest = input_list[length - 1] + 1;
    }
    printf("The first smallest, missing, positive integer is: %d\n", smallest);
}