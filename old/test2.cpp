#include <iostream>
#include <vector>
using namespace std;

int main(void){

    vector<string> vect = {"abc", "def"};

    auto v_size = vect[0].size();
    auto v_length = vect[0].length();

    cout << v_size << endl;
    cout << v_length << endl;


}
