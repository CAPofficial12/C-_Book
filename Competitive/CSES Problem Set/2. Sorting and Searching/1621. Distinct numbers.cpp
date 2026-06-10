#include <iostream>
#include <vector>
using namespace std;
using inta = long long int;

int find(vector<int> base, int value){
    for(int i = 0; i < base.size(); i++){
        if (base[i] == value){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> saved = {};
    int size;
    cin >> size;
    for (int i = 0; i < size; i++){
        int a;

        cin >> a;
        if (find(saved, a) == -1){
            saved.push_back(a);
        }
    }
    cout << saved.size();
}