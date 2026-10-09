#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> diff(200002, 0);
    vector<ll> prefix(200001, 0);

    ll low = LLONG_MAX;
    ll high = LLONG_MIN;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        low = min(a, low);
        high = max(b, high);
        diff[a]++;
        diff[b+1]--;
    }

    ll binTotal = 0;
    ll total = 0;
    for(ll i = 1; i <= 200000; i++){
        total += diff[i];
        prefix[i] = prefix[i-1];
        if(total >= k){
            prefix[i]++;
        } 
    }

    for(ll i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
    
        cout << prefix[b] - prefix[a-1] << endl;
    }
    return 0;
}