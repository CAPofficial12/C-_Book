#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("circlecross.in", "r", stdin);
    //freopen("circlecross.out", "w", stdout);

    vector<vector<ll>> Exits(26);
    for(int i = 0; i < 52; i++){
        char c;
        cin >> c;
        c -= 'A';
        Exits[c].push_back(i);
    }

    ll cross = 0;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            char c = i + 'A';   
            char d = j + 'A';

            vector<ll> cowA = Exits[i];
            vector<ll> cowB = Exits[j];

            ll star_diff = cowB[0] - cowA[0];
            ll end_diff = cowB[1] - cowA[1];
            
            if (cowB[0] > cowA[0] && cowA[1] > cowB[0] && cowB[1] > cowA[1] || cowB[0] < cowA[0] && cowA[1] < cowB[0] && cowB[1] < cowA[1]){
                cross += 1;
            }
        }
    }
    cout << cross;
    return 0;
}