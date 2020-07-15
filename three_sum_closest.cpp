#include <iostream>
//#include <bits/stdc++.h>
//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int ans;
        int diff = INT_MAX;
        int v_size = nums.size();
        int left = 0;
        int right = v_size;
        int temp;
        for(int i = 0; i < v_size; i++){
            left = i +1;
            right = v_size-1;
            while(right > left){
                temp = nums[i] + nums[left] + nums [right];
                ans = temp;
                if (abs(target- temp) <diff){
                    ans = temp;
                    diff = abs(target-temp);
                }
                //diff = abs(temp - target);
                if (temp == target){
                    cout << "" << nums[left] <<" ";
                    cout << "" << nums[right] <<" ";
                    cout << "" << target - nums[right] - nums[left]  <<" " << endl;
                    return temp;
                }
                else if (temp > diff){
                    right--;
                }
                else{
                    left++;
                }
             }
         }
         cout << "" << nums[left] <<" ";
         cout << "" << nums[right] <<" ";
         cout << "" << target - nums[right] - nums[left] <<" "<< endl;
         return ans;
    }
};

int main(){
    vector<int> nums = {-2, 2, 3, -4, -7, 3, 5, 7};
    
    int target = 1;
    Solution so;
    int ans = so.threeSumClosest(nums, target);
    cout << ans <<endl;

}
