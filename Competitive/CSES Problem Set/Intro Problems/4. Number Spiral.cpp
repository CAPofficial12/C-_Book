#include <iostream>
#include <cmath>
using namespace std;
using inta = long long int;

inta Sol_square(inta x, inta y){
    inta ans;
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

    return ans;
}

inta Sol_Car(inta x, inta y){
    inta Maxi = max(x,y);
    inta top,side;
    inta ans;
    if (Maxi == x){
        if (Maxi % 2 == 1){
            top = pow(Maxi, 2);
            ans = top - (y-1);
        } else{
            top = pow(Maxi-1,2) + 1;
            ans = top + (y-1);
        }
    } else{
        if (Maxi % 2 == 0){
            side = pow(Maxi, 2);
            ans = side - (x-1);
        } else{
            side = pow(Maxi-1,2) + 1;
            ans = side + (x-1);
        }
    }
    return ans;
}

int main(){
    int tests = 1;
    //cin >> tests;
    for (inta i = 0; i < tests; i++){
            
        inta x;
        inta y;
        cin >> y;
        cin >> x;
            
        inta ans1 = Sol_Car(x,y);
        inta ans2 = Sol_square(x,y);
        cout << ans1 << " " << ans2;
        cout << endl;
    }
    return 0;
}