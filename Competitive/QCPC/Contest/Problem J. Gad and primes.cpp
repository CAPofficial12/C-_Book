#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){

        ll size;
        cin >> size;

        bool flag = false;

        if (size >= 4){
            flag = true;
        }

        vector<ll> array (size);
        ll total = 0;

        for(auto& b: array){
            cin >> b;
            if (b == 1){
                flag = true;
            }
            total += b;
        }

        sort(array.begin(), array.end());

        if ((total %2 == 0 || total % 3 == 0) && size != 1){
            flag = true;
        }

        if(flag == true){
            cout << "-1";
        }else if (size == 1){
            if(array[0] == 1){
                cout << "-1";
            }else{
                cout << array[0];
            }   
        }else if(size == 2){
            cout << array[0] << " " << array[1];
        }else{
            vector<ll> solution = {2, 2, 3};
            if (array != solution){
                cout << "-1";
            } else{
                cout << "2 3 2";
            }
        }
        cout << "\n";
    }
    return 0;
}