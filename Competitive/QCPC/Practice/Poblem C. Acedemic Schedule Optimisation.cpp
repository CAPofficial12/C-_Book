#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll number(vector<tuple<ll, ll, ll>> array, ll n){
    ll total = 0;
    ll end = 0;

    for(ll i = 0; i < array.size(); i++){
        if(get<2>(array[i]) <= n && get<1>(array[i]) > end){
            total += 1;
            end = get<0>(array[i]);
        }
    }
    return total;
}

int main(){
    ll t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;
        vector<tuple<ll, ll, ll>> array(n);
        ll high_bin = LLONG_MIN;
        ll low_bin = LLONG_MAX;

        for(auto& c:array){
            cin >> get<1>(c) >> get<0>(c) >> get<2>(c);
            high_bin = max(high_bin, get<2>(c));
            low_bin = min(low_bin, get<2>(c));
        }

        sort(array.begin(), array.end());
        ll old_total = number(array, high_bin);

        while (low_bin < high_bin){
            ll guess = (high_bin + low_bin)/2;
            ll total = number(array, guess);

            if (total < old_total){
                low_bin = guess+1;
            }else if(total == old_total){
                high_bin = guess;
            }
        }
        cout << old_total << " " << low_bin << "\n";
    }

    return 0;
}