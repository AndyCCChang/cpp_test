#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool isValid(string s){
        unordered_map<char, char> p = {{'(',')'}, {'{','}'}, {'[',']'}};
        stack<char> x;
        for(char &c : s){
            if(p.find(c)!=p.end()){
                x.push(p[c]);
            }
            else{
                if(x.empty() || c!=x.top()){
                    return false;
                }
                x.pop();
            }
        }
        return x.empty();
    }
};

int main(){
    Solution sol;
    string s = "{[}]";
    auto ret = sol.isValid(s);
    cout << ret <<endl;

}
