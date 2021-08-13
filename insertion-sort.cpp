#include<stdio.h>
#include<iostream>

using namespace std;

static const int SIZE = 100;

void swap(int *arr, int pos);
void printarr(int *arr, int size, int mode);
void insertionSort(int *arr, int size);

void prompt();

int main(){
    printf("Welcome to Insertion-sort Sorter!\n");
    printf("Please choose one of the following action : \n");

    prompt();
}

void prompt(){
    int opt = 1;
    int arr[SIZE], size;
    while(opt < 4){
        printf("1. Create a new array\n");
        printf("2. Sort the array\n");
        printf("3. Show the current array\n");
        printf("0. Quit the program\n");
        printf("Option : ");
        cin >> opt;

        switch(opt){
            case 1:
                printf("How many numbers(> 1) in the array?\n");
                int size;
                printf("Size : ");
                scanf("%i", &size);
                //scanf("\n");
                printf("Please input the elements of the array :");
                for(int i = 0; i < size; i++){
                    scanf("%i", arr+i);
                }
                break;
            case 2:
                insertionSort(arr, size);
                break;
            case 3:
                printf("The array :");
                printarr(arr,size,0);
                break;
            default:
                printf("Thank you for using this program!");
                opt = 5;
                break;

        }

    }
}

void swap(int *arr, int pos){
    int temp = arr[pos];
    arr[pos] = arr[pos-1];
    arr[pos-1] = temp;
}

void printarr(int *arr, int size, int mode){
    if(mode == 1){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < size/2; j++){
                printf("=");
            }
            printf("||");
            for(int j = 0; j < size/2; j++){
                printf("=");
            }
            printf("\n");
        }
    }
    for(int i = 0; i < size; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int size){
    int mode = 1;
    printf("If you wish to see the insertion sort in progress, please choose 1\n");
    printf("Option : ");
    scanf("%i", &mode);

    printarr(arr, size, 0);

    for(int i = 1; i < size; i++){
        int j = i;
        
        while((arr[j] < arr[j-1]) && j > 0){
            swap(arr, j);
            printarr(arr,size,mode);
            j--;
        }
    }
}