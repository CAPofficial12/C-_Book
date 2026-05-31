#include <iostream>
#include <vector>
using namespace std;

int main(){
    int test;
    cin >> test;

    for (int i = 0; i < test; i++){
        int length;
        int largest = 0;
        int largest2 = 0;
        vector<int> nums;

        cin >> length;
        
        for (int e = 0; e < length; e++){
            int a;
            cin >> a;
            nums.push_back(a);

            if (a > largest){
                largest2 = largest;
                largest = a;
            } else if (a > largest2)
            {
                largest2 = a;
            }
        }

        for (int a: nums){
            if (a  == largest){
                cout << largest - largest2 << " ";
            } else{
                cout << a - largest << " ";
            }
        }
        cout << endl;

    }
    return 0;
}