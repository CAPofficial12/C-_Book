#include <iostream>
using inta = long long int;
using namespace std;

inta calc(inta num, inta factorial){
    inta ans = 0;
    inta multiplier = 1;
    while (true)
    {   
        multiplier *= num;
        if (factorial/multiplier > 0){
            ans += factorial/multiplier;
        } else{
            break;
        }
    }

    return ans;
}
inta solution(inta factorial){
    inta trail = 0;
    inta num5 = calc(5, factorial);
    inta num2 = calc(2, factorial);
    trail = min(num5, num2);
    return trail;
}

int main(){
    inta input;
    cin >> input;
    inta ans = solution(input);
    cout << ans;
    return 0;
}