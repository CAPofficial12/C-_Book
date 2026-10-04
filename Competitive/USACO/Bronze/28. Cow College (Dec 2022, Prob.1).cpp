#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    vector<ll> val(n);
    set<ll> va;
    for(auto& v: val){
        cin >> v;
        va.insert(v);
    }
    sort(val.begin(), val.end());

    pair<ll, ll> total = make_pair(0,0);
    for(ll a: va){
        ll maxa = n * a;
        for(ll b: val){
            if (b < a){
                maxa -= a;
            }else{
                break;
            }
        }
        if (total.first < maxa){
            total.first = maxa;
            total.second = a;
        }
    }
    cout << total.first << " " << total.second;
    return 0;
}