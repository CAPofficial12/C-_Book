#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;
		vector<int> elsie_log = vector<int>(n);
		int log_sum = 0;
		for (int &h : elsie_log) {
			cin >> h;
			log_sum += h;
		}

		if (log_sum == 0) {
			cout << 0 << '\n';
			continue;
		}

		auto valid = [&](int num_hours) {
			int curr_sum = 0;  // The current number of hours Elsie's logging
			for (int h : elsie_log) {
				curr_sum += h;
				if (curr_sum > num_hours) {
					return false;  // curr_sum can't exceed num_hours
				} else if (curr_sum == num_hours) {
					curr_sum = 0;
				}
			}
			return true;
		};

		// Try possible number of hours after modification in increasing order.
		bool found = false;
		int max_factor = 0;
		for (int factor = 1; factor * factor <= log_sum; factor++) {
			max_factor = factor;
			if (log_sum % factor == 0 && valid(factor)) {
				// log_sum/factor is the total # of classes AFTER modifying
				cout << n - log_sum / factor << '\n';
				found = true;
				break;
			}
		}
		if (found) { continue; }

		for (int factor = max_factor; factor >= 1; factor--) {
			if (log_sum % factor == 0 && factor * factor != log_sum) {
				int num_hours = log_sum / factor;
				if (valid(num_hours)) {
					// log_sum/num_hours is the total # of classes AFTER modifying
					cout << n - log_sum / num_hours << '\n';
					break;
				}
			}
		}
	}
}