#include <stdio.h>
#include <stdlib.h>

// A program to calculate a weekly pay amount.

// To make this calculation the user should enter the number of hours worked in a week via keyboard.

// The output is 1, the gross pay, 2, the taxes, and 3, the net pay.

/* Assumptions
Basic pay rate = $12.00/hr
Overtime (in excess of 40 hours) = overtime * 1.5
Tax rate:
    15% of the first $300
    20% of the next $150
    25% of the rest
*/

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
    int hoursWorked = 0;
    double grossPay = 0.0;
    double netPay = 0.0;
    double taxes = 0.0;

    // Get the input
    printf("Please, enter your weekly hours\n");
    scanf("%d", &hoursWorked);
    printf("\n");

    // Calculate the gross pay
    if(hoursWorked <= 40) {
        grossPay = hoursWorked * PAYRATE;
    }

    if(hoursWorked > 40) {
        grossPay = 40 * PAYRATE;
        double overTimePay = (hoursWorked - 40) * (PAYRATE * 1.5);
        grossPay += overTimePay;
    }

    //Calculate the taxes
    if(grossPay <= 300.00) {
        taxes = grossPay * TAXRATE_300;
    }

    if(grossPay > 300.00 && grossPay <= 450.00) {
        taxes = (300.00 * TAXRATE_300) + ((grossPay - 300.00) * TAXRATE_150);
    }

    if(grossPay > 450.00) {
        taxes = (300.00 * TAXRATE_300) + (150.00 * TAXRATE_150) + ((grossPay - 450.00) * TAXRATE_REST);
    }

    netPay = grossPay - taxes;
    printf("Gross Pay: %.2lf, Taxes: %.2lf, Net Pay: %.2lf\n", grossPay, taxes, netPay);

    return 0;
}
