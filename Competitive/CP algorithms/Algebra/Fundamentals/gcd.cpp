#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    int g = gcd(a, b);
    cout << g;
    return 0;
}

int gcd(int a, int b){
    while (b > 0){
        a %= b;
        swap(a,b);
    }
    return a;
}