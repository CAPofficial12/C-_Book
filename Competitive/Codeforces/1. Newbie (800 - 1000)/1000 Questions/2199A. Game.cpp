#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int k;
        cin >> k;

        int a = 0;
        int b = 0;
        int wins = 0;

        for (int i = 0; i < 2; i++){
            int a1,b1;
            cin >> a1;
            cin >> b1;

            if (b1 > a1){
                wins += 1;
            }

            a += a1;
            b += b1;
        } 

        if (a - b < k){
            cout << "Yes" << "\n";
        } else if (a - b > k){
            cout << "No" << "\n";
        } else{
            if (wins == 0){
                cout << "No" << "\n";
            } else{
                cout << "Yes" << "\n";
            }
        }
    }
    return 0;
}
