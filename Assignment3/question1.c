/*
    *Name : Mohammad Burair 
    *Roll Number : 24K-0775
    *Section : BCS-1C
    *Desc : Program that uses structure to store information of employees and perform operations on them.
*/
#include<stdio.h>
#include<string.h>

typedef struct {
    int year;
    int month;
    int day; 
} Date;

typedef struct {
    int employeeCode;
    char name[100];
    Date dateOfjoing;
} Employee;

void inputEmploye(Employee *emp){
    printf("Enter Employee Code: ");
    scanf("%d", &emp->employeeCode);
    getchar();
    printf("Enter Employee Name: ");
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name , "\n")] = '\0';
    printf("Enter Date of Joining (dd/mm/yyyy): ");
    scanf("%d %d %d", &(emp->dateOfjoing.day), &(emp->dateOfjoing.month) , &(emp->dateOfjoing.year));
    getchar();
}

void printEmploye(Employee *emp){
    printf("Employee Code: %d\n", emp->employeeCode);
    printf("Employee Name: %s\n", emp->name);
    printf("Date of joing is (dd/mm/yyyy) %d/%d/%d \n", emp->dateOfjoing.day, emp->dateOfjoing.month , emp->dateOfjoing.year);

}

int tenureCalculator(Employee *emp, Date *currentdate) {
    int tenureYears = currentdate->year - emp->dateOfjoing.year;
    int tenureMonths = currentdate->month - emp->dateOfjoing.month;
    int tenureDays = currentdate->day - emp->dateOfjoing.day;

    if (tenureDays < 0) {
        tenureMonths--;
        tenureDays += 30; 
    }
    if (tenureMonths < 0) {
        tenureYears--;
        tenureMonths += 12;
    }
    printf("Tenure of Employee %s: %d Years, %d Months, %d Days\n", emp->name, tenureYears, tenureMonths, tenureDays);
    return tenureYears; 
}

int main(){
    Employee emp[4];
    int i , count = 0 , tenure = 0;
    Date currentDate;

    for(i = 0; i < 4; i++){
        inputEmploye(&emp[i]);
    }

    printf("Enter the current date (dd/mm/yyyy): ");
    scanf("%d %d %d", &(currentDate.day), &(currentDate.month), &(currentDate.year));
    getchar();

    for( i = 0; i < 4; i++){
        printEmploye(&emp[i]);
        // tenureCalculator(&emp[i], &currentDate);
        int tenure = tenureCalculator(&emp[i], &currentDate);
        if(tenure >= 3){
            count++;
        }
    }
    printf("The Total Empolyee with Tenure of 3 years or more is %d\n", count);

    return 0;
}