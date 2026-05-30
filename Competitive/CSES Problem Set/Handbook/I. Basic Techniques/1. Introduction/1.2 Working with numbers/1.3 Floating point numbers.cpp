#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a = 1;
    printf("%.9f\n", a);

    double b = 0.3 * 3 + 0.1;
    printf("%.20f\n", b); 
    //Although the answer is 1, rounding error causes a wroing answer to emerge
    // Hence, be caution when equating floating points and USE:
    if (abs(a - b) < 1e-8){
        printf("The are equal");
    }
    return 0;
}