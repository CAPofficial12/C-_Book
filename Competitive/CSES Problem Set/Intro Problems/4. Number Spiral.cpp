#include <iostream>
#include <cmath>
using namespace std;
using inta = long long int;

int main(){
    int tests = 5;
    //cin >> tests;

    for(int i = 0; i < tests; i++){
        inta ans;
        inta x = 5, y = 3;
        //cin >> y;
        //cin >> x;
        inta Max = max(x,y);
        inta Min = min(x,y);
        inta square = pow(Max, 2) - Max + 1;
        int diff = y-x;
        if (Max % 2 == 0){
            ans = square + diff;
        } else{
            ans = square - diff;
        }

        cout << ans << endl;

    }
    return 0;
}