/* 
   Name: Mohammad Burair
   Roll No: 24k 0775
   Section: BCS-1C
   Date: 10-12-2024
   Description: Program to evaluate employee performance using dynamic memory 
                allocation and determine the employee of the year, highest-rated 
                period, and worst-performing employee.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Worker {
    int *evaluations;
    int totalScore;
};

void inputEvaluations(int **scores, int numWorkers, int numPeriods);
void displayRatings(int **scores, int numWorkers, int numPeriods);
int findTopPerformer(int **scores, int numWorkers, int numPeriods);
int findBestRatedPeriod(int **scores, int numWorkers, int numPeriods);
int findLowestPerformer(int **scores, int numWorkers, int numPeriods);

int main() {
    struct Worker *workers;
    int numWorkers, numPeriods;

    printf("Enter the number of workers: ");
    scanf("%d", &numWorkers);

    printf("Enter the total number of evaluations: ");
    scanf("%d", &numPeriods);

    workers = (struct Worker *)malloc(sizeof(struct Worker) * numWorkers);

    for (int i = 0; i < numWorkers; i++) {
        workers[i].evaluations = (int *)malloc(sizeof(int) * numPeriods);
    }

    int **scores = (int **)malloc(sizeof(int *) * numWorkers);
    for (int i = 0; i < numWorkers; i++) {
        scores[i] = workers[i].evaluations;
    }

    inputEvaluations(scores, numWorkers, numPeriods);
    displayRatings(scores, numWorkers, numPeriods);

    printf("\n\n==========================================\n");
    printf("Employee %d has the highest average score\n", findTopPerformer(scores, numWorkers, numPeriods) + 1);
    printf("Period %d has the highest average score\n", findBestRatedPeriod(scores, numWorkers, numPeriods) + 1);
    printf("The lowest-performing employee is %d\n", findLowestPerformer(scores, numWorkers, numPeriods) + 1);

    // Free allocated memory
    for (int i = 0; i < numWorkers; i++) {
        free(workers[i].evaluations);
    }
    free(scores);
    free(workers);

    return 0;
}

void inputEvaluations(int **scores, int numWorkers, int numPeriods) {
    for (int i = 0; i < numWorkers; i++) {
        printf("Enter evaluations for worker %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Evaluation %d: ", j + 1);
            scanf("%d", &scores[i][j]);
        }
    }
}

void displayRatings(int **scores, int numWorkers, int numPeriods) {
    for (int i = 0; i < numWorkers; i++) {
        printf("\nRatings of worker %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Evaluation %d: %d\n", j + 1, scores[i][j]);
        }
    }
}

int findTopPerformer(int **scores, int numWorkers, int numPeriods) {
    int highestAvg = -1, topIndex = -1;
    for (int i = 0; i < numWorkers; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += scores[i][j];
        }
        if (sum / numPeriods > highestAvg) {
            highestAvg = sum / numPeriods;
            topIndex = i;
        }
    }
    return topIndex;
}

int findBestRatedPeriod(int **scores, int numWorkers, int numPeriods) {
    int highestAvg = -1, bestIndex = -1;
    for (int i = 0; i < numPeriods; i++) {
        int sum = 0;
        for (int j = 0; j < numWorkers; j++) {
            sum += scores[j][i];
        }
        if (sum / numWorkers > highestAvg) {
            highestAvg = sum / numWorkers;
            bestIndex = i;
        }
    }
    return bestIndex;
}

int findLowestPerformer(int **scores, int numWorkers, int numPeriods) {
    int lowestAvg = 9999, lowIndex = -1;
    for (int i = 0; i < numWorkers; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += scores[i][j];
        }
        if (sum / numPeriods < lowestAvg) {
            lowestAvg = sum / numPeriods;
            lowIndex = i;
        }
    }
    return lowIndex;
}
