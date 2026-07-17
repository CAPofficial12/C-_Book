#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int n;
    cin >> n;
    vector<ll> set1;
    vector<ll> set2;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        set1.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        set2.push_back(a);
    }
    ll max = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll x1 = set1[i];
            ll x2 = set1[j];
            ll y1 = set2[i];
            ll y2 = set2[j];
            ll dist = (x2-x1)*(x2-x1) + (y2 - y1)*(y2 - y1);

            if (max < dist){
                max = dist;
            }
        }
    }
    cout << max;
    return 0;
}