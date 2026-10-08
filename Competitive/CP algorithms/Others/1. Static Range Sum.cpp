#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    ll Q;
    cin >> N >> Q;
    vector<ll> set (N+1);
    ll total = 0;
    set[0] = 0;
    for(ll i = 1; i < N+1; i++){
        cin >> set[i];
        set[i] += total;
        total = set[i];
    }

    vector<pair<ll, ll>> queries (Q);
    for(auto& c: queries){
        cin >> c.first >> c.second;
        cout << set[c.second] - set[c.first] << endl;
    }

    return 0;
}