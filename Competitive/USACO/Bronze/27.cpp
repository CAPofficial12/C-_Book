#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ll n;
    cin >> n;

    vector<ll> num(n);
    for(auto& u:num){
        cin >> u;
    }

    ll i = 3;
    vector<ll> old_ref = num;
    vector<ll> explode = {num[i]};
    vector<ll> new_ex = {};

    for(ll a =0; a < n; a++){
    }
    return 0;
}