#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int> nums){
    int total = 0;
    vector<int> final = {};

    for(int i:nums){
        total += i;
        final.push_back(total);
    }
    return final;
}

int main(){
    vector<int> tests = {1,2,3,4};
    vector<int> ans = runningSum(tests);
    for(int a: ans){
        cout << a << endl;
    }

    return 0;
}