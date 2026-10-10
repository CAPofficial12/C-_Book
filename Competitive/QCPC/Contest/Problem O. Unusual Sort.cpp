#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<pair<ll,ll>> array (n);
        for (ll i = 0; i< n; i++){
            cin >> array[i].first;
            array[i].second = i;
        }

        sort(array.begin(), array.end());

        bool flag = true;
        for(ll i = 0; i < n; i++){
            if (array[i].second % x != i % x){
                flag = false;
                break;
            }
        
        }

        if (flag){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;

    }
    return 0;
}