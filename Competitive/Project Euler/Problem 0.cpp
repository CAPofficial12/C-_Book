#include <iostream>
#include <string>
using namespace std;

int main(){
    unsigned long long total = 0;
    int n = 472000;
    for (long long i = 1; i < n + 1; i += 2){
        total += i * i;
    }
    cout << total;
    return 0;
}