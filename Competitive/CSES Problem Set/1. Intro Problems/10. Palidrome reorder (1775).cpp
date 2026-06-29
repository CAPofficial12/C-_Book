#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int check = 0;
    int odd = 0;
    char mid;
    int Size = 0;
    unordered_map<char, int> Dict;
    string OG;
    vector<char> Palidrome;
    vector<char> keys;

    cin >> OG;  
    for (char i: OG){
        Dict[i] += 1;
    }
    Size = OG.size();
    Palidrome.resize(Size);

    if (Size % 2 == 1){
        check = 1;
    }

    vector<char> alpha = {};
    for (const auto& [key, value]: Dict){
        if (value % 2 == 1){
            odd += 1;
            mid = key;
            Dict[key] -= 1;
        }

        for (int i = 0; i < value; i++){
            alpha.push_back(key);
        }
    }

    if (odd > check){
        cout << "NO SOLUTION";
        return 0;
    } if (check == 1){
        Palidrome[Size/2] = mid;
    }

    for (int i = 0; i < Size/2; i++){
        Palidrome[i] = alpha[2*i];
        Palidrome[Size - 1 - i] = alpha[2 * i];
    }

    for (char i: Palidrome){
        cout << i;
    }

    return 0;
}