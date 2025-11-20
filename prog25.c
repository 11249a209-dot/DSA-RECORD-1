#include <stdio.h>

int main() {
    char color;

    printf("Enter traffic light color (R for Red, Y for Yellow, G for Green): ");
    scanf(" %c", &color); // note the space before %c to ignore any newline

    if (color == 'R' || color == 'r') {
        printf("Stop!\n");
    } else if (color == 'Y' || color == 'y') {
        printf("Get Ready!\n");
    } else if (color == 'G' || color == 'g') {
        printf("Go!\n");
    } else {
        printf("Invalid color! Use R, Y, or G.\n");
    }

    return 0;
}
