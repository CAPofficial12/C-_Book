#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

ll square(ll n){
    ll total = 0;
    while (n >= 1){
        total += (n % 10)*(n%10);
        n /= 10;
    }
    return total;
}

ll getKey(ll n){
    vector<ll> cycle = {4, 16, 37, 58, 89, 145, 42, 20};
    ll steps = 0;

    while(n!=1){
        ll idx = -1;
        for(ll i = 0; i < 8; i++){
            if (n == cycle[i]){
                idx = i;
                break;
            }
        }

        if (idx = -1){
            return (idx - steps % 8) % 8;
        }
        n = square(n);
        steps++;
    }
    return 8;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        map<ll, ll> freq;
        ll total = 0;

        for(ll i = 0; i < n; i++){
            ll x;
            cin >> x;

            ll key = getKey(x);
            total += freq[key];
            freq[key]++;
        }

        cout << "\n" << total;
    }

    return 0;
}
