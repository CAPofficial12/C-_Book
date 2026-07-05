#include <iostream>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

void print_deques(deque<int> d){
    for (int i:d){
        cout << i << ", ";
    }
    cout << endl;
}

void bits(){
    bitset<10> s(string("0100110101"));
    cout << s << endl;
    s[0] = 1;
    cout << "4th value: " << s[3] << endl;
    cout << "Number of 1s: " << s.count() << endl;

    cout << endl << "Calculations: " << endl;
    bitset<3> a = 010;
    bitset<3> b = 110;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "AND operator: "  << (a&b) << endl;
    cout << "OR operator: " << (a|b) << endl;
    cout << "XOR operator: " << (a^b) << endl;
    cout << endl;
}

void deques(){
    deque<int> d = {5,3};
    cout << "Original Deque: ";
    print_deques(d);

    d.push_back(0); // Functions same as a vector
    d.push_front(1);// Adds a value to the end of the deque
    cout << "Added Deque: " ;
    print_deques(d);

    d.pop_back();   // Functions same as vector
    d.pop_front();  // Remove the first value of the deque
    cout << "Removed Deque: " ;
    print_deques(d);

}
int main(){
    bits();
    deques();
    return 0;
}