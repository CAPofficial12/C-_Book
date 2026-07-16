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
    for (int i = 0; i < names.size(); i++){
        output[names[i]] = 7;
    }

    vector<string> display = names;
    vector<string> old_display = names;
    int change = 0;
    for (auto& measure: measurements){
        
        output[get<1>(measure)] += get<2>(measure);
        int maxa = max(max(output["Bessie"], output["Elsie"]), output["Mildred"]);
        display = {};
        if(output["Bessie"] == maxa){
            display.push_back("Bessie");
        }

        if(output["Elise"] == maxa){
            display.push_back("Elsie");
        }

        if(output["Mildred"] == maxa){
            display.push_back("Mildred");
        }

        if (display != old_display){
            change += 1;
        }
        old_display = display;
    }
    cout << change;
    return 0;
}