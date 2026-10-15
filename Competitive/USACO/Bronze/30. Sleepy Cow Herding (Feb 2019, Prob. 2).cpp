#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

ll diff(ll a, ll b){
    return abs(a-b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    ll b, e, m;
    cin >> b >> e >> m;
    vector<ll> cows = {b, e, m};
    sort(cows.begin(), cows.end());
    ll low = min(abs(cows[1] - cows[2]), abs(cows[0] - cows[1]));
    ll high = max((cows[1] - cows[0]), (cows[2] - cows[1]));
    if (high == 1){
        cout << "0 " << endl;
    }
    else if (low == 2){
        cout << "1" << endl;
    }else{
        cout << "2" << endl;
    }
    cout << high - 1 << endl;
    return 0;
}