#include <iostream>
using inta = long long int;
using namespace std;

int main(){
    inta weight = 0;
    cin >> weight;
    if (weight % 2 == 0){
        cout << "YES";
    } else{
        cout << "NO";
    }
    
    return 0;
}