#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        int n = 3;
        //cin >> n;

        long long total = 0;
        long long total_min = LLONG_MAX;

        for (int i = 1; i <= n; i++) {
            long long height;
            cin >> height;

            total += height;
            total_min = min(total_min, total / i);

            cout << total_min;
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }
}