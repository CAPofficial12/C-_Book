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
        vector<ll> array (n);
        for(auto& c: array){
            cin >> c;
        }

        vector<ll> ref = array;
        sort(array.begin(), array.end());

        bool flag = true;
        for(ll i = 0; i < n; i++){
            if (ref[i] != array[i]){
                if (i < x){
                    if(array[i] != ref[i+x]){
                        flag = true;
                    }
                }else if(i > n-x-1){
                    if(array[i] != ref[i-x]){
                        flag = true;
                    }
                }else if(array[i] != ref[i-x] && array[i] != ref[i+x]){
                    flag = false;
                }
            }

            if (!flag){
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