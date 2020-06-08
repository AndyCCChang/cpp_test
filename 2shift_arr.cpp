#include <iostream>
using namespace std;

//from the pramp
int find_pivot(int arr [], int begin, int end){
    while (end > begin){
        int mid = begin + (begin + end)/2;
        if (mid == 0 | arr[mid] < arr[mid-1]){
            return mid;
        }
        if (arr[mid] > arr[0]){
            begin = mid+1;
        }
        else{
            end = mid-1;
        }
    }
}

int main(void){
//    int arr[5];
    int arr[] = {2,3,4,5,1};
    int arr_size = sizeof(arr)/sizeof(arr[0])-1;
    int pivot = find_pivot(arr, 0, arr_size);
    cout << pivot << endl;

}
