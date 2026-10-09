#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, q;
    cin >> n >> k >> q;
    map<ll, ll> freq;

    ll low = LLONG_MAX;
    ll high = LLONG_MIN;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        low = min(a, low);
        high = max(b, high);
        for(ll c = a; c <= b;c++){
            freq[c] ++;
        }
    }

    vector<ll> culum(high+1);
    ll total = 0;
    for(auto [key, value]: freq){
        total += value;
        culum[key] = total;
    }

    for(ll i = 0; i < q; i++){
        ll a, b, ref;
        cin >> a >> b;
        if(b > high){
            ref = high;
        }else{
            ref = b;
        }

        cout << culum[ref] - culum[a] << endl;
    }
    return 0;
}