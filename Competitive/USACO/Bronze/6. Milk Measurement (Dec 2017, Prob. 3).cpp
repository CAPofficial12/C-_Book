#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const vector<string> names = {"Bessie", "Elsie", "Mildred"};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    ll test;
    vector<tuple<ll, string, ll>> measurements;
    cin >> test;

    for(int i = 0; i < test; i++){
        ll day, change;
        string name;
        cin >> day >> name >> change;
        measurements.push_back(make_tuple(day, name, change));
    }

    sort(measurements.begin(), measurements.end());


    map<string, int> output;
    //Shouldn't change much but it is more techinical usage 
    for (auto& name:names){
        output[name] = 7;
    }

    vector<string> display = names;
    vector<string> old_display = names;
    ll change = 0; //Always use ll instead of int

    for (auto& measure: measurements){

        output[get<1>(measure)] += get<2>(measure);

        int maxa = 0;
        for(auto&[redundant, out]:output){  //Replaced Nested Max statement with Loop
            maxa = max(maxa, out);
        }

        display = {};
        for(auto& [name, out]:output){  //Replaced Decision tree with a loop using measurements as unit
            if (out == maxa){
                display.push_back(name);
            }
        }

        if (display != old_display){
            change += 1;
        }
        old_display = display;
    }
    cout << change;
    return 0;
}