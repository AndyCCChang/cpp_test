#include <bits/stdc++.h>
using namespace std;

int expressiveWords(string S, vector<string>& words) {
    int res = 0;
    for (auto &w : words)
        if (w.size() <= S.size()) {
            int i, j;
            for (i = 0, j = 0; j < S.size(); j++) {
                if (w[i] == S[j]) // w[i] references to a null char when i reaches w.size()
                    i++;
                else if (j > 0 && S[j] == S[j - 1] && j + 1 < S.size() && S[j] == S[j + 1]) // last, this and next
                    j++;
                else if (!(j > 1 && S[j] == S[j - 1] && S[j] == S[j - 2])) // this and last 2 chars
                    break;
            }
            if (i == w.size() && j == S.size()) // both pointers reach the end
                res++;
        }
    return res;
}

int main(){
    string S = "heeellooo";
    vector<string> vect = {"goni", "hello", "hi", "helo"};
    auto res = expressiveWords(S, vect);
    cout << res ;

}
