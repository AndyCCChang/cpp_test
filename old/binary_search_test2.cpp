#include <iostream>

using namespace std;

int binary_search(int arr[], int left, int right, int x){
    if (right >1){
        int mid = left + (right - left)/2;
	if (left > right){
	    return -1;
	}
	if (arr[mid] == x){
	    return mid;
	}
	if (arr[mid] > x){
            return binary_search(arr, left, mid -1, x);
	}
	if (arr[mid] < x)
            return binary_search(arr, mid + 1, right, x);
		
    }

}

int main (void)
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    int ret = binary_search(arr, 0, size_arr-1, 11);
    (ret == -1) ? cout << "not found" <<endl : cout << "found it at: " << ret <<endl;
}

