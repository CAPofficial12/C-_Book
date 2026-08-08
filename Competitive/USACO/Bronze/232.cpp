#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    ll x = -1;
    cin >> n;
    vector<pair<char, ll>> mow(n);
    map<pair<ll,ll>, vector<ll>> path;
    pair<ll,ll> pos = {0,0};
    ll c = 0;
    for(auto& m:mow){
        char a;
        ll b;
        cin >> a;
        cin >> b;
        c++;
        for(ll i = 0; i < b; i++){
            if(a == 'N'){
                pos.first ++;
            } else if(a == 'S'){
                pos.first --;
            }else if(a == 'E'){
                pos.second ++;
            }else if (a == 'W'){
                pos.second --;
            }
            path[pos].push_back(c);
        }
    }
    ll maxa = -1;
    for(auto& v: path){
        if(v.second.size() > 1){
            for(ll i = v.second.size() - 1; i > 0; i--){
                ll temp = v.second[i] - v.second[i-1];
                maxa = max(maxa, temp);
            }
        }
    }
    cout << maxa;
    return 0;
}