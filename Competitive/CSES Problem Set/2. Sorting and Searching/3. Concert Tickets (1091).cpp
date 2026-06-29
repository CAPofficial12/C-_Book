#include <iostream>
#include <set>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<ll> tickets;

    for (int i = 0; i < n; i++) {
        ll price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++) {
        ll budget;
        cin >> budget;

        // First ticket with price > budget
        auto it = tickets.upper_bound(budget);

        // No ticket <= budget
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        }
        else {
            --it;                   // Largest ticket <= budget
            cout << *it << '\n';
            tickets.erase(it);      // Remove only this ticket
        }
    }

    return 0;
}