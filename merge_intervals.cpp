#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size();i++){
            if(output.back()[1] >= intervals[i][0])
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            else
                output.push_back(intervals[i]);
        }
        return output;

    }
};

int main(){
    Solution s;
    vector<vector<int>> interv = {{0,3},{2,5},{1,4},{6,9}};
    auto res = s.merge(interv);
    for(int i=0 ; i < res.size();i++){
        for(int j=0 ; j<  res[i].size();j++){
            cout << res[i][j] ;
        }
        cout <<endl ;
    }
//    cout<< res <<endl;
    
}
