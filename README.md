# Loan Calculator

This program is a simple loan calculator implemented in C. It allows users to input details for multiple loans and calculates monthly payment details including interest, principal, remaining debt, equity, and tax savings. It assumes fixed-rate simple interest and a stable price on the loan.

[Demo](https://vimeo.com/936178350?share=copy)

## Features

- Command Line Arguments: Users can specify the number of loans as a command line argument `./loanLink [number_of_loans]`
- Monthly Payment Details: Calculates and prints monthly payment details for each loan, including payment amount, interest, principal, remaining debt, equity, and tax savings.
- Total Interest and Tax Savings: Prints the total interest paid and total tax savings over the loan term for each loan.


## Usage

To use the loan calculator, follow these steps:

1. Compile the program: `gcc -o loanLink loanLink.c -lm`
2. Run the compiled executable: `./loanLink` or `./loanLink [number_of_loans]`
3. Follow the prompts to input details.

The program will then calculate and display monthly payment details for each loan, as well as total interest paid and total tax savings.

## Goal

The provided C program showcases basic fundamental aspects of programming in the language:
1. Highlights the ability to adapt C programming knowledge to address real-life problems.
2. Employs dynamic memory allocation techniques, crucial for managing memory efficiently, especially when dealing with user input and linked list structures.
3. Demonstrates the use of linked lists, a fundamental data structure in C, to organise and manipulate data efficiently, here used to manage multiple loan instances.
4. The program utilises standard input/output operations for user interaction and error handling, showcasing basic familiarity with fundamental C techniques for program flow control and user interaction.

Overall, this simple C program underscores the basics of programming concepts and their application in solving real-world challenges.


## Dependencies

This program requires the following standard C libraries:

stdio.h: For input and output operations.
stdlib.h: For memory allocation and deallocation.
math.h: For mathematical operations.

### Sample Output

Here's an example of the program's output for two loans:

```
Enter details for Loan 1:
Enter the name of the loan: Home
Enter the purchase price: 250000
Enter the loan term in years: 30
Enter the annual interest rate (in decimal form): 0.04
Enter the down payment (in decimal form): 0.2
Enter the marginal tax rate (in decimal form): 0.25

Enter details for Loan 2:
Enter the name of the loan: Car
Enter the purchase price: 35000
Enter the loan term in years: 5
Enter the annual interest rate (in decimal form): 0.06
Enter the down payment (in decimal form): 0.1
Enter the marginal tax rate (in decimal form): 0.2

Details for Loan: Car
Name    Purchase Price  Loan Term (Years)       Annual Interest Rate    Down Payment    Marginal Tax Rate
Car     35000.00                5                       0.0600                  0.1000          0.2000

Month   Payment Interest        Principal       Debt    Equity  Tax Savings
1       608.98          157.50          451.48          31048.52        3951.48         31.50
2       608.98          155.24          453.74          30594.78        4405.22         31.05
3       608.98          152.97          456.01          30138.77        4861.23         30.59
...
58      608.98          9.04            599.94          1208.89 33791.11                1.81
59      608.98          6.04            602.94          605.95  34394.05                1.21
60      608.98          3.03            605.95          -0.00   35000.00                0.61

Total Interest: 5038.99
Total Tax Savings: 1007.80

Details for Loan: Home
Name    Purchase Price  Loan Term (Years)       Annual Interest Rate    Down Payment    Marginal Tax Rate
Home    250000.00               30                      0.0400                  0.2000          0.2500

Month   Payment Interest        Principal       Debt    Equity  Tax Savings
1       954.83          666.67          288.16          199711.84       50288.16                166.67
2       954.83          665.71          289.12          199422.71       50577.29                166.43
3       954.83          664.74          290.09          199132.62       50867.38                166.19
...
358     954.83          9.49            945.35          1900.16 248099.84               2.37
359     954.83          6.33            948.50          951.66  249048.34               1.58
360     954.83          3.17            951.66          0.00    250000.00               0.79

Total Interest: 143739.01
Total Tax Savings: 35934.75
```
#### Input terminologies

1. Name: This column simply refers to the name or title of the loan.
2. Purchase Price: This is the total price of the item you're buying with the loan.
3. Loan Term (Years): This indicates the duration or length of time over which you'll be repaying the loan.
4. Annual Interest Rate: This is the percentage of the loan amount that you'll pay each year to borrow the money. It represents the cost of borrowing the money.
5. Down Payment: This is the initial payment you make upfront when you take out the loan. It's a percentage of the purchase price that you pay immediately, reducing the amount of money you need to borrow.
6. Marginal Tax Rate: This is the percentage of your income that you pay in taxes to the government. It's used in the calculation of tax savings, which can occur when you have deductible expenses, such as mortgage interest on a home loan.

#### Output terminologies
1. Month: This column indicates the specific month of the loan repayment period. It starts from the first month and increments by one for each subsequent month until the end of the loan term.
2. Payment: This column shows the total amount of money you need to pay for that particular month. It includes both the interest and principal components of your loan repayment.
3. Interest: This column displays the portion of your monthly payment that goes towards paying the interest on the loan. It represents the cost of borrowing money for that month.
4. Principal: This column represents the portion of your monthly payment that goes towards reducing the outstanding balance (the principal) of your loan. It directly reduces the amount you owe.
5. Debt: This column shows the remaining amount of money you owe on the loan after making the payment for that month. It's the remaining balance of your loan after deducting the principal payment.
6. Equity: This column indicates the portion of the asset (such as a house or car) that you own outright. It's the value of the asset minus the remaining loan balance.
- For example, if you've paid off 20% of your home loan, your equity in the home would be 20% of its value.
7. Tax Savings: This column shows any potential tax savings resulting from deductible expenses related to the loan.
- For example, if you have a home loan, you may be able to deduct the interest paid on the loan from your taxable income, thus reducing your tax liability. This column shows the amount of tax savings for each month.

##### Financial Disclaimers

This program provides estimates and should not be considered financial advice. Actual loan terms, interest rates, tax implications, and other financial factors may vary. Users should consult with financial professionals or advisors before making any financial decisions.
