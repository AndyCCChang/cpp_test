#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dds (deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<string> bfs;
    string init_s = "0000";
    if (dds.find(init_s) !=dds.end()) return -1;
    visited.insert(init_s);
    bfs.push(init_s);
    int res = 0;

    while(!bfs.empty()){
        int sz = bfs.size();
        for(int i = 0; i < sz; i++){
            auto t = bfs.front();
            bfs.pop();
            auto nbrs = nbrStrs(t);
            for (auto s: nbrs){
                if (s == target) return ++res;
                if (visited.find(s)!=visited.end()) continue;
                if (dds.find(s)==dds.end()){
                    bfs.push(s);
                    visited.insert(s);
                }
            }
        }
        ++res;
    }
    return -1;

    }
    
    vector<string> nbrStrs(string key) {
        vector<string> res;
        for(int i=0; i<4; i++){
            string temp = key;
            temp[i] = (key[i] - '0' + 1)%10 + '0';
            res.push_back(temp);
            temp[i] = (key[i] - '0' -1 +10)%10 + '0';
            res.push_back(temp);
        }
        return res;
        
    }
};
int main(){
    Solution s;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    auto res = s.openLock(deadends, target);
    cout << res << endl;
}
