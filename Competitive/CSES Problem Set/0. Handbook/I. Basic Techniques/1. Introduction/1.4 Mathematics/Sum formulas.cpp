#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int Lin_ans = n * (n + 1) / 2;
    cout << "Linear ans: "<< Lin_ans << "\n";
    
    int Quad_ans = (n) * (n+1) * (2*n + 1) / 2;
    cout << "Quadratic ans: "<< Quad_ans << "\n";

    cout << "Cubic ans: "<<Lin_ans * Lin_ans;
}