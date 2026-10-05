#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<string> words (n);
    for(auto& c: words){
        cin >> c;
        reverse(c.begin(), c.end());
    }
    string ref = words[0];
    for(auto i: words){
        ll size = min(i.size(), ref.size());
        for(ll c = 0; c < size; c++){
            if (i[c] != ref[c]){
                ref = ref.substr(0, c);
                break;
            }
        }
        ref = ref.substr(0, size);
    }
    if (ref == ""){
        cout << "NO";
    }else{
        cout << "YES" << endl;
        cout << ref;
    }
    cout << "\n";
    return 0;
}