#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0, n = 5;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum of array elements: %d\n", sum);
    return 0;
}
