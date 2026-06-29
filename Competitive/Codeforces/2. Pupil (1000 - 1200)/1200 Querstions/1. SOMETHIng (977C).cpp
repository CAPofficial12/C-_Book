#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using inta = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<inta> Sets;
    inta n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        inta input;
        cin >> input;
        Sets.push_back(input);
    }
    sort(Sets.begin(), Sets.end());

    inta ans;

    if (k == 0){
        ans = Sets[0] -1;
    } else{
        ans = Sets[k - 1];
    }

    if (ans <= 0){
        ans = -1;
    }
    
    inta count = 0;
    for (int i: Sets){
        if (i <= ans){
            count++;
        }
    }

    if (count != k){
        ans = -1;
    }

    cout << ans;
    return 0;
}