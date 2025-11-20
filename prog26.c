#include <stdio.h>

int main() {
    int correctPIN = 1234; // Predefined correct PIN
    int enteredPIN;
    int attempts = 0;
    int maxAttempts = 3;

    printf("Welcome to the ATM!\n");

    do {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == correctPIN) {
            printf("PIN accepted. Access granted!\n");
            break;  // Exit loop on correct PIN
        } else {
            printf("Incorrect PIN. Try again.\n");
            attempts++;
        }

        if (attempts == maxAttempts) {
            printf("Maximum attempts reached. Your account is locked.\n");
            break;
        }
    } while (1);

    return 0;
}
