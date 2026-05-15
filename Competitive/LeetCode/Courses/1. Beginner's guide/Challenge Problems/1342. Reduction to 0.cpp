#include <iostream>
using namespace std;

int numberOfSteps(int& num){
    int steps = 0;
    while (num != 0){
        if (num % 2 == 0){
            num /= 2;
        } else{
            num -= 1;
        }
        steps += 1;
    }
    return steps;
}

int main(){
    int test = 123;
    int steps = numberOfSteps(test);
    cout << steps;
    return 0;
}