#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> skipd = {3,2,1,3,1,2,3};
    int index = 0;
    int value = 0;
    int total = 0;

    int n = 1000000000;

void fast(){
    while (value < n - 1){
        value += skipd[index %7];
        total += value;
        index += 1;
    }
}

void slow(){
    for (int i = 1; i < n; i++){
        if(i%3 == 0 || i%5 == 0){
            total += i;
        }
    }
}

int main(){

    auto start = high_resolution_clock::now();
    fast();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << total << endl;
    cout << "Time taken: "
         << duration.count()
         << " nanoseconds" << endl;
    cout << endl;
    total = 0;
// Time second solution
    start = high_resolution_clock::now();

    slow();

    stop = high_resolution_clock::now();

    duration = duration_cast<nanoseconds>(stop - start);
    cout << total << endl;
    cout << "Time taken: "
         << duration.count()
         << " nanoseconds" << endl;
    return 0;
}