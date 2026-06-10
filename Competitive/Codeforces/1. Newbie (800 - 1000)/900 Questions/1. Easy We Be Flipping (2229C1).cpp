#include <iostream>
#include <array>
#include <vector>
using namespace std;


int num = 0;
vector<int> solution(vector<int> array){
    vector<int> ans = {};
    int size = array.size();
    int multiplier = 1;
    int test = 0;

    for (int i = size -1; i > -1; i--){
        test = array[i] * multiplier;
        if (test > 0){
            multiplier *= -1;
            ans.push_back(i+1);
            num += 1;
        }
    }

    vector<int> final = {ans};

    return final;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++){
        vector<int> save = {};
        int length;
        cin >> length;
        save.resize(length);

        for(int a = 0; a < length; a++){
            int b;
            cin >> b;
            save[a] = b;
        }

        vector<int> ans = solution(save);
        cout << num << "\n";
        for (int i: ans){
            cout << i << " ";
        }
        cout << "\n";

        num = 0;
    }
    return 0;
}