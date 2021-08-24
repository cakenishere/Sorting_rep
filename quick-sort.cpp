#include<stdio.h>
#include<iostream>

using namespace std;

static const int SIZE = 100;

void swap(int *arr, int i, int j);
void printarr(int *arr, int size, int mode);
void quickSort(int *arr, int left, int right);
int partition(int *arr, int left, int right);

void prompt();

int main(){
    printf("Welcome to Quick-sort Sorter!\n");
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
                quickSort(arr, 0, size-1);
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

void swap(int *arr, int left, int right){
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
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
    else{
        printf(" The array : ");
    }
    for(int i = 0; i < size; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void quickSort(int *arr, int left, int right){
    if(left >= right){
        return;
    }
    
    int pivot = partition(arr, left, right);
    printarr(arr, right+1, 0);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);

}

int partition(int *arr, int left, int right){
    int pivot = (left+right)/2;
    int lastSmall =left;
    swap(arr, pivot, left);

    for(int i = left+1; i <= right; i++){
        if(arr[i] < arr[left]){
            swap(arr,++lastSmall, i);
        }
    }

    swap(arr, lastSmall, left);

    return lastSmall;
}
