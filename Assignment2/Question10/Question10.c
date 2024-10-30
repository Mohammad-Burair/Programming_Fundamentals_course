/*
    *Name : Mohammad Burair
    *Class : BCS-1C
    *Roll Number : 24K-0775
    *Description : This is the program to print star after taking an number input from the user. 
    
    The approach to solve this problem is to divide the pattern into smaller  parts and then print them. The first part is the top half of the pattern, the second part is the middle part , and lastly  the third part is the bottom half of the pattern. The problem in this was to find the values of spaces and stars in terms of the user input ,  and then print them accordingly. I tried multiple time but failed to find forumulae for spaces and inner spaces. I worked on that  for 2 days and then I found the solution.
    
    Through this problem I learn to make the problem simple by  dividing it into smaller parts and then solve them. 

*/
#include<stdio.h>

int main(){
    int space , a , spaceinner , star , i , j , l;

    printf("Enter any number :");
    scanf("%d", &a);

    space = (a*2)-2; //spaces in terms of input (One of the most difficult thing for me in this problem)
    spaceinner = 0;

// printing the upper part 
    for(i = 0; i <  a-1; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < spaceinner; l++){
            printf(" ");
        }

        if(l != 0)
            printf("*");
        

        printf("\n");

        space--;
        if(i == 0)
            spaceinner++;
        else
            spaceinner+=2;
    }
// upper part is done 


//printing middle part 
    for(i = 0 ;  i < a; i++){
        printf("*");
    }

    for(i = 0;  i < spaceinner; i++){
        printf(" ");
    }

    for(i = 0 ;  i < a; i++){
        printf("*");
    }


    printf("\n");
    spaceinner = (spaceinner*2)-1; // again that difficult part :(
    space = 1;

    for(i = 0; i < a-1;  i++){
        for(j = 0; j  < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0 ; l < spaceinner; l++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spaceinner-=2;
        space++;

    }
    
// lower part 
    space = a-2;
    spaceinner = 1;
    for(i = 0; i < a-2; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < space; l++){
            printf(" ");
        }
        printf("*");
        for(j = 0;  j < spaceinner; j++){
            printf(" ");
        }
        printf("*");
        for( j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        space --;
        spaceinner+=4;

    }
    spaceinner+=2;
    printf("*");
    for(j = 0; j < spaceinner; j++){
        printf(" ");
    }
    printf("*");

    return 0;
}
