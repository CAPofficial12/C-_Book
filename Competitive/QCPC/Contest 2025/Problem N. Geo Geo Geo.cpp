#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 0; 
    cin >> t;

    for(ll i = 0; i < t; i++){
        vector<ll> angles (4);

        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        angles[a-1] = b;
        angles[c-1] = d;
        angles[2-a] = 90 - b;
        angles[4-c+2] = 180 - (b + d);
        bool flag= false;
        for(ll e: angles){
            if(e <= 0 || e >= 90){
                flag = true;
            }

            if (e == angles[2] && e >= 90 && e < 180 || e == angles[3] && e >= 90 && e < 180){
                flag = false;
            }

        }

        if(flag){
            cout << "-1";
        } else{
            for(ll e: angles){
                cout << e << " ";
            }
        }
        cout << "\n"; 
    }
    return 0;
}