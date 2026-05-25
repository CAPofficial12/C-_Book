#include <iostream>
#include <vector>
using namespace std;
using inta = long long int;

inta solution(vector<inta> input){
    inta count = 0;
    inta min = 0;
    for (inta i: input){
        if (i >= min){
            min = i;
        } else{
            count += min - i;
        }
    }
    return count;
}

int main(){
    inta length;
    vector<inta> input;
    cin >> length;
    for (int i = 0; i < length; i++){
        inta a = 0;
        cin >> a;
        input.push_back(a);
    }
    inta ans = solution(input);
    cout << ans;

    return 0;
}