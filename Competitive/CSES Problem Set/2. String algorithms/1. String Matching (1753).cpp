#include <iostream>
#include <string>
#include <vector>
using namespace std;

string MS;
string sub;
int len;

void input();
int subsearch(int ans);
int old_old_solution();


vector<int> buildFailure(const string& p) {
    int m = p.size();
    vector<int> f(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = f[j-1];
        if (p[i] == p[j]) j++;
        f[i] = j;
    }
    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text, pat;
    cin >> text >> pat;

    vector<int> f = buildFailure(pat);

    int ans = 0, j = 0;
    int n = text.size(), m = pat.size();
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pat[j]) j = f[j-1];
        if (text[i] == pat[j]) j++;
        if (j == m) {
            ans++;
            j = f[j-1];  // allow overlapping matches
        }
    }

    cout << ans;
    return 0;
}

int subsearch(int ans){
    for (int i = 0; i < MS.size(); i++){
        for(int e = 0; e < sub.size(); e++){
            if(sub[e] != MS[i+e]){
                break;
            }
            if (e == sub.size()-1){
                ans += 1;
            }
        }
    }
    return ans;
}

int old_old_solution(){
    int ans = 0;
    char start = sub[0];
    for (int i = 0; i < MS.size(); i++){

        if (MS[i] == start){
            string check = MS.substr(i, len);

            if (check == sub){
                ans += 1;
            }
        }
    }
    return ans;
}


void input(){
    cin >> MS >> sub;
    len = sub.size();
}