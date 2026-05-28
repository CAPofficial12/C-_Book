#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;
auto start = chrono::high_resolution_clock::now();

void time(){
    auto Tans1 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = Tans1 - start;
    cout << "Execution time: " << duration.count() << " ms\n";
    auto start = chrono::high_resolution_clock::now();
}

long long binpowRec(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpowRec(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) // Bitwise operator just checks parity by using a mask with an AND operator
            res = res * a;
        a = a * a;
        b >>= 1; //Bitwise RIghtshift to divide b by 2 without remainder
    }
    return res;
}

int main(){
    cout << binpow(3, 10) << endl;
    time();
    return 0;
}