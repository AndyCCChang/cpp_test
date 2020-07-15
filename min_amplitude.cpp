#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minAmplitude(vector<int> A, int k){
        sort(A.begin(), A.end());
        int n = A.size();
        if (n<=3) return 0;
        int minA = INT_MAX;
        int sz = A.size();
        for(int i =0; i < k;i++){
            minA = min(minA, A[sz - (k-i+1)] - A[i]);

        }
        return minA;
    }
    
};

int main(){
//    vector<int> input = {-1,3,-1,8,5,4};
//    vector<int> input = {10,10,3,4,10};
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    //-1 -1 3 4 5 8
    int k = 3;
    Solution s;
    auto res = s.minAmplitude(input, k);
    cout << res << endl;
}
