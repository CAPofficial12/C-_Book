#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll val = 3;
int main(){

    vector<ll> v = {3,5,10,3,1};
    ll first_pos = lower_bound(v.begin(), v.end(), val) - v.begin();
    cout << first_pos << endl;

    sort(v.begin(), v.end());
    auto frequency = upper_bound(v.begin(), v.end(), val)-lower_bound(v.begin(), v.end(), val);
    cout << frequency;
    return 0;
}