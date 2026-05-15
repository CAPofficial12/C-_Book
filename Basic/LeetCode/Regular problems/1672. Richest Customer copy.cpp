#include <iostream>
#include <vector>
using namespace std;

int maxWealth(vector<vector<int>>& accounts){
    int max = 0;
    for (vector<int> i: accounts){
        int total = 0;
        for (int a:i){
            total += a;
        }

        if (total > max){
            max = total;
        }
    }
    return max;
}

int main(){
    vector<vector<int>> tests = {{1,2,3},{3,2,1}};
    cout << maxWealth(tests);
    return 0;
}