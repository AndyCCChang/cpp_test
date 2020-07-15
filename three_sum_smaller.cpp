#include <iostream>
//#include <bits/stdc++.h>
//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    res += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-2, 2, 3, -4, -7, 3, 5, 7};
    
    int target = -12;
    Solution so;
    int ans = so.threeSumSmaller(nums, target);
    cout << ans <<endl;

}
