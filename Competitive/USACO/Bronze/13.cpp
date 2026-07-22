#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool check(vector<ll> reference){
    ll r = reference[0];
    for(auto c:reference){
        if (r != c){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1;
    cin >> T;

    for(ll j = 0; j < T; j++){

        ll n;
        cin >> n;
        
        vector<ll> cl (n);
        ll max = 0;
        for(auto& c: cl){
            cin >> c;
            if (c > max){
                max = c;
            }
        }

        ll steps = 0;
        while(!check(cl)){
            for(ll i = 0; i < cl.size()-1;i++){
                if (cl[i] < max){
                    cl[i] +=  cl[i + 1];
                    cl.erase(cl.begin() + i+1);
                    steps += 1;
                }  if (cl[i] > max){
                    max = cl[i];
                }

                if (cl.size() == 2){
                    cl[i] +=  cl[i + 1];
                    cl.erase(cl.begin() + i+1);
                    steps += 1;
                }

            }
        }
        cout << steps << "\n";
    }

    return 0;
}