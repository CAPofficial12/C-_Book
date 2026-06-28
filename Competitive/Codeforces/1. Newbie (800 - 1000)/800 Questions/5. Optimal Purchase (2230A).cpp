#include <iostream>
using namespace std;
using inta = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    inta tests;
    cin >> tests;
    for (inta i = 0; i < tests; i++){

        inta n, a, b;        

        cin >> n >> a >> b;

        inta ans = (n / 3) * min(3*a, b);
        if (n % 3 == 1){
            ans += min(a, b);
        }
        else if (n % 3 == 2){
            ans += min(2*a, b);
        }

        cout << ans << '\n';
        cout << "\n";
    
    }
    return 0;
}

