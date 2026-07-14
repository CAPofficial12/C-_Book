#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int close_start, close_end;
    if (abs(a-x) < abs(a-y)){
        close_start = x;
    } else{
        close_start = y;
    }
    if (abs(b-x) < abs(b-y)){
        close_end = x;
    } else{
        close_end = y;
    }
    if (close_start == close_end){
        cout << abs(a-b);
    } else{
        cout << abs(a - close_start) + abs(b-close_end);
    }
    return 0;
}