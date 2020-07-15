#include <iostream>
using namespace std;

//from the pramp
int find_pivot(int arr[], int size_arr){
    int begin = 0;
    //auto end = arr.size()-1;
    //auto end = size(arr)-1;
    int end = size_arr;
    while (end > begin){
        int mid = begin + (begin + end)/2;
        if (mid == 0 || arr[mid] < arr[mid-1]){
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

int binary_search(int arr[], int begin, int end, int target){
    while (end >= begin){
        int mid = begin + (end - begin)/2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target){
            end = mid -1;
        }
        else{
            begin = mid + 1;
        }
    }
    return -1;
}

int main(void){
//    int arr[5];
    int arr[] = {5,15,20,1, 2, 3, 4};
    int target = 20;
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    int pivot = find_pivot(arr, size_arr-1);
    int ret;
    if (pivot ==0 || target < arr[0])
        ret = binary_search(arr, pivot, size_arr, target );
    
    ret = binary_search(arr, 0, pivot-1, target );
    cout << "pivot: "<< pivot << endl;
    (ret !=-1) ?  cout << "location: " << ret << endl : cout << "Not found! " <<endl;

}
