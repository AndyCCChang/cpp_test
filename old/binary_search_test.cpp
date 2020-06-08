#include <iostream>

using namespace std;


int binary_search(int arr[], int left, int right, int x ){
    if (right >=left){

        int mid = left + (right - left) / 2;
	if (arr[mid] == x){
	    return mid;
	}
        if(arr[mid] > x){
	    return binary_search(arr,  left , mid - 1 , x );
	}
	return binary_search(arr, mid + 1, right , x);
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 7};
    int a_size = sizeof(arr) / sizeof(arr[0]);
    int ret = binary_search(arr, 0, a_size-1, 8);
    (ret == -1) ? cout << " not found it" <<endl : cout << " fount it at location:" << ret << endl;
}
