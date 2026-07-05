#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> skipd = {3,2,1,3,1,2,3};
    int index = 0;
    int value = 0;
    int total = 0;

    int n = 1000;
    while (value < n - 1){
        value += skipd[index %7];
        total += value;
        index += 1;
    }
    cout << total;
    return 0;
}