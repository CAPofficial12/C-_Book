#include <iostream>
using namespace std;

int E_gcd(int a, int b);

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    int g = E_gcd(a, b);
    cout << g;
    return 0;
}

int E_gcd(int a, int b){
    while (b > 0){
        a %= b;
        swap(a,b);
    }
    return a;
}