#include <stdio.h>

int main() {
    int arr[] = {10, 20, 5, 8, 50};
    int max = arr[0], n = 5;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    printf("Largest element: %d\n", max);
    return 0;
}
