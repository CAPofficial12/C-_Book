#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

bool good(ll x){
    bool seen[10] = {};
    int cnt = 0;
    while(x){
        int d = x % 10;
        if(!seen[d]){
            seen[d] = true;
            cnt++;
            if(cnt > 2) return false;
        }
        x /= 10;
    }
    return true;
}

vector<ll> gen_good_y(){
    vector<ll> v;

    for(int d = 1; d <= 9; d++){
        ll x = 0;
        for(int len = 1; len <= 9; len++){
            x = x * 10 + d;
            v.push_back(x);
        }
    }

    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            if(a == b) continue;
            for(int len = 2; len <= 9; len++){
                ll x = 0;
                for(int i = 0; i < len; i++){
                    x = x * 10 + (i % 2 ? b : a);
                }
                v.push_back(x);
            }
        }
    }

    return v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto cand = gen_good_y();

    int t;
    cin >> t;

    while(t--){
        ll x;
        cin >> x;

        for(ll y : cand){
            if(good(y) && good(x * y)){
                cout << y << "\n";
                break;
            }
        }
    }
}