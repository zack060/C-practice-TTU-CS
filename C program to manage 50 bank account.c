/*
name:Viet Phuc Do
R number:R11829618
*/

#include <stdio.h>
//create a constant of -1.0
#define INITIAL_ACCOUNT -1.0

//max amount of accounts
int accounts[50];

void initialize_accounts() {
    for (int i = 0; i < 50; i++) {
    //array account initialize to -1
        accounts[i] = INITIAL_ACCOUNT;
    }
}

int open_account(float deposit) {
    for (int i = 0; i < 50; i++) {
        if (accounts[i] == INITIAL_ACCOUNT) {
            if (deposit >= 100.0) {
                accounts[i] = deposit;
                printf("Your account number is %d\n", i + 100);
                return i;
            } else {
                printf("Initial deposit must be at least 100 USD\n");
                return -1;
            }
        }
    }
    //tell user maximum account has been created, return -1
    printf("Maximum number of accounts has been reached\n");
    return -1;
}


void print_balance(int account_num) {
  if (accounts[account_num] >= 100) {
       printf("Account number: %d\n", account_num + 100);
       printf("Balance: %d\n", accounts[account_num]);
    } else if (accounts[account_num] <= 99) {
       printf("Account is not created\n");
    }
}


void depositFunction(int account_num, float amount) {
    if (accounts[account_num] >= 100) {
        accounts[account_num] += amount;
        printf("Account number: %d\n", account_num + 100);
        printf("New balance: %d\n", accounts[account_num]);
    } else if (accounts[account_num] <= 99) {
        printf("Account is not created\n");
    }
}

void withdraw(int account_num, float amount) {
    if (accounts[account_num] >= 100) {
        if (accounts[account_num] >= amount) {
            accounts[account_num] -= amount;
            printf("Account number: %d\n", account_num + 100);
            printf("New balance: %d\n", accounts[account_num]);
        } else {
            printf("Insufficient funds\n");
        }
    } else if (accounts[account_num] <= 99) {
        printf("Account is not created\n");
    }
}


void close_account(int account_num) {
    if (accounts[account_num] != INITIAL_ACCOUNT) {
        accounts[account_num] = INITIAL_ACCOUNT;
        printf("Account closed\n");
    } else {
        printf("Account is not created\n");
    }
}

void change_interest(float rate) {
    int i;
    for (i = 0; i < 50; i++) {
        if (accounts[i] != INITIAL_ACCOUNT) {
            accounts[i] *= (1 + rate);
        }
    }
    printf("Change interest rate and applied to all accounts\n");
}

void printing_all_accounts() {
    int i;
    for (i = 0; i < 50; i++) {
        if (accounts[i] != INITIAL_ACCOUNT) {
            printf("Account number: %d\n", i + 100);
            printf("Balance: %d\n", accounts[i]);
        }
    }
}


int main() {
    initialize_accounts();
    char transaction_type;
    int account_num;
    float deposit, amount, rate;
    do {
        printf("Transaction type?: ");
        scanf(" %c", &transaction_type);
        switch (transaction_type) {
            case 'O':
            case 'o':
                //Open an account
                printf("Open an account\n");
                printf("Type how much you want to deposit?: ");
                scanf("%f", &deposit);
                open_account(deposit);
            break;
            case 'B':
            case 'b':
            //A balance inquiry
            printf("Balance Inquiry\n");
            printf("Account number?: ");
            scanf("%d", &account_num);
            //because account is at index 0, so we must have account number -100
            print_balance(account_num - 100);
            break;
        case 'D':
        case 'd':
            //A Deposit
            printf("Deposit new fund\n");
            printf("Account number?: ");
            scanf("%d", &account_num);
            printf("Amount?: ");
            scanf("%f", &amount);
            depositFunction(account_num - 100, amount);
            break;
        case 'W':
        case 'w':
            //A withdrawal
            printf("Withdaw fund\n");
            printf("Account number?: ");
            scanf("%d", &account_num);
            printf("Amount?: ");
            scanf("%f", &amount);
            withdraw(account_num - 100, amount);
            break;
        case 'C':
        case 'c':
            //Close account
            printf("Close the account\n");
            printf("Account number?: ");
            scanf("%d", &account_num);
            close_account(account_num - 100);
            break;
        case 'I':
        case 'i':
            printf("Interest Rate\n");
            printf("Interest rate?: ");
            scanf("%f", &rate);
            change_interest(rate / 100);
            break;
        case 'P':
        case 'p':
            printing_all_accounts();
            break;
        case 'E':
        case 'e':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid transaction type\n");
            break;
        }
      //Create a condition to keep the program going unless explicity press E
    } while (transaction_type != 'E' && transaction_type != 'e');

return 0;
}
