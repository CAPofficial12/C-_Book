#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using inta = long long int;
auto start = chrono::high_resolution_clock::now();


vector<inta> seq = {0,1};
int counter = 0;

int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + f(n - 2);
}

int main(){
    int a = f(41);
    cout << a << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    cout << "Execution time: " << duration.count() << " ms\n";   
    cin >> a;
    return 0;
}