#include<stdio.h>
#include<iostream>

using namespace std;

static const int SIZE = 100;


void printarr(int *arr, int size, int mode);
void insertionSort(int *arr, int size);
void merge(int *arr, int left, int right);
void mergeSort(int *arr, int left, int right);
void swap(int *arr, int pos);

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
                mergeSort(arr, 0, size-1);
                printarr(arr,size,0);
                break;
            case 3:
                printarr(arr,size,0);
                break;
            default:
                printf("Thank you for using this program!");
                opt = 5;
                break;

        }

    }
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
         printf("The array :");
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

void mergeSort(int *arr, int left, int right){
    int mid = (left+right)/2;
    if(right - left > 1){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
    }

    printarr(arr,7,0);
    merge(arr, left, right);
}

void merge(int *arr, int left, int right){
    int mid = ((left+right)/2)+1;
    printf(" left:%i right:%i \n", left, right);
    while(left < right){
        if(arr[left] <= arr[mid]){
            left++;
        }
        else{
            int temp = arr[mid];
            for(int i = mid; i > left; i--){
                arr[i] = arr[i-1];
            }
            arr[left] = temp;

            left++;
            if(mid < right){
                mid++;
            }
        }
    }
    printarr(arr, right, 0);
}

void swap(int *arr, int pos){
    int temp = arr[pos];
    arr[pos] = arr[pos-1];
    arr[pos-1] = temp;
}