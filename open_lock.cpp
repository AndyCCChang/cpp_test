#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> bfs;
        string init = "0000";
        if (dds.find(init) != dds.end()) return -1;
        visited.insert("0000");
        bfs.push("0000");
        int res = 0;
        while (!bfs.empty()) {
            int sz = bfs.size();
            for (int i = 0; i < sz; i++) {
                string t = bfs.front(); bfs.pop();
                vector<string> nbrs = move(nbrStrs(t));
                for (auto s : nbrs) {
                    if (s == target) return ++res;
                    if (visited.find(s) != visited.end()) continue;//if visited, then go to next iterate in for
                    if (dds.find(s) == dds.end()) { //skip the deadeand
                        bfs.push(s);// put it in the queue
                        visited.insert(s); // insert it to visited
                    }
                }
            }
            ++res;
        }
        return -1;
    }
    int b_openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> q1, q2, pass, visited;
        string init = "0000";
        if (dds.find(init) != dds.end() || dds.find(target) != dds.end()) return -1;
        visited.insert("0000");
        q1.insert("0000"), q2.insert(target);
        int res = 0;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) swap(q1, q2);
            pass.clear();
            for (auto ss : q1) {
                vector<string> nbrs = nbrStrs(ss);
                for (auto s : nbrs) {
                    if (q2.find(s) != q2.end()) return res + 1;
                    if (visited.find(s) != visited.end()) continue;
                    if (dds.find(s) == dds.end()) {
                        pass.insert(s);
                        visited.insert(s);
                    }
                }
            }
            swap(q1, pass);
            res++;
        }
        return -1;
    }

    
    
    vector<string> nbrStrs(string key) {
        vector<string> res;
        for (int i = 0 ; i < 4; i++) {
            string tmp = key;
//            cout<< "i: " << i<<endl;
//            cout << "before temp: " <<tmp<< endl;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            //tmp[i] = (key[i] +1);
//            cout << " temp: " <<tmp<< endl;
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' -1 +10)%10 + '0';
//            tmp[i] = (key[i] - 1);
            res.push_back(tmp);
         }
        return res;
    }
};
int main(){
    Solution s;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    auto res = s.b_openLock(deadends, target);
    cout << res << endl;
}
