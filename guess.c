#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_VALUE 9

void printfArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int array[SIZE];
    int sortedArray[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++){
        array[i] = rand() % (MAX_VALUE + 1);
        sortedArray[i] = array[i];
    }

    bubbleSort(sortedArray, SIZE);

     printf("Welcome to the sorted number guessing game!\n");
    printf("The computer generated a list of random numbers between 0 and 9 and sorted it.\n");
    printf("Try to guess the numbers in the sorted list.\n");

    int guess;
    int correctCount = 0;

    for (int i = 0; i < SIZE; i++) {
        if (sortedArray[i] > sortedArray[i - 1]) {
            printf("Hint: The number to be guessed is greater than %d.\n", sortedArray[i - 1]);
        } else if (sortedArray[i] < sortedArray[i - 1]) {
            printf("Hint: The number to be guessed is less than %d.\n", sortedArray[i - 1]);
        } else {
            printf("Hint: The number to be guessed is equal to %d.\n", sortedArray[i - 1]);
        }
        
        printf("Enter your guess for the number at position %d: ", i + 1);
        scanf("%d", &guess);

        if (guess == sortedArray[i]) {
            printf("Congratulations! You guessed the number %d at position %d.\n", guess, i + 1);
            correctCount++;
        } else {
            printf("Oops! The number %d is not at position %d.\n", guess, i + 1);
        }

        if (i == SIZE - 1) {
            printf("You made 10 guesses. Here is the sorted list:\n");
            printArray(sortedArray, SIZE);
        }
    }

    printf("You guessed %d numbers correctly.\n", correctCount);

    return 0;
}
