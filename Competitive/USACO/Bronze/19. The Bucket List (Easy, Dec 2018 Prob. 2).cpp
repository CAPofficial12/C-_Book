#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<ll>> cows(n);
    for(auto& sa:cows){
        ll s, t, b;
        cin >> s >> t >> b;
        vector<ll> cow = {s, t, b};
        sa = cow;
    }
    
    ll maxi = 0;
    for(ll i = 0; i < 1000; i++){
        ll used = 0;
        for(auto j: cows){
            if (j[0] <= i && j[1] >= i){
                used += j[2];
            }
        }
        maxi = max(maxi, used);
    }
    cout << maxi;
    return 0;
}