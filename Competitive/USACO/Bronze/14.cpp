#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;
    vector <ll> cows(n);
    vector<ll> species(n);
    vector<ll> ans(n+1, 0);
    for(auto& c:cows){
        cin >> c;
    }

    for(auto& s:species){
        cin >> s;
    }

    ll og_op = 0;
    for(int i = 0; i < n; i++){
        if(cows[i] == species[i]){
            og_op += 1;
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = i; j < n; j++){
            ll num = og_op;
            for(ll a = i; a <= j; a++){
                if( cows[j-a+i] == species[a]){
                    num += 1; 
                }
                if(cows[a] == species[a]){
                    num -= 1;
                }

            }
            ans[num] += 1;
        }
    }

    for (auto a: ans){
        cout << a << endl;
    }
    return 0;
}