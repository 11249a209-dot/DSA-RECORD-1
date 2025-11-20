#include <stdio.h>

int main() {
    int arr[100], n, i, pos, value, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Traverse\n2. Insert\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Traversal
                printf("Array elements: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 2:  // Insertion
                printf("Enter position (1 to %d) to insert: ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);

                for (i = n; i >= pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos - 1] = value;
                n++;
                printf("Insertion successful.\n");
                break;

            case 3:  // Deletion
                printf("Enter position (1 to %d) to delete: ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                printf("Deletion successful.\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
