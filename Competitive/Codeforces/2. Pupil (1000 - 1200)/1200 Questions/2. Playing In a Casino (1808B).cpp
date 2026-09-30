#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> card(n);
        for(auto& integer: card){

            vector<ll> numbers(m);
            for(auto& num: numbers){
                cin >> num;
            }
            integer = numbers;
        }

        ll total = 0;
        if(n != 1){
            for(ll a = 0; a < n-1; a++){
                for(ll b = a+1; b < n; b++){
                    for(ll c = 0; c < m; c++){
                        total += abs(card[a][c] - card[b][c]);
                    }
                }

            }
        }
        cout << total << endl;
    }
    return 0;
}