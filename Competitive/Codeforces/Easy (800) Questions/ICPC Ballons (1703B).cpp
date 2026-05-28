#include <iostream>
#include <vector>
#include <string>
using namespace std;
using inta = long long int;

int main(){
    inta test_case;
    cin >> test_case;
    for (inta i = 0; i < test_case; i++){

        inta length = 0;
        string problems;
        inta balloons = 0;
        vector<char> alpha = {};

        cin >> length;
        cin >> problems;

        for (char c: problems){
            bool loc = false;
            for (char a: alpha){
                if (a == c){
                    loc = true;
                    break;
                }
            }

            if (loc){
                balloons += 1;
            } else{
                balloons += 2;
                alpha.push_back(c);
            }
        }

        cout << balloons << endl;
    }
    return 0;
}