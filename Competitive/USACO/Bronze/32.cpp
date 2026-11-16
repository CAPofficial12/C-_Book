#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    map<string, ll> Years = {{"Ox", 1},
        {"Tiger", 2},
        {"Rabbit", 3},
        {"Dragon", 4},
        {"Snake", 5},
        {"Horse", 6},
        {"Goat", 7},
        {"Monkey", 8},
        {"Rooster", 9},
        {"Dog", 10},
        {"Pig", 11},
        {"Rat", 12}};
    map<string, ll> born = {{"Bessie", 1}};
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        string cow, a, b, dir, year, c, d, ref;
        cin >> cow >> a >> b >> dir >> year >> c >> d >> ref;

        ll r = born[ref];
        ll target;

        if (r < 1 || r > 12){
            target = Years[year] + (r/12 + r/abs(r))*12;
        }else{
            target = Years[year];
        }

        ll dist = abs(target - r);
        
        if (dir == "previous"){
            if(r > target){
                dist *= -1;
            }else{
                dist -= 12;
            }
        }else{
            if(r > target){
                dist = 12 - dist;
            }
        }
    
        r = (r + dist);
        born[cow] = r;
    }

    cout << abs(born["Elsie"] - born["Bessie"]);
    

    return 0;
}