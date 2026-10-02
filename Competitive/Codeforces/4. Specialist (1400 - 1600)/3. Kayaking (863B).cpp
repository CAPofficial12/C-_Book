#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;

    vector<ll> mass (2*n);
    for(auto& e: mass){
        cin >> e;
    }
    sort(mass.begin(), mass.end());

    ll total = LLONG_MAX;
    for(ll a = 0; a < 2*n-1; a++){
        for(ll b = a+1; b < 2*n; b++){
            ll instable = 0;

            vector<ll> m = mass;
            m.erase(m.begin() + b);
            m.erase(m.begin() + a);
            sort(m.begin(), m.end());
            for(ll c = 0; c < 2*n-3; c += 2){
                instable += m[c+1] - m[c];
            }
            total = min(total, instable);
        }
    }
    cout << total;
    return 0;
}