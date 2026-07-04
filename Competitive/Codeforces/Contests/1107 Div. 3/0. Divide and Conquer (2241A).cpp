#include <iostream>
#include <string>
using namespace std;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 0;
    cin >> test;

for (int i = 0; i < test; i++){
    int x, y;
    string ans = "YES";
    cin >> x >> y;

    if (x % y != 0){
        ans = "NO";
    }
    cout << ans << endl;
    /*while (x != y || x < y){
        int z = 2;
        while (x % z != 0){
            z ++;
        }
        x %= z;
    }*/
    }
    return 0;
}
// Test Primes