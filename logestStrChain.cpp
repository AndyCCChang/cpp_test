//#include <iostream>
using namespace std;
#include <bits/stdc++.h>
template class std::vector<string>;
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<string,int>m; int ans=0;
        sort(words.begin(),words.end(),[](auto a,auto b){return a.length()<b.length();});
        for(auto s:words)
        {
            for(int i=0 ; i<s.length() ; i++)
            {
                string str=s.substr(0,i)+s.substr(i+1);
                m[s]=max(m[s],m[str]+1);
            }
            ans=max(ans,m[s]);
        }
        return ans;
    }
};

int main(){
    //vector<string> vec = {"b","a","ba","bca","bda","bdca"};
    vector<string> vec = {"b","bca","bda","bdca"};
    Solution s;
    auto res = s.longestStrChain(vec);
    cout << res <<endl;
}
