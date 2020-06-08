#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> num2id;
        for(int i=0; i < nums.size(); i++)
        {
            int res = target - nums[i];
            auto it = num2id.find(res);//find key, so the number need to be converted to key by num2id
            if(it != num2id.end()) return vector<int>{it->second, i};
            num2id[ nums[i] ] = i;
        }
        
        return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    cout << "input: [ ";
    for (auto i : nums)
        cout << " " << i << " ";
    cout << "]\n";
    int target = 9;
    auto res = s.twoSum(nums, target);
    cout << "Answer: ";
    for(auto const&i :res){
        cout << "["<< i<<"]";
        }
    cout << "\n";
    return 0;
}
