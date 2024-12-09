/*
    *Name : Mohammad Burair 
    *Section : BCS-1C
    *Roll Number : 24K-0775
    *Desc : Program that check if the given email is valid or not valid.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validatemail(char *email){
    int count = 0;
    int index = 0;
    // int isvalid = 0;
    int dotcount = 0;
    for(int i = 0; i < strlen(email); i++){
        if(email[i] == '@'){
            count++;
            index = i;
        }
        if(count == 1 && i > index && email[i] == '.'){
            dotcount++;
        }
    }

    if(email == NULL || strlen(email) <= 0 || count != 1 || dotcount < 1){
        return 0;
    }
    else return 1;
}

int main(){
    char *email;
    int n;
    printf("\nEnter the length of email you want to enter :");
    scanf("%d", &n);
    email = (char *)calloc( n , sizeof(char));
    if(email == NULL){
        printf("\nFailed to allocate memory. ");
        exit(1);
    }
    fflush(stdin);
    printf("\nEnter the email :");
    fgets(email , n , stdin);
    email[strcspn(email , "\n")] = '\0';

    if(validatemail(email)){
        printf("\nValid Email.");
    }
    else {
        printf("Invalid Email.");
    }

    free(email);
    return 0;
}