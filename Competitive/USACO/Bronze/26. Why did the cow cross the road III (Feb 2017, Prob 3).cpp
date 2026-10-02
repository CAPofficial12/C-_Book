#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> cows (n);
    for(auto& e: cows){
        cin >> e.first >> e.second;
    }
    sort(cows.begin(), cows.end());
    
    ll time = 0;
    for(ll i = 0; i < n; i++){
        if (time < cows[i].first){
            ll diff = cows[i].first - time;
            time += diff;
        }
        time += cows[i].second;
    }
    cout << time;
    return 0;
}