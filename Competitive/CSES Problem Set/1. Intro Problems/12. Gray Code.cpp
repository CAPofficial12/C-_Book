#include <iostream>
#include <vector>
using namespace std;
using inta = long long int;

inta power(inta n){
    inta val = 1;
    for(inta i = 0; i < n; i++){
        val *= 2;
    }
    return val;
}

void printa(vector<bool> num){
    for(inta i = num.size()-1; i >= 0; i--){
        cout << num[i];
    }
    cout << endl;
}

int main(){
    inta total = 0;
    inta n;
    cin >> n;
    vector<bool> number(n, false);
    inta index = power(n);
    inta counter = 0;
    for (inta i = 0; i < index; i++){
        inta place = i;
        for (inta t = n-1; t >= 0; t-- ){
            if (power(t) <= place){
                number[t] = true;
                place -= power(t);
            }
        }
        printa(number);
        total += 1;
        number.assign(number.size(), false);
    }
    return 0;
}