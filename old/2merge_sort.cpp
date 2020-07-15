/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l +1;
    int n2 = r -m;
   
    int L[n1], R[n2];

    for (i = 0 ;i < n1; i++ ){
        L[i] = arr[l + i];
    }
    for (j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
     }
     while (i < n1){
         arr[k] = L[i];
         i++;
         k++;
     }
     while (j < n2){
         arr[k] = R[j];
         j++;
         k++;
     }

}

void merge2(int arr[], int l, int m, int r){
    
}


void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 




void mergeSort2(int arr[], int l, int r){
    if (r > l){
        int m = l + (r-l)/2;
        
        mergeSort2(arr, l, m);
        mergeSort2(arr, m+1, r);
        merge2(arr, l, m, r);
    }
}
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
