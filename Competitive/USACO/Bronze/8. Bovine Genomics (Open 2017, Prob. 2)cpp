#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<string> spotty(n);
	vector<string> normal(n);

	for(auto& a:spotty){
		cin >> a;
	}

	for(auto& a:normal){
		cin >> a;
	}

	int count = 0;
	for(int i = 0; i < m; i++){
		bool flag = false;
		set<char> nucleo = {};
		int p = 0;
		for(int j = 0; j < n; j++){
			nucleo.insert(spotty[j][i]);
		}

		for(int j = 0; j < n; j++){
			p += nucleo.count(normal[j][i]);
		}

		if (p == 0){
			count += 1;
		}
	}
	cout << count;
	return 0;
}