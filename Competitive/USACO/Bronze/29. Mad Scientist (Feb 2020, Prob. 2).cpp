#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    ll n;
    string A, B;
    cin >> n >> A >> B;

    ll total = 0;
    if (A[0] != B[0]){
        total = 1;
    }

    for(ll i = 1; i < n; i++){
        if(A[i] != B[i] && A[i-1] == B[i-1]){
            total ++;
        }
    }
    cout << total;
    return 0;
}