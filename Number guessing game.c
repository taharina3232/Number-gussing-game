#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number;

    srand(time(0));

    number = rand() % 10 + 1;

    printf("Welcome to Number Guessing Game!\n");
    printf("Guess a number between 1 and 10:\n");

    while (1) {
        scanf("%d", &guess);

        if (guess < number) {
            printf("Enter a bigger number.\n");
        }
        else if (guess > number) {
            printf("Enter a smaller number.\n");
        }
        else {
            printf("Congratulations! You guessed the right number!\n");
            break;
        }
    }

    printf("Game Over.\n");
    return 0;
}
