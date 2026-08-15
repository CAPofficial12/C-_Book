
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll sizer(vector<vector<char>> c){
    sort(c.begin(), c.end());
    vector<char> g;
    ll total = 0;
    for(auto ca:c){
        if(ca != g){
            total += 1;
        }
        g = ca;
    }
    return total;
}

ll sizerl(vector<char> c){
    set<char> s(c.begin(), c.end());
    return s.size();
}

vector<vector<char>> single, dual;

void check(vector<char> vert){
    set<char> s(vert.begin(), vert.end());
    if (s.size() == 1){
        single.push_back(vert);
    } else if (s.size() == 2){
        vector<char> track(s.begin(), s.end());
        dual.push_back(track);
    }
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("tttt.in", "r", stdin);
freopen("tttt.out", "w", stdout);

vector<vector<char>> grid;
for(ll i = 0; i < 3; i++){
    vector<char> a;
    for(int i = 0; i < 3; i++){
        char t;
        cin >> t;
        a.push_back(t);
    }
    grid.push_back(a);
}

vector<char> diagonal, inv_dia;
for(int i = 0; i < 3; i++){
    vector<char> vert = {grid[i][2], grid[i][1], grid[i][0]};
    vector<char> hori = {grid[2][i], grid[1][i], grid[0][i]};
    check(vert);
    check(hori);

    diagonal.push_back(grid[i][i]);
    inv_dia.push_back(grid[2-i][i]);
}
check(diagonal);
check(inv_dia);

cout << sizer(single) << endl;
cout << sizer(dual) << endl;
return 0;
}