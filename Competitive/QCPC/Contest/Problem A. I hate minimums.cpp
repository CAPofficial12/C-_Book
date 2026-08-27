#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto& c: a){ 
        cin >> c;
    }   

    ll q;
    cin >> q;
    vector<pair<ll, ll>> quieres(q);
    for(auto& q: quieres){
        ll l,r;
        cin >> l >> r;
        q = make_pair(l, r);
    }

    for(const auto&p: quieres){
        ll l = p.first - 1;
        ll r = p.second - 1;

        ll low = LLONG_MAX;
        vector<ll> low_count;
        for(ll i = l; i <= r; i++){
            low = min(low, a[i]);
        }
        for(ll i = l; i <= r; i++){
            if(a[i] == low){
                low_count.push_back(i);
            }
        }

        ll sub = 0;
        for(ll size = 1;size < low_count.size(); size++){
            for(ll j=0;j < low_count.size() -size+1; j++){
                vector<ll> section(low_count.begin()+j, low_count.begin()+j+size);
                if(j == 0 && j != section[section.size()]){
                    sub += section[0];
                    sub += section[section.size()-1];
                }
            }
        }
        
    }
    return 0;
}