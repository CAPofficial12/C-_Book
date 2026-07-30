#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> rooms (n);
    for(auto& r:rooms){
        cin >> r;
    }

    ll maximum = LLONG_MAX;
    for(ll i = 0; i < n; i++){
        ll walked = 0;
        for(int j = i; j < n + i; j++){
            walked += (j-i) * rooms[j%n];
        }
        maximum = min(walked, maximum);
    }
    cout << maximum;
    return 0;
}