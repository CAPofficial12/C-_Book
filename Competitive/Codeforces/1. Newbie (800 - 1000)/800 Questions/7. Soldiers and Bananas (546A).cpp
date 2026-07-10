#include <iostream>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;
    int cost = k * (w) * (w+1)/2;
    int diff = cost - n;
    if (diff <= 0){
        cout << 0;
    } else{
        cout << diff;
    }
    return 0;
}