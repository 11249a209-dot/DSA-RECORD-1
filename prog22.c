#include <stdio.h>

int main() {
    int n, sum = 0, i = 1;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    while (i <= n) {
        sum += i;  // Add current number to sum
        i++;       // Move to next number
    }

    printf("Sum of first %d natural numbers is: %d\n", n, sum);

    return 0;
}
