#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
    char name[30];
    int ballscore[12];
    int totalscore;

}Player;


bool validatescore(int score){
    if(score >= 0 && score <= 6){
        return true;
    }
    else {
        return false;
    }
}

void playgame(Player *p){
    int score = 0;
    for(int i = 0; i < 12; i++){
        printf("\nEnter score %d for %s:" , i+1 , p->name);
        scanf("%d", &score);
        if(validatescore(score)){
            p->ballscore[i] = score;
            p->totalscore+=score;
        }
        else {
            p->ballscore[i] = -1; //if score is not valid I am marking it -1 so that while displaying if score is -1 I will print discarded score
        }
    }
}

void winner(Player *p1 , Player *p2){
    if(p1->totalscore>p2->totalscore){
        printf("\n%s is the winner of the Game. ", p1->name);
    }
    else if(p1->totalscore>p2->totalscore){
        printf("\nThe game ended in a draw. ");
    }
    else {
        printf("\n%s is the winner of the Game. ", p2->name);
    }
} 

void displaymatchscore(Player *p){
    printf("\nFor %-30s", p->name);
    printf("\n%-5s :", "Score");
    for(int i = 0; i < 12; i++){
        if(p->ballscore[i] != -1){
            printf("%-5d", p->ballscore[i]);
        }
        else {
            printf("%-5s" , "N/A");
        }
    }
    printf("\nTotal Score is : %d\n", p->totalscore);
}
int main(){
    Player p1 , p2;
    // getchar();
    printf("\nEnter the name of Player 1: ");
    fgets(p1.name , 30 , stdin);
    p1.name[strcspn(p1.name , "\n")] ='\0';
    printf("Enter the name of Player 2: ");
    fgets(p2.name , 30 , stdin);
    p2.name[strcspn(p2.name , "\n")] ='\0';

    p1.totalscore = 0;
    p2.totalscore = 0;

    playgame(&p1);
    playgame(&p2);

    displaymatchscore(&p1);
    displaymatchscore(&p2);

    winner(&p1 , &p2);


    return 0;
}