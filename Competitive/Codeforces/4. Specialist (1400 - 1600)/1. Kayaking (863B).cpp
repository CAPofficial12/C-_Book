#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> weigths (2*n);
    for(auto& i: weigths){
        cin >> i;
    }
    sort(weigths.begin(), weigths.end());

    ll maxDiff = LLONG_MIN;
    ll insta = 0;
    ll pair;
    for(ll i = 0; i < 2*n-1; i++){
        ll dif = weigths[i+1] - weigths[i];
        if (max(maxDiff, dif) > maxDiff){
            maxDiff = dif;
            pair = i;
        }
    }
    weigths.erase(weigths.begin() + pair);
    weigths.erase(weigths.begin() + pair);

    for(ll i = 1; i < weigths.size(); i+= 2){
        insta += weigths[i] - weigths[i-1];

    }
    cout << insta;
    return 0;
}