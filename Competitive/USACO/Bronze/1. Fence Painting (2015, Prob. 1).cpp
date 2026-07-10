#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("paint.in", "r", stdin);
    //freopen("paint.out", "w", stdout);

    int a;
    int b;
    int c;
    int d;

    cin >> a >> b;
    cin >> c >> d;

    int length;
    if (c <= b && a <= d){
        length = max(b, d) - min(a, c);
    } else{
        length = (b-a) + (d-c);
    }
    cout << length;
    return 0;
}