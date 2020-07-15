#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> vect = {3,4,7,2,-3,1,4,2};
    int k = 7;
    auto res = s.subarraySum(vect, k);
    cout << res <<endl;
   
}
