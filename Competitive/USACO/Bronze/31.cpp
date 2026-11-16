#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("socdist1.in", "r", stdin);
    //freopen("socdist1.out", "w", stdout);

    ll n;
    cin >> n;
    vector<ll> stall(n);
    vector<ll> posa(n, 0);
    vector<ll> pos;

    string num;
    cin >> num;
    ll og = false;
    for(ll i = 0; i < n; i++){
        ll c = num[i] - '0';
        if(c == 1){
            if(!og){
                pos.push_back(i);
                pos.push_back(i);
                og = true;
            }else{
                pos.push_back(i);
            }
        }
        stall[i] = c;
    }

    ll low = LLONG_MAX;
    ll high = LLONG_MIN;

    sort(pos.begin(), pos.end());
    ll size = pos.size();
    for(ll i = 1; i < size-1; i++){
        low = min(low, pos[i+1] - pos[i]);
        high = max(high, pos[i+1] - pos[i]);
    }

    pair<ll, ll> min1 = {0, 0};
    pair<ll, ll> min2 = {0, 0};
    ll counter = 1;
    size = pos.size();
    n = stall.size();
    counter = 1;

    for(ll i = 0; i < n; i++){
        ll diff = min(abs(i - pos[counter]), abs(i - pos[counter-1]));
        if(i == pos[counter]){
            counter++;
            posa[i] = 0;
            if (counter >= size){
                counter = size-1;
            }
        }
        else if (diff >= low){
            posa[i] = low;
        }else{
            posa[i] = diff;
        }

        if(min1.first < posa[i]){
            min1.first = posa[i];
            min1.second = i+1;
        }

    
    }

    counter = 1;
    pos.push_back(min1.second-1);
    sort(pos.begin(), pos.end());
    for(ll i = 0; i < n; i++){
        ll diff = min(abs(i - pos[counter]), abs(i - pos[counter-1]));
        if(i == pos[counter]){
            counter++;
            posa[i] = 0;
            if (counter >= size){
                counter = size-1;
            }
        }
        else if (diff >= low){
            posa[i] = low;
        }else{
            posa[i] = diff;
        }

        if(min2.first < posa[i]){
            min2.first = posa[i];
            min2.second = i+1;
        }

    
    }
    pos.push_back(min2.second-1);
    sort(pos.begin(), pos.end());

    low = LLONG_MAX;
    for(ll i = 1; i < size-1; i++){
        low = min(low, pos[i+1] - pos[i]);
    }

    cout << low;
    return 0;
}