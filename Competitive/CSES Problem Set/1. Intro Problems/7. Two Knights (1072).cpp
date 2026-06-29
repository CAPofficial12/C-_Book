#include <iostream>
#include <vector>
using namespace std;
using inta = long long int;

int main(){
    vector<inta> number = {0,6,28,96};
    inta i;
    cin >> i;
    for (inta k = 5; k <= i; k++){
        inta area = k*k;
        inta inner = (k-4)*(k-4);
        inta possible = 0;
        possible += 4 * (area - 3);//Corners
        possible += 8 * (area - 4);//Adjecent corners
        possible += (4 * (k - 4)) * (area - 5); // Middle edge
        possible += 4 * (area - 5); // Inner corners
        possible += (4 * (k - 4)) * (area - 7); //Inner middle
        possible += inner * (area - 9); //Middle
        possible /= 2;
        number.push_back(possible);
    }

    for(inta a = 0; a < i; a++){
        cout << number[a] << "\n";
    }

    return 0;
}