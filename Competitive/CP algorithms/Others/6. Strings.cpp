#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    string s = "banana";

    //Character Frequency
    map<ll, ll>  freq;
    for(char c : s){
        freq[c-'a'] += 1;
    }

    //Substring must be
    cout << "Substring: " << s.substr(0, 3) << endl;

    //Subsequence
    cout << "Subsequece: " << s[0] << s[2] << s[3];

    
    //Common prefix
    string a = "computer";
    string b = "compute";
    string ans = "";
    ll len= min(a.size(), b.size());
    ll count = 0;
    while(count < len){
        if(a[count] != b[count]){
            cout << endl << ans;
            break;
        }else{
            ans += a[count];
        }
        count++;
    }

    //Common suffix
    a = "playing";
    b = "running";
    ans = "";
    len= min(a.size(), b.size());
    while(len){
        len--;
        if(a[len] != b[len]){
            reverse(ans.begin(), ans.end());
            cout << endl << ans;
            break;
        }else{
            ans += a[len];
        }
    }
    return 0;
}