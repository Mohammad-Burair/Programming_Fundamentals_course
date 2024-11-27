/* 
   Name: Mohammad Burair
   Roll Number: 24k-0775
   Section: BCS-1C
   Description: Program to populate a 6x5 character array with random letters and numbers, and allow the user to search for strings horizontally or vertically.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void fill(char arr[6][5]) {
    // Fill array with random characters A-Z and a specific numeric code at the end row
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = 'A' + (rand() % 26);
        }
    }
    arr[5][0] = '0';
    arr[5][1] = '7';
    arr[5][2] = '7';
    arr[5][3] = '5';
}

void disparr(char arr[6][5]) {
    // Display the 6x5 character array
    printf("\nCharacter Array:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int search(char arr[6][5], const char *str) {
    int len = strlen(str);

    // Search horizontally
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            if (strncmp(&arr[i][j], str, len) == 0) {
                return 1; // Found horizontally
            }
        }
    }

    // Search vertically (top to down)
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i <= 5 - len; i++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1; // Found vertically
            }
        }
    }

    return 0; // Not found
}

int main() {
    char characters[6][5];
    char input[100];
    int score = 0;

    srand(time(NULL)); // Seed random number generator

    while (1) {
        fill(characters);
        disparr(characters);

        while (1) {
            printf("Enter a string to search (or type 'END' to repopulate or 'EXIT' to quit): ");
            scanf("%s", input);

            if (strcmp(input, "EXIT") == 0) {
                printf("Exiting the game. Final score: %d\n", score);
                return 0; // Exit the game gracefully
            }

            if (strcmp(input, "END") == 0) {
                break; // Break out of inner loop to repopulate the array
            }

            if (search(characters, input)) {
                score++; // Increment score if found
                printf("%s is present. Score: %d\n", input, score);
            } else {
                score--; // Decrement score if not found
                printf("%s is not present. Score: %d\n", input, score);
            }
        }
    }

    return 0;
}

