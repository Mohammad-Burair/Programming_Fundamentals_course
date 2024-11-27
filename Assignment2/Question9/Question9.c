/* 
   Name: Mohammad Burair
   Roll Number: 24k-0775
   Section: BCS-1C
   Description: A simple grid adventure game where the player moves around a grid to collect items and wins after collecting all items.
*/

#include <stdio.h>
#include <stdlib.h>

void upDown(char grid[][5], int *i, int *j, int *k, int *item);
void leftRight(char grid[][5], int *i, int *j, int *k, int *item);
void printGrid(char grid[5][5]);
void clearScreen();
int countItems(char grid[5][5]);

int main(){
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    printf("Welcome to Grid Adventure Game.\n\n");
    printf("Enter following keys to play\nW: up\nS: down\nA: Left\nD: Right\nQ: Quit.\n\n");
    printf("Let's Start\n");

    int p1 = 4, p2 = 4, item = 0;
    char a;

    // Count the number of 'I' items on the grid initially
    int totalItems = countItems(grid);

    while(a != 'Q'){
        int p3 = 0;
        clearScreen(); // Clear the screen before displaying the grid
        printGrid(grid);
        printf("\nEnter your move: ");
        scanf(" %c", &a);

        if(a == 'W'){
            p3 = p1 - 1;
            upDown(grid, &p2, &p1, &p3, &item);
        }
        else if(a == 'S'){
            p3 = p1 + 1;
            upDown(grid, &p2, &p1, &p3, &item);
        }
        else if(a == 'A'){
            p3 = p2 - 1;
            leftRight(grid, &p1, &p2, &p3, &item);
        }
        else if(a == 'D'){
            p3 = p2 + 1;
            leftRight(grid, &p1, &p2, &p3, &item);
        }
        else if(a == 'Q'){ 
            printf("\nThe game has ended\n");
            printf("Collected items: %d\n", item);
            return 0;
        }
        else {
            printf("Invalid Input\n");
        }

        // Check if all items have been collected
        if (item == totalItems) {
            clearScreen();
            printGrid(grid);
            printf("\nCongratulations! You have collected all items!\n");
            break; // Exit the game
        }
    }
}

void clearScreen() {
    // Windows-specific screen clearing
    system("cls");
}

void printGrid(char grid[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("|'%c'", grid[i][j]);
        }
        printf("|\n");
    }
}

void upDown(char grid[][5], int *i, int *j, int *k, int *item){
    if(*k >= 0 && *k <= 4){
        if(grid[*k][*i] == ' ' || grid[*k][*i] == 'I'){
            if(grid[*k][*i] == 'I') (*item)++;
            grid[*j][*i] = ' ';
            grid[*k][*i] = 'P';
            *j = *k;
        }
    }
    else {
        printf("Invalid Input\n");
    }
    return;
}

void leftRight(char grid[][5], int *i, int *j, int *k, int *item){
    if(*k >= 0 && *k <= 4){
        if(grid[*i][*k] == ' ' || grid[*i][*k] == 'I'){
            if(grid[*i][*k] == 'I') (*item)++;
            grid[*i][*j] = ' ';
            grid[*i][*k] = 'P';
            *j = *k;
        }
    }
    else {
        printf("Invalid Input\n");
    }
    return;
}

int countItems(char grid[5][5]) {
    int itemCount = 0;
    // Count the number of 'I' items on the grid
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (grid[i][j] == 'I') {
                itemCount++;
            }
        }
    }
    return itemCount;
}

