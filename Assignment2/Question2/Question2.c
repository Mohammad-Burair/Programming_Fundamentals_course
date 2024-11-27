/* 
   Name: Mohammad Burair
   Roll Number: 24k-0775
   Section: BCS-1C
   Description: Program to count and display the frequency of letters in slogans.
*/

#include <stdio.h>
#include <string.h>

void countLetters(char str[]); // function prototype

int main() {
    int n;

    printf("Enter number of slogans: ");
    scanf("%d", &n);
    getchar(); // Consume the leftover newline from the integer input

    char str[n][50];

    for (int i = 0; i < n; i++) {
        printf("\nSlogan %d: ", i + 1);
        fgets(str[i], 50, stdin);
        str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline character
    }

    for (int i = 0; i < n; i++) {
        printf("\nFor slogan %d: \"%s\"\n", i + 1, str[i]);
        countLetters(str[i]);
    }

    return 0;
}

void countLetters(char str[]) {
    int freq[256] = {0}; // Frequency array for ASCII characters

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') { // Ignore spaces
            freq[(int)str[i]]++;
        }
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c': %d\n", i, freq[i]);
        }
    }
}

