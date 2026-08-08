#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    ll x = -1;
    cin >> n;
    vector<pair<char, ll>> mow(n);
    vector<pair<ll,ll>> path;
    pair<ll,ll> pos = {0,0};
    path.push_back(pos);
    for(auto& m:mow){
        cin >> m.first >> m.second;
        if(m.first == 'N'){
            pos.first += m.second;
        } else if(m.first == 'S'){
            pos.first -= m.second;
        }else if(m.first == 'E'){
            pos.second += m.second;
        }else if (m.first == 'W'){
            pos.second -= m.second;
        }
        path.push_back(pos);
    }
    ll c = 0;
    for (ll i = 2; i < path.size()-4; i++){
        for(ll j = i - 1; j >= 0; j++){
            pair<ll, ll> p1 = path[i];
            pair<ll, ll> p2 = path[i-1]; 
            pair<ll, ll> p3 = path[j];
            pair<ll, ll> p4 = path[j-1];
            bool dir_curr = (p1.second == p2.second);
            bool dir_check = (p3.second == p4.second);
            bool count = false;
            if(dir_curr == dir_check){
                if(!dir_curr){
                    ll down = min(p1.second,p2.second);
                    ll up = max(p1.second,p2.second);
                    ll y = p1.first;

                    ll left = min(p3.first,p4.first);
                    ll right = max(p3.first,p4.first);
                    ll x = p3.second;

                    bool x_check = (x > left && x < right);
                    bool y_check = (y > down && y < up);

                    if(x_check && y_check){
                        count = true;
                    }
                }else{
                    ll down = min(p3.second,p4.second);
                    ll up = max(p3.second,p4.second);
                    ll y = p3.first;

                    ll left = min(p1.first,p2.first);
                    ll right = max(p1.first,p2.first);
                    ll x = p1.second;

                    bool x_check = (x > left && x < right);
                    bool y_check = (y > down && y < up);

                    if(x_check && y_check){
                        count = true;
                    }
                }
            } else{
                if(dir_check){
                    ll left = min(p1.first,p2.first);
                    ll right = max(p1.first,p2.first);
                    ll y = p1.second;

                    ll high = min(p3.second,p4.second);
                    ll low = max(p3.second,p4.second);
                    ll x = p3.first;

                    bool x_check = (x > left && x < right);
                    bool y_check = (y > low && y < high);
                    if(x_check && y_check){
                        count = true;
                    }
                }else{
                    ll left = min(p3.first,p4.first);
                    ll right = max(p3.first,p4.first);
                    ll y = p3.second;

                    ll high = min(p1.second,p2.second);
                    ll low = max(p1.second,p2.second);
                    ll x = p1.first;

                    bool x_check = (x > left && x < right);
                    bool y_check = (y > low && y < high);
                    if(x_check && y_check){
                        count = true;
                    }
                }
            }

            if (count && p2 != p3){

            }
        }
    }
    
    return 0;
}