/* 
   Name: Mohammad Burair
   Roll Number: 24k-0775
   Section: BCS-1C
   Description: Program to determine how many matchsticks player A should pick in a matchstick game. 
*/

#include <stdio.h>

int match(int n) {
    if (n % 5 == 0) {
        return -1; // If divisible by 5, return -1 as a special case.
    } else {
        return n % 5; // Otherwise, return the remainder when divided by 5.
    }
}

int main() {
    int n;
    printf("Enter the number of matches: ");
    scanf("%d", &n);

    int result = match(n);

    if (result == -1) {
        printf("Return -1\n"); // Return -1 if the condition is met.
    } else {
        printf("A should pick %d matchstick(s).\n", result); // Display the number of matchsticks A should pick.
    }

    return 0; 
}

