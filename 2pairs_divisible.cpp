#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int x: arr){
            m[x%k]++;
        }
        for(auto x: arr){
            cout<<x.second;
        }
        cout<<endl;
        return 1;
    }
};

int main(){
    vector<int> vec = {1,2,3,4,5,10,6,7,8,9};
    int k = 5;
    cout << (7 & 1);
    Solution s;
    auto res = s.canArrange(vec, k);
    cout << res<<endl;
}
