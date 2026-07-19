#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll finda(vector<ll> set, auto num){

        for(int i = 0; i < set.size(); i++){
            if (set[i] == num){
                return i;
            }
        }
        return -1;
    }

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    ll k, n;
    cin >> k >> n;
    vector<vector<ll>> rankings (k);

    for(auto& a : rankings){
        vector<ll> ranks(n);
        for(auto& b: ranks){
            cin >> b;
        }
        a = ranks;
    }

    int cons = 0;
    vector<ll> init = rankings[0];
    rankings.erase(rankings.begin());

    for(int a = 0; a < n-1; a++){
        ll start = init[a];
        for(int b = a+1; b < n; b++){
            ll end = init[b];
            bool consti = false;
            for(auto& r:rankings){
                bool flag = false;
                bool cos = false;
                for(int i = 0; i < n; i++){
                    if (r[i] == start){
                        flag = true;
                    }

                    if (flag && r[i] == end){
                        cos = true;
                        break;
                    }
                }

                if (!cos){
                    consti = true;
                }
            }
            if (consti == false){
                cons += 1;
            }
        }
    }

    cout << cons;
    return 0;
}