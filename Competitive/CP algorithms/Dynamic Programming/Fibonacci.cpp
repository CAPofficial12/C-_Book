#include <iostream>
#include <array>
#include <chrono>
using namespace std;
using inta = long long int;
int counter = 0;
auto start = chrono::high_resolution_clock::now();

void time(){
    auto Tans1 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = Tans1 - start;
    cout << "Execution time: " << duration.count() << " ms\n";
    auto start = chrono::high_resolution_clock::now();
}

inta custom(int n){
    array<inta,2> seq = {1,1};
    while (n > 2){
        inta temp = seq[0] + seq[1];
        seq[0] = seq[1];
        seq[1] = temp;
        n -= 1;
    }
    return seq[1];
}

int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + f(n - 2);
}

int main(){
    
    long long a = f(100);
    cout << a << endl;
    time();
    
    inta count;
    cin >> count;
    start = chrono::high_resolution_clock::now();
    for (int i = 1; i < count + 1; i++){
        inta b = custom(i);
        cout << i << " " << b << endl;
    }
    time();

    cin >> count;
    return 0;
}