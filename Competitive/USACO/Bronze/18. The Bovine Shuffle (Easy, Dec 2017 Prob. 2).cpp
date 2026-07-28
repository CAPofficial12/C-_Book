#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);


    ll n;
    cin >> n;
    vector<ll>cows (n);
    vector<ll> id (n);
    for(auto& c:cows){
        cin >> c;
    }
    for(auto& I:id){
        cin >> I;
    }

    for(int i = 0; i < 3; i++){
        vector<ll> new_order (n);
        for(int j = 0; j < n; j++){
            new_order[j] = id[cows[j]-1];
        }
        id = new_order;
    }

    for(auto c: id){
        cout << c << endl;
    }
    return 0;
}