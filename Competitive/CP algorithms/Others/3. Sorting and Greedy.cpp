#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> set(n);
    for(auto& c: set){
        cin >> c.second >> c.first;
    }
    sort(set.begin(), set.end());
    ll end = set[0].first;
    cout << set[0].second << " " << set[0].first << endl;
    for(auto& c: set){
        if(c.second > end){
            cout << c.second << " " << c.first << endl;
            end = c.second;
        }
    }
    return 0;
}