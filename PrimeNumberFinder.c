#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to write prime numbers to a file
void write_primes_to_file(int start, int end, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Prime numbers between %d and %d:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            fprintf(file, "%d\n", num);
        }
    }

    fclose(file);
    printf("Prime numbers have been written to %s\n", filename);
}

int main() {
    int start, end;

    // Get range from user
    printf("Enter the starting number of the range: ");
    scanf("%d", &start);
    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    // Validate the range
    if (start > end) {
        printf("Invalid range! Starting number should be less than or equal to the ending number.\n");
        return 1;
    }

    // Define the output file name
    const char *filename = "primes.txt";

    // Find and save primes to the file
    write_primes_to_file(start, end, filename);

    return 0;
}
