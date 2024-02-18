/*
name:Viet Phuc Do
R number:R11829618
*/

#include <stdio.h>
/*

// Recursive function to calculate the balance of a bank account after n years
float calculate_balance(float initial_balance, float interest_Rate, int years)
{
    //provide a condition for the function to exit
    if (years == 0) {
        return initial_balance;
    //Use recursion to calculate balance after one year and call function
    //again with one less year
    //then add on of them up until year = 0, which provide condition to
    //exit the function and return the total balance get after X years
    } else {
        float interest = initial_balance * interest_Rate;
        float new_balance = initial_balance + interest;
        return calculate_balance(new_balance, interest_Rate, years-1);
    }
}

int main()
{
    float initial_balance;
    float interest_Rate;
    int years;

    //Since there are just the variable without any value assign into it
    //so I assume the Program must require a user input
    //for these variables
    printf("Enter initial balance ");
    scanf("%f", &initial_balance);
    printf("Enter interest rate as a decimal ");
    scanf("%f", &interest_Rate);
    printf("Enter years ");
    scanf("%d", &years);

    float final_balance = calculate_balance(initial_balance, interest_Rate, years);
    //initially the print function use %d for the final balance
    //but this is incorrect because final balance use Float data type
    //so I change %d to %.2f
    printf("After %d years, the final balance is $%.2f\n", years, final_balance);

    return 0;
}


*/
