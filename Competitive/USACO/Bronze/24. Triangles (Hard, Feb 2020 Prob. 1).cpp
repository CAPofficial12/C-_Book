#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pai = pair<ll, ll>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("triangles.in","r", stdin);
    freopen("triangles.out", "w", stdout);

    ll n;
    cin >> n;
    vector<pai> X(n);
    pai a;
    for(auto& [x, y]:X){
        cin >> x >> y;
    }  

    ll area = LLONG_MIN;
    for(ll c = 0; c < n; c++){
        ll H = LLONG_MIN;
        ll W = LLONG_MIN;

        for(ll e = 0; e < n; e++){
            if(X[e].first == X[c].first){
                ll diff = abs(X[e].second - X[c].second);
                H = max(H, diff);
            }

            if(X[e].second == X[c].second){
                ll diff = abs(X[e].first - X[c].first);
                W = max(W, diff);
            }
        }
        area = max(area, H*W);
    }
    cout << area;
    return 0;
}