#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> um;
        for (int i =0; i<nums.size(); i++){
            int diff = target - nums[i];
            if (um.find(diff) != um.end()){
                return {um[i],i};
            }
            um[nums[i]] = i;
        }
        return {};
    }
};
int main(){
    Solution s;
    vector<int> vec = {2, 7, 10, 15};
    int target = 9;
    auto ans = s.twoSum(vec, target);
    for (int i =0; i < ans.size()-1;i++){   
        cout << ans[i] << endl;
    }

}
