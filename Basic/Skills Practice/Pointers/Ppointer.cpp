#include <iostream>
using namespace std;

void broken_swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << a;
    cout << b;
    // a and b are COPIES — original variables unchanged
}

// With pointers — WORKS
void real_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    /*
    int value = 42;
    int* Pvalue = &value;
    cout<< value << endl;
    cout << Pvalue << endl;
    *Pvalue = 5;
    cout << value;
    value = 34;
    */

    int x = 5, y = 10;
    real_swap(&x, &y);
    
    return 0;
}