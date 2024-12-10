/* 
   Name: Mohammad Burair
   Roll No: 24k 0775
   Section: BCS-1C
   Date: 10-12-2024
   Description: Program demonstrating user engagement and content categorization 
                using dynamic memory allocation and structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_CATEGORIES 5
#define MAX_DEVICES 3
#define MAX_CONTENT 10

struct MediaContent {
    char title[50];
    float rating;
    int duration;
    char format[20];
};

struct User {
    char username[30];
    double *engagementMetrics;
    double **devicePreferences;
};

struct Category {
    struct MediaContent *items[MAX_CONTENT];
};

void setupUsers(struct User users[], int totalUsers);
void initializeEngagementMetrics(struct User *user);
void initializeDevicePreferences(struct User *user);
void updateEngagement(struct User *user, int categoryIndex, double value);
void showUserEngagement(const struct User *user);
void setupCategories(struct Category categories[]);
void addContent(struct Category *category, int index, const char *title, float rating, int duration, const char *format);
void showCategoryContents(const struct Category *category);

int main() {
    struct User users[MAX_USERS];
    struct Category categories[MAX_CATEGORIES];
    
    setupUsers(users, MAX_USERS);
    setupCategories(categories);
    
    addContent(&categories[0], 0, "Action Film 1", 8.5, 120, "H.264");
    addContent(&categories[1], 0, "Drama Film 1", 7.8, 90, "H.265");
    
    updateEngagement(&users[0], 0, 5.0);
    updateEngagement(&users[0], 1, 3.5);
    
    printf("Engagement Metrics for %s:\n", users[0].username);
    showUserEngagement(&users[0]);
    
    printf("\nAction Category Contents:\n");
    showCategoryContents(&categories[0]);
    
    return 0;
}

void setupUsers(struct User users[], int totalUsers) {
    for (int i = 0; i < totalUsers; i++) {
        snprintf(users[i].username, sizeof(users[i].username), "User%d", i + 1);
        users[i].engagementMetrics = (double *)malloc(MAX_CATEGORIES * sizeof(double));
        memset(users[i].engagementMetrics, 0, MAX_CATEGORIES * sizeof(double));
        initializeDevicePreferences(&users[i]);
    }
}

void initializeDevicePreferences(struct User *user) {
    user->devicePreferences = (double **)malloc(MAX_DEVICES * sizeof(double *));
    for (int i = 0; i < MAX_DEVICES; i++) {
        user->devicePreferences[i] = (double *)malloc(3 * sizeof(double));
        memset(user->devicePreferences[i], 0, 3 * sizeof(double));
    }
}

void updateEngagement(struct User *user, int categoryIndex, double value) {
    if (categoryIndex >= 0 && categoryIndex < MAX_CATEGORIES) {
        user->engagementMetrics[categoryIndex] += value;
    }
}

void showUserEngagement(const struct User *user) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        printf("Category %d Engagement: %.2f\n", i + 1, user->engagementMetrics[i]);
    }
}

void setupCategories(struct Category categories[]) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_CONTENT; j++) {
            categories[i].items[j] = NULL;
        }
    }
}

void addContent(struct Category *category, int index, const char *title, float rating, int duration, const char *format) {
    if (index >= 0 && index < MAX_CONTENT) {
        category->items[index] = (struct MediaContent *)malloc(sizeof(struct MediaContent));
        strncpy(category->items[index]->title, title, sizeof(category->items[index]->title));
        category->items[index]->rating = rating;
        category->items[index]->duration = duration;
        strncpy(category->items[index]->format, format, sizeof(category->items[index]->format));
    }
}

void showCategoryContents(const struct Category *category) {
    for (int i = 0; i < MAX_CONTENT; i++) {
        if (category->items[i] != NULL) {
            printf("Title: %s\nRating: %.1f\nDuration: %d mins\nFormat: %s\n",
                   category->items[i]->title,
                   category->items[i]->rating,
                   category->items[i]->duration,
                   category->items[i]->format);
        }
    }
}
