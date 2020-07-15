//TODO Debug compile error
#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        return true;
    }
};

int main(void){
    int x = 121;
    Solution s;
    auto t = s.isPalindrome(x);
    cout << t << endl;
}
