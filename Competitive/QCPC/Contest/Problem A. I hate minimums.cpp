#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto&i:a){
        cin >> i;
    }

    ll q;
    cin >> q;
    vector<pair<ll, ll>> queires (q);
    for(auto& j:queires){
        ll a, b;
        cin >> a >> b;
        j.first = a -1;
        j.second = b - 1;
    }

    for(auto p:queires){
        ll num = 0;
        for(int i = p.first; i <= p.second; i++){
            for(ll j = i; j <= p.second; j++){
                ll mini_sub = LLONG_MAX;
                ll mini = LLONG_MAX;
                if(i != p.first || j != p.second){
                    for(ll b = p.first; b <= p.second; b++){
                        if(b >= i && b <= j){
                            mini_sub = min(mini_sub, a[b]);
                        }else{
                            mini = min(mini, a[b]);
                        }
                }
                } else{
                    mini = 0;
                }
                if(mini_sub == mini){
                    num += 1;
                }
            }
        }
        cout << endl << num;
    }
    return 0;
}