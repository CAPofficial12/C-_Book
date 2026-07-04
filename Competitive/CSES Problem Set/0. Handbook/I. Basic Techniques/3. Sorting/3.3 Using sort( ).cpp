#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

void print(vector<int> test){
    for (int i: test){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> v = {4,2,5,3,5,8,3};
    int a[7] = {4,2,5,3,5,8,3};

    sort(v.begin(),v.end());
    print(v);

    sort(v.rbegin(), v.rend());
    print(v);

    sort(a,(a + 7));

    string s = "C++a";
    sort(s.begin(), s.end());
    cout << s;

    return 0;
}