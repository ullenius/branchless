#include <stdio.h>

int single_digit(int n);

int main() {
    printf("single digit: %d, %s\n", 7, single_digit(7) ? "true" : "false");
    printf("single digit: %d, %s\n", 42, single_digit(42) ? "true" : "false");

    return 0;
}

int single_digit(const int n) {
    return (n % 10) == n;
}
