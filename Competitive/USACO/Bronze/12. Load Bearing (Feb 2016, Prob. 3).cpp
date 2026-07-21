#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin >> n >> b;
    set<ll> y;
    set<ll> x;
    vector<vector<ll>> cows;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x.insert(a+1);
        y.insert(b+1);
        x.insert(a-1);
        y.insert(b-1);

        vector<ll> s= {a, b};
        cows.push_back(s);
    }

    ll lowest_M = n;
    for(auto a: x){
        for(auto b: y){
            vector<ll> quad = {0,0,0,0};
            for(auto& c:cows){
                ll x = c[0];
                ll y = c[1];

                if (x > a){
                    if (y > b){
                        quad[3] += 1;
                    } else{
                        quad[2] += 1;
                    }
                }else{
                    if (y > b){
                        quad[0] += 1;
                    } else{
                        quad[1] += 1;
                    }   
                }
            }
            ll mileage = 0;
            for(auto q:quad){
                if (q > mileage){
                    mileage = q;
                }
            }

            if (lowest_M > mileage){
                lowest_M = mileage;
            }
        }
    }
    cout << lowest_M;
    return 0;
}