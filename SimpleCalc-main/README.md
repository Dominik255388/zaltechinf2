#include <stdio.h>
#define SIZE 10

void enterNumbers(int *numbers) {
    for (int i = 0; i < SIZE; i++) {
        printf("numbers[%d] = ", i);
        scanf("%d", numbers + i);
    }
}

void displayNumbers(int *numbers) {
    for (int i = 0; i < SIZE; i++) {
        printf("numbers[%d] = %d\n", i, *(numbers + i));
    }
}

void calculateAverage(int *numbers) {
    float sum = 0;
    
    for (int i = 0; i < SIZE; i++) {
        sum += *(numbers + i);
    }
    
    printf("\nAverage: %.2f\n", sum / SIZE);
}

void findMaximum(int *numbers) {
    int max = *numbers;
    
    for (int i = 1; i < SIZE; i++) {
        if (*(numbers + i) > max) {
            max = *(numbers + i);
        }
    }
    
    printf("Maximum: %d\n", max);
}

void findMinimum(int *numbers) {
    int min = *numbers;
    
    for (int i = 1; i < SIZE; i++) {
        if (*(numbers + i) < min) {
            min = *(numbers + i);
        }
    }
    
    printf("Minimum: %d\n", min);
}

void menu() {
    printf("0 - Exit\n");
    printf("1 - Enter numbers\n");
    printf("2 - Display numbers\n");
    printf("3 - Find maximum\n");
    printf("4 - Find minimum\n");
    printf("5 - Calculate average\n");
}

int main() {
    int numbers[SIZE] = {1,2,3,4,5,6,9,8,3,2};
    int option;

    while (1) {
        menu();
        scanf("%d", &option);
        
        if (option == 0) {
            break;
        }

        switch (option) {
            case 1: 
                enterNumbers(numbers); 
                break;
            case 2: 
                displayNumbers(numbers); 
                break;
            case 3: 
                findMaximum(numbers); 
                break;
            case 4: 
                findMinimum(numbers); 
                break;
            case 5: 
                calculateAverage(numbers); 
                break;
            default: 
                printf("Choose correct option\n");
        }
    }
    
    return 0;
}
