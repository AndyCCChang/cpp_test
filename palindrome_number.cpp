#include <iostream>
using namespace std;

bool isPalindrome(int x){

    int rev = 0;
    int pop =0;
    while (rev < x && rev < x/10){
        pop = x%10;
        rev = rev*10 + pop;
        x = x/10;
    }
    return rev ==x || rev==x/10;

}

int main(){
    int num = 121;

    auto t = isPalindrome(num);
    cout <<t<<endl;
    return 0;

}
