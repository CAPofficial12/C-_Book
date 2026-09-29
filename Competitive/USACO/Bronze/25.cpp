#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);


    ll n;
    cin >> n;

    vector<pair<ll, ll>> times(n);
    for (auto& i:times){
        cin >> i.first >> i.second;
        i.second --;
    }

    ll final = 0; 
    for (int i = 0; i < n; i++){
        ll total = 0;
        
        vector<ll> time;
        for(int a = 0; a<1000; a++){
            time.push_back(a);
        }
        
        for(int j = 0; j < n; j++){
            if(j != i){
                ll start = times[j].first;
                ll end = times[j].second;

                for(int count = start; count <= end; count++){
                    if(time[count] != -1){
                        total += 1;
                        time[count] = -1;
                    }
                }
            }
        }
        final = max(final, total);
    }
    cout << final;
    return 0;
}