#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int n;
    cin >> n;
    vector<ll> cows(n);
    vector<ll> bovine (n);

    for(auto& c: cows){
        cin >> c;
    }

    for(auto& b: bovine){
        cin >> b;
    }

    ll OG = 0;
    for(ll i = 0; i < n; i++){
        if(cows[i] == bovine[i]){
            OG ++;
        }
    }

    vector<ll> ans(n+1,0);
    for(ll centre = 1; centre < n; centre++){
        ll start = centre - 1;
        ll end = centre;
        ll total = 0;
        while (start >= 0 && end < n){

            if(cows[end] == bovine[start]){
                total += 1;
            }
            if (cows[start] == bovine[end]){
                total += 1;
            }
            if (cows[start] == bovine[start]){
                total -= 1;
            }
            if(cows[end] == bovine[end]){
                total -= 1;
            }
            start--;
            end++;
            ans[total + OG] ++;
        }
    }

    for(ll centre = 0; centre < n; centre++){
        ll start = centre;
        ll end = centre;
        ll total = 0;
        while (start >= 0 && end < n){
            if(cows[end] == bovine[start]){
                total += 1;
            }
            if (cows[start] == bovine[end]){
                total += 1;
            }
            if (cows[start] == bovine[start]){
                total -= 1;
            }
            if(cows[end] == bovine[end]){
                total -= 1;
            }
            ans[OG+total] += 1;

            start --;
            end++;
        }
    }
    for(auto a: ans){
        cout << a << endl;
    }

    return 0;
}