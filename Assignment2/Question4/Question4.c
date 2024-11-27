/* 
   Name: Mohammad Burair
   Roll Number: 24k-0775
   Section: BCS-1C
   Description: Program to group words that share common characters and print them in reverse order.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

bool hasCommonCharacter(char word1[], char word2[]) {
    // Check if two words have any character in common
    for (int i = 0; word1[i] != '\0'; i++) {
        for (int j = 0; word2[j] != '\0'; j++) {
            if (word1[i] == word2[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;

    printf("Enter the number of words: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character left by scanf

    char arr[n][MAX_WORD_LENGTH];
    bool grouped[n]; // To track if a word has already been grouped
    for (int i = 0; i < n; i++) {
        grouped[i] = false;
    }

    // Input words
    for (int i = 0; i < n; i++) {
        printf("Enter the %d word: ", i + 1);
        fgets(arr[i], MAX_WORD_LENGTH, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove the newline character from the input
    }

    // Process and group words
    for (int i = n - 1; i >= 0; i--) {
        if (grouped[i]) continue; // Skip already grouped words

        printf("[");
        bool firstWord = true;

        // Start a new group with the word at index i
        for (int j = i; j >= 0; j--) {
            if (!grouped[j] && hasCommonCharacter(arr[i], arr[j])) {
                if (firstWord) {
                    printf("%s", arr[j]);
                    firstWord = false;
                } else {
                    printf(",%s", arr[j]);
                }
                grouped[j] = true; // Mark this word as grouped
            }
        }
        printf("],");
    }

    return 0;
}

