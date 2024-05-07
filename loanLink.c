// Assumes fixed rate simple interest and stable price on the loan.
// Further assume that interests are calculated monthly based on the remaining principal.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50

typedef struct Loan
{
    char *name;
    double price;
    int loanTermYears;
    double annualInterestRate;
    double downPayment;
    double marginalTaxRate;
    struct Loan *next;
} Loan;

void getUserInput(Loan **head, int numLoans);
void calculateMonthlyDetails(Loan *loan);
void freeList(Loan *head);
int parseCommandLineArguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int numLoans = parseCommandLineArguments(argc, argv);

    Loan *loans = NULL; 

    getUserInput(&loans, numLoans);

    Loan *current = loans;
    while (current != NULL)
    {
        calculateMonthlyDetails(current);
        current = current->next;
    }

    freeList(loans);

    return 0;
}

// Command line arguement
int parseCommandLineArguments(int argc, char *argv[])
{
    int numLoans = 1; // Default number of loans

    if (argc == 2)
    {
        numLoans = atoi(argv[1]);

        if (numLoans <= 0)
        {
            fprintf(stderr, "Please enter a valid number of loans.\n");
            exit(1); 
        }
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [number_of_loans]\n", argv[0]);
        exit(2); 
    }

    return numLoans;
}

// Prompt for user input
void getUserInput(Loan **head, int numLoans)
{
    for (int i = 0; i < numLoans; i++)
    {
        Loan *newLoan = (Loan *) malloc(sizeof(Loan));
        if (!newLoan)
        {
            fprintf(stderr, "Memory allocation error.\n");
            exit(1); 
        }

        newLoan->name = (char *) malloc(NAME_LENGTH * sizeof(char));
        if (!newLoan->name)
        {
            fprintf(stderr, "Memory allocation error.\n");
            exit(1); 
        }

        printf("\nEnter details for Loan %d:\n", i + 1);

        printf("Enter the name of the loan: ");
        scanf("%s", newLoan->name);

        printf("Enter the purchase price: ");
        scanf("%lf", &newLoan->price);

        printf("Enter the loan term in years: ");
        scanf("%d", &newLoan->loanTermYears);

        printf("Enter the annual interest rate (in decimal form): ");
        scanf("%lf", &newLoan->annualInterestRate);

        printf("Enter the down payment (in decimal form): ");
        scanf("%lf", &newLoan->downPayment);

        printf("Enter the marginal tax rate (in decimal form): ");
        scanf("%lf", &newLoan->marginalTaxRate);

        newLoan->next = *head;
        *head = newLoan;
    }
}

// Calculation
void calculateMonthlyDetails(Loan *loan)
{
    double loanAmount = loan->price - (loan->price * loan->downPayment);
    double monthlyInterestRate = loan->annualInterestRate / 12;
    int numberOfPayments = loan->loanTermYears * 12;
    double monthlyPayment = loanAmount * (monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments)) /
                            (pow(1 + monthlyInterestRate, numberOfPayments) - 1);
    double equity = loan->price - loanAmount;

    double totalInterest = 0.0;
    double totalTaxSavings = 0.0;

    printf("\nDetails for Loan: %s\n", loan->name);
    printf("Name\tPurchase Price\tLoan Term (Years)\tAnnual Interest Rate\tDown Payment\tMarginal Tax Rate\n");
    printf("%s\t%.2lf\t\t%d\t\t\t%.4lf\t\t\t%.4lf\t\t%.4lf\n", loan->name, loan->price, loan->loanTermYears,
           loan->annualInterestRate, loan->downPayment, loan->marginalTaxRate);

    printf("\nMonth\tPayment\tInterest\tPrincipal\tDebt\tEquity\tTax Savings\n");

    for (int month = 1; month <= numberOfPayments; month++)
    {
        double interestPayment = loanAmount * monthlyInterestRate;
        double principalPayment = monthlyPayment - interestPayment;
        loanAmount -= principalPayment;
        equity = loan->price - loanAmount;
        double taxSavings = interestPayment * loan->marginalTaxRate;

        totalInterest += interestPayment;
        totalTaxSavings += taxSavings;

        printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\t%.2lf\t\t%.2lf\n", month, monthlyPayment, interestPayment, principalPayment,
               loanAmount, equity, taxSavings);
    }

    printf("\nTotal Interest: %.2lf\n", totalInterest);
    printf("Total Tax Savings: %.2lf\n", totalTaxSavings);
}

void freeList(Loan *head)
{
    while (head != NULL)
    {
        Loan *temp = head;
        head = head->next;
        free(temp->name);
        free(temp);
    }
}
