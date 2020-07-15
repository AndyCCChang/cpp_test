#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> vect, int begin, int end, int target ){
    if (begin <= end){
        int mid = begin + (end - begin)/2;
        if (target == vect[mid]){
            return mid;
        }
        if (target < vect[mid]){
            end = mid-1;
        }
        else
            begin = mid+1;
    }
    return -1;
}
int main (void){

    vector<int> vect = {1,2,3, 6, 8, 10};
    auto end = vect.size();
    int ret = binary_search(vect, 0, end, 11);
    for (int i =0; i < vect.size();i++){
        cout << vect[i] << endl;
    }
    cout << "ret: " << ret << endl;

}
