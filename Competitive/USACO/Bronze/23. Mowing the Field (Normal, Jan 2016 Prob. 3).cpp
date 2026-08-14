#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("mowing.in", "r", stdin);
    freopen64("mowing.out", "w", stdout);

    ll n;
    cin >> n;
    vector<pair<ll,ll>> turns(n);
    unordered_map<ll, vector<ll>> count;
    ll x = 0 ,y = 0;
    ll t = 0;
    for(pair<ll, ll> a: turns){
        char dir;
        ll dist;
        cin >> dir >> dist;
        for(int i = 0; i < dist; i++){
            t++;
            if (dir == 'N'){
                y++;
            } else if (dir == 'E'){
                x++;
            } else if (dir == 'S'){
                y--;
            } else if (dir == 'W'){
                x--;
            }
            ll cord = x*10000 + y;
            count[cord].push_back(t);
        }   
    }
    ll diff = LLONG_MAX;
    for(const auto& [key, val]: count){
        if(val.size() > 1){
            ll T = LLONG_MAX;
            for(ll i = 0; i < val.size()-1; i++){
                T = min(T, val[i+1] - val[i]);
            }   
            diff = min(diff, T);     
        }
    }

    if (diff == LLONG_MAX){
        cout << -1;
    } else{
        cout << diff;
    }
    return 0;
}