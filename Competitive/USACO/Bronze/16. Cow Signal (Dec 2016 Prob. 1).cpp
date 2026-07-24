#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;
    vector<string> symbol;
    
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        symbol.push_back(s);
    }

    for(string s:symbol){
        for(int i = 0; i < k; i++){
            for(char c:s){
                for(int j =0; j < k; j++){
                    cout << c;
                }
            }
            cout << endl;
        }
    }
    return 0;
}