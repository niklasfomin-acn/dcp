#include <stdio.h>
#include <stdlib.h>

int *resultArray(int input_list[], int length)
{
    int i, j, n;
    int *result = (int *)malloc(length * sizeof(int));
    if (result == NULL)
    {
        printf("Memory not allocated.\n");
        exit(1);
    }

    // outer loop to iterate through the input list
    for (i = 0; i < length; i++)
    {
        int elements_right = length - i - 1;
        int elements_left = i;
        int product_counter_right = 1;

        // inner loop to iterate through the elements to the right of the current element
        for (j = i + 1; j < length; j++)
        {
            product_counter_right *= input_list[j];
        }

        result[i] = product_counter_right;

        int product_counter_left = 1;

        for (n = i; n > 0; n--)
        {
            product_counter_left *= input_list[n - 1];
        }

        result[i] *= product_counter_left;
    }

    return result;
}

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

    int input_list[] = {1, 2, 3};

    int length = sizeof(input_list) / sizeof(input_list[0]);

    int *result = resultArray(input_list, length);

    printArray(result, length);
}