#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    ll x, y, loc;
    cin >> x >> y;
    loc = x;
    ll steps = 1;
    ll target = x + steps;
    ll count = 0;
    bool flag = false;
    while (!(x >= y && loc <= y) && !(x <= y && loc >= y)){ 
        count += abs(loc - target);
        steps *= -2;
        loc = target;
        target = x + steps;
        
    } 
    cout << count - abs(loc - y);
    return 0;
}