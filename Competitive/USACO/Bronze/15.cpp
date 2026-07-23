#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    vector<ll> size(n);

    for(auto& s:size){
        cin >> s;
    }

    int max=0;
    for(auto ref:size){
        ll total = 0;
        for(auto s:size){
            if (ref + k >= s && ref <= s){
                total += 1;
            }  
        } 
        if (total > max){
            max = total;
        }
    }

    cout << max;
    return 0;
}