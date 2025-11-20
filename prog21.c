#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive number: ");
    scanf("%d", &n);

    printf("Even numbers from 1 to %d are:\n", n);
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
