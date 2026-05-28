// C++ program to illustrate the maximum
// value that can be stored in long long int
#include <climits>
#include <iostream>
using namespace std;

// Driver Code
int main()
{
    // From the constant of climits
    // header file
    long long int valueFromLimits = LLONG_MAX;
    cout << "Value from climits "
         << "constant (maximum): ";
    cout << valueFromLimits
         << "\n";

    valueFromLimits = LLONG_MIN;
    cout << "Value from climits "
         << "constant (minimum): ";
    cout << valueFromLimits
         << "\n";

    return 0;
}