#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 1;
    long long mod = 1e9 + 7; // 10^9 + 7

    for (int i = 0; i < n; i++) {
        ans = (ans * 2) % mod;
    }

    cout << ans << "\n";
    return 0;
}