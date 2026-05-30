#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a = 123456789;
    long long b = a*a;
    cout << b << "\n"; // Will not work because a is int so b will also be int

    long long int c = 123456789LL;
    b = c * c;
    cout << b << "\n";
    return 0;
}