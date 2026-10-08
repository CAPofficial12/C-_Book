#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using bs = bitset<4>;
int main(){
    ll a = 0b1010;
    ll b = 0b1100;
    cout << bs(a) << endl << bs(b) << endl << endl;

    ll ad = a & b; // True if both values are 1
    ll o = a | b; // True if at least 1 value is 1
    ll xo = a ^b; // True if only a single 1 is present
    cout << bs(ad) << endl << bs(o) << endl << bs(xo) << endl;

    cout << bs(a >> 1) << endl << bs(a << 1) << endl;
    return 0;
}