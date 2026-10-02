#include <bits/stdc++.h>
using namespace std;

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> p(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// transpose to m by n to make sorting easier
				cin >> p[j][i];
			}
		}

		long long wins = 0;
		for (int i = 0; i < m; i++) {
			sort(p[i].begin(), p[i].end());
			for (int j = 0; j < n; j++) {
				// sum individual contributions per card
				wins += 1ll * (j - (n - 1 - j)) * p[i][j];
			}
		}

		cout << wins << '\n';
	}
}