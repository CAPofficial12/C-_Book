#include <iostream>
#include <map>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string,int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; // The map uses a [key, value] structure

    cout << m["piano"] << "\n"; //An unfound key is automatically initalised as 0

    for (auto x : m) {
        cout << x.first << ": " << x.second << "\n"; // The iterator in a loop for a map is ordered first key, second map
    }
}