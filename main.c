#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Employee {
    int employeeNo;
    char employeeName[20];
    float basicSalary;
    
    struct Date {
        int dd, mm, yy;
    } hireDate;
    
    float netSalary;
};

void input(struct Employee*);
void show(struct Employee*);
float calcNet(float);
bool checkDate(struct Employee*);

int main() {
    int n, i;
    
    // Get the number of elements for the array
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];
    
    // Get the details of the employees
    for (i = 0; i < n; i++) {
        input(&emp[i]);
    }
    
    // Print the details of the employees
    printf("\n======== EMPLOYEE RECORD =========");
    for (i = 0; i < n; i++) {
        show(&emp[i]);
        printf("\n");
    }
    
    return 0;
}

void input(struct Employee* emp) {
    // Function to accept the details of the employee
    printf("\n");
    printf("Employee Number: ");
    scanf("%d", &emp->employeeNo);
    
    printf("Employee Name: ");
    scanf("%s", emp->employeeName);
    
    printf("Hire Date (DD MM YY): ");
    scanf("%d %d %d", &emp->hireDate.dd, &emp->hireDate.mm, &emp->hireDate.yy);
    
    // Check whether the hire date is a valid date
    // If not, re-enter the hire date
    while (!checkDate(emp)) {
        printf("Invalid date input!!! Re-enter\nHire Date (DD MM YY): ");
        scanf("%d %d %d", &emp->hireDate.dd, &emp->hireDate.mm, &emp->hireDate.yy);
    }
    
    printf("Basic Salary: ");
    scanf("%f", &emp->basicSalary);
  
    emp->netSalary = calcNet(emp->basicSalary);
}

void show(struct Employee* emp) {
    // Function to display all the details
    printf("\n----------------------------------");
    printf("\nEmployee Number    :\t%d", emp->employeeNo);
    printf("\n----------------------------------");
    printf("\nEmployee Name      :\t%s", emp->employeeName);
    printf("\n----------------------------------");
    printf("\nHire Date(DD/MM/YY):\t%d/%d/%d", emp->hireDate.dd, emp->hireDate.mm, emp->hireDate.yy);
    printf("\n----------------------------------");
    printf("\nBasic Salary       :\t%0.2f", emp->basicSalary);
    printf("\n----------------------------------");
    printf("\nNet Salary         :\t%0.2f", emp->netSalary);
    printf("\n----------------------------------\n");
}

float calcNet(float basic) {
    // Function to calculate the net salary
    // gross salary = basic salary + DA + TA
    // net salary = gross salary - PF
    
    float DA = 0.4 * basic;     // 40% of basic salary
    float TA = 0.1 * basic;     // 10% of basic salary
    float PF = 0.05 * basic;    // 5% of basic salary
    
    float gross = basic + DA + TA;
    float net = gross - PF;
    
    return net;
}

bool checkDate(struct Employee* emp) {
    // Function to validate the date
    // Note: Not accounting for the leap year
    int t_dd = emp->hireDate.dd;
    int t_mm = emp->hireDate.mm;
    
    if (t_mm >= 1 && t_mm <= 12) {
        if (t_mm == 1 || t_mm == 3 || t_mm == 5 || t_mm == 7 || 
            t_mm == 8 || t_mm == 10 || t_mm == 12) {
            return (t_dd >= 1 && t_dd <= 31);
        }
        else if (t_mm == 2) return (t_dd >= 1 && t_dd <= 28); 
        else return (t_dd >= 1 && t_dd <= 30);
    }
    else return false;
}

