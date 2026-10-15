#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    multiset<ll> S = {};
    ll Q = 0;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        ll t, x;
        cin >> t >> x;
        if (t == 1){
            S.insert(x);
        } else if (t == 2){
            S.erase(x);
        } else if (t==3){
            ll count = 0;
            ll maximum = 0;
            ll ad = 0;
            for(ll a:S){
                maximum = max(maximum, x&a);
            }
            for(ll a:S){
                if (maximum == x&a){
                    count ++;
                }
            }
            cout << maximum << " " << count << endl;
        }
    }

    return 0;
}