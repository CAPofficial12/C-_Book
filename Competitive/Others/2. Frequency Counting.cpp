#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ll n;
    cin >> n;
    vector<ll> set (n);
    map<ll, ll> freq;
    for(auto& c: set){
        cin >> c;
        freq[c]++;
    }

    cout << "NUMBER, FREQUENCY" << endl;
    for(auto& [key, value]: freq){
        cout << key << ", " << value << endl;
    }
    return 0;
}