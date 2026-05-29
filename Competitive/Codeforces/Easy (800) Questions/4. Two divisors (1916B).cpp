#include <iostream>
#include <vector>
#include <array>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { 
        a %= b; swap(a, b); 
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main(){
    int test;
    
    cin >> test;

    while (test--) {
        long long a, b;
        cin >> a >> b;
        
        if (b % a == 0) {
            cout << b * b / a << "\n";
        } else {
            cout << lcm(a, b) << "\n";
        }
    }
    return 0;
}