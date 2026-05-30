#include <iostream>
using namespace std;

void basic_mod(){
    int a;
    int mod;

    cin >> a;
    cin >> mod;
    cout << "Mod:" << a % mod; // Used for problem where large numbers cannot be represent or saved in 64 bits
}

void factorial(int n, int m){
    long long x = 1;
    for (int i = 2; i <= n; i++) {
    x = (x*i)%m;
    }
    cout << x%m << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    factorial(5, 12);

    return 0;
}