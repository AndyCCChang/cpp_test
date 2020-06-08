#include <iostream>

using namespace std;

int binary_search(int arr[], int left, int right, int x){

	while(right >= left){
            int mid = left + (right - left)/2;
	    if (arr[mid] ==x){
	        return mid;
	    }
	    if (arr[mid] > x){
	        right = mid -1;
	    }
	    if (arr[mid] < x){
		left = mid + 1;
	    }

	}
	return -1;
}


int main(void){
    int arr[] = {1, 2, 3, 4, 5};
    int x = 6;
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int ret = binary_search(arr, 0, arr_size-1, x);
    cout << ret <<endl;
}
