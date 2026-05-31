#include <iostream>
using namespace std;

int main(){
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int length;
        cin >> length;
        for (int a = 0; a < length; a++){
            int b;
            cin >> b;
        }

        int rem = 10 - length;
        int choose = rem * (rem - 1) / 2;
        int password = choose * 6;
        cout << password << endl;
    }
    return 0;
}