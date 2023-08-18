#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
struct Expense {
    char date[11];
    double amount;
    char task[100];
};

void showExpense() {
    FILE *file = fopen("db.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;

    while (getline(&buffer, &buffer_size, file) != -1) {
        printf("Line: %s", buffer);
    }

    free(buffer);  
    fclose(file);
}


void showMenu() {
    printf("===== Expense Manager Menu =====\n");
    printf("1. Add an expense\n");
    printf("2. View expenses\n");
    printf("3. Calculate total expenses\n");
    printf("4. Exit\n");
    printf("===============================\n");
    printf("Please enter your choice: ");
}

void addTask(FILE *file) {
    time_t currentTime;
    struct tm *localTime = localtime(&currentTime);
    char dateString[20];
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", localTime);

    struct Expense expenses;
    printf("task : ");
    scanf("%s", expenses.task);
    printf("amount: ");
    scanf("%lf", &expenses.amount);

    strcpy(expenses.date, dateString);
    fprintf(file, "task: %s, amount: %.2lf, date: %s\n",
            expenses.task, expenses.amount, expenses.date);
}

void totalExpense() {
    printf("total");
    // Todo
}

int main() {
    FILE *file;

    file = fopen("db.txt", "w+b");
    showMenu(); 
    int inp;
    scanf("%d", &inp);
    switch (inp) {
        case 1 :
            addTask(file);
            break;
        case 2 :
            showExpense();          
            return 0;
        case 3 :
            totalExpense();
            break;
        case 4 :
            break;
    }
}
