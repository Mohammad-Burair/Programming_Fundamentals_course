/*
    *Name : Mohammad Burair
    *Class : BCS-1C
    *Roll Number : 24K-0775
    *Decription : The program is to find the second smallest value in the array (if it exists) 
    
    The approach to solve this problem is to take input from the user the whole array
    keeping in mind that every value should be less than 9999. After taking the input from 
    the user I started a loop to compare every element with the smallest and second smallest 
    is there is value smaller than second smallest , it is swapped with smallest and the other value 
    is placed into the second smallest.
    
*/
#include <stdio.h>

int main() 
{
    int arr[5], smallest, smallestsecond, i;

    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
        while(arr[i]>=9999){ // is input is 9999 then taking another input till its in range
            printf("(Value out of range!). Enter a number less than 9999: ");
            scanf("%d", &arr[i]);
        }
    }
    
    smallest=9999;// replacing with largest value (in this case)
    smallestsecond=9999;
    
    //loop for checking
    for(i = 0; i < 5; i++){
    	
        if(arr[i]<smallest){
            smallestsecond=smallest;
            smallest = arr[i];
        } 
		else if(arr[i]<smallestsecond && arr[i]!=smallest){
            smallestsecond = arr[i];
        }
    }
    
    if(smallestsecond==9999){
        printf("\nThere is no second smallest element.\n");
    } 
    
	else{
        printf("\nThe Second smallest element in the array is: %d\n", smallestsecond);
    }
    
    
    return 0;
}
