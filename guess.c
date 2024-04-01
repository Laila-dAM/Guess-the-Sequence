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
}