#include <iostream>
using namespace std;
using ll = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count;
    cin >> n;
    count = 0;
    for (int i = 0; i < n; i++){
        int total, a, b, c;
        cin >> a >> b >> c;
        total = 0;
        total += a + b + c;
        if (total >= 2){
            count += 1;
        }
    }
    cout << count;
}