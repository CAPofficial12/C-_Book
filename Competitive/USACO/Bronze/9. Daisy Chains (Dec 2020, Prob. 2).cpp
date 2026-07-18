#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int n;
    cin >> n;

    vector<int> petals(n);

    for(auto& p:petals){
        cin >> p;
    }
    ll total = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            ll sub = 0;
            for(int a = i; a < j+1; a++){
                sub += petals[a];
            }
            ll diff = j - i + 1;
            ll avg = sub/diff;

            for(int a = i; a < j+1; a++){
                if (petals[a] == avg && sub%diff == 0){
                    total += 1;
                    break;
                }
            }
        }
    }
    cout << total;
    return 0;   
}