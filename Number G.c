#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void playGame();
void showScoreboard();

int main() {
    int choice;

    while (1) {
        printf("\n===== 🎯 NUMBER GUESSING GAME 🎯 =====\n");
        printf("1. Play Game\n");
        printf("2. Show Scoreboard\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showScoreboard();
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void playGame() {
    char name[50];
    int guess, number, attempts = 0;
    FILE *file;
    time_t t;

    srand(time(0));
    number = rand() % 10 + 1;

    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("Welcome, %s! Guess a number between 1 and 10:\n", name);

    while (1) {
        scanf("%d", &guess);
        attempts++;

        if (guess < number)
            printf("Enter a bigger number:\n");
        else if (guess > number)
            printf("Enter a smaller number:\n");
        else {
            printf("🎉 Congratulations %s! You guessed it in %d attempts!\n", name, attempts);
            break;
        }

        if (attempts >= 5) {
            printf("❌ Sorry %s, you've used all 5 attempts! The number was %d.\n", name, number);
            break;
        }
    }

    file = fopen("game_results.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    time(&t);
    if (guess == number)
        fprintf(file, "Player: %-10s | Attempts: %d | Result: WON  | Time: %s", name, attempts, ctime(&t));
    else
        fprintf(file, "Player: %-10s | Attempts: %d | Result: LOST | Time: %s", name, attempts, ctime(&t));

    fclose(file);
    printf("✅ Your result has been saved to 'game_results.txt'.\n");
}

void showScoreboard() {
    FILE *file;
    char line[200];

    file = fopen("game_results.txt", "r");
    if (file == NULL) {
        printf("⚠ No scoreboard found yet. Play a game first!\n");
        return;
    }

    printf("\n===== 🏆 SCOREBOARD 🏆 =====\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("\n============================\n");
}
