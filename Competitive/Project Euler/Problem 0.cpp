#include <iostream>
#include <string>
#include <boost>
using namespace std;

int main(){
    boost::multiprecision::total = 0;
    int n = 472000;
    total = (2*n - 1) * (n) * (2*n + 1) / 3;
    cout << total;
    return 0;
}