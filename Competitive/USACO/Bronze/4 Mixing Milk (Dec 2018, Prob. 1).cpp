#include <iostream>
using namespace std;
using ll = unsigned long long int;

void pour (ll& milk1, ll& milk2, ll& size2){
    if (milk2 + milk1 > size2){
        milk1 -= size2 - milk2;
        milk2 = size2;
    } else{
        milk2 += milk1;
        milk1 = 0;
    }
}

int main(){

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    
    ll size1, milk1, size2, milk2, size3, milk3;
    cin >> size1 >> milk1 >> size2 >> milk2 >>  size3 >> milk3;
    for (int i = 0; i < 33; i++){
        pour(milk1, milk2, size2);
        pour(milk2, milk3, size3);
        pour(milk3, milk1, size1);
    }
    pour(milk1, milk2, size2);
    cout << milk1 << endl;
    cout << milk2 << endl;
    cout << milk3 << endl;
    return 0;
}