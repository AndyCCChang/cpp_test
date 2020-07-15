#include <iostream>
#include <vector>
using namespace std;
int binary_search_arr(int arr[], int begin, int end, int target){
    while (end >= begin){
        int mid = begin + (end - begin)/2;
        if (arr[mid] == target)
            return mid;
        if (target > arr[mid]){
            begin = mid + 1;
        }
        else
            end = mid -1;
    }

    return -1;
}

int binary_search_vector(vector<int> vect, int begin, int end, int target){
    while (end >=begin){
         int mid = begin + (end - begin)/2;
         if (vect[mid] == target){
             return mid;
         }
         if (target > vect[mid]){
             begin = mid +1;
         }
         else{
             end = mid =1;
         }
    }
    return -1;
    
}

int main(void){
    int arr [] = {5, 10, 15, 20};
    int target = 5;
    vector<int> vec = {1,2,3, 5};
    int vec_end = vec.size();
    int end = sizeof(arr)/sizeof(arr[0])-1;
    int ret = binary_search_arr(arr, 0, end, target);
    int ret_vector = binary_search_vector(vec, 0, vec_end, target);
    cout << ret << endl;
    cout << ret_vector << endl;
}
