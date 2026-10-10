#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    
    ll low = 0;
    ll high = n-1;
    bool flag = false;
    while(a[low].first + a[high].first != x && !flag){
        ll sum = a[low].first + a[high].first;
        if (sum > x){
            high--;
        }else if (sum < x){
            low++;
        }

        if(high < 0 || low >= n){
            flag = true;
        }
    }

    if(flag){
        cout << "IMPOSSIBLE";
    }else{
        cout << a[low].second<< " " << a[high].second;
    }
    return 0;
}