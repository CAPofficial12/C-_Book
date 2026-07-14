#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long int;

const int days = 100;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    vector<ll> Bessie(days);
    vector<ll> Elsie(days);
    vector<ll> Mildred(days);

    ll measurements;

    // Inputs
    cin >> measurements;
    for (ll i = 0; i < measurements; i++){
        ll day, value;
        string Name;
        cin >> day >> Name >> value;

        if (Name == "Bessie"){
            Bessie[day - 1] = value + 7;
        } else if (Name == "Elsie"){
            Elsie[day - 1] = value + 7;
        } else{
            Mildred[day - 1] = value + 7;
        }
    }

    ll B_Change = 0;
    ll E_Change = 0;
    ll M_Change = 0;
    int change = 0;
    string lead, prev_lead;
    for (int i = 0; i < days; i++){
        B_Change += Bessie[i];
        E_Change += Elsie[i];
        M_Change += Mildred[i];

        int high = max(max(B_Change, E_Change), M_Change);
        lead = " ";
        if (M_Change == high){
            lead.append("M");
        }

        if (E_Change == high){
            lead.append("E");
        }

        if (B_Change == high){
            lead.append("B");
        }

        int spaces = 0;

        for (char c: lead){
            if (c == ' '){
                spaces += 1;
            }
        }

        if (prev_lead != lead){
            change += spaces;
        }
        prev_lead = lead;
    }
    cout << change;
    return 0;
}