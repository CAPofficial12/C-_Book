#include <iostream>
#include <set>
using namespace std;
using inta = long long int;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<int> saved = {};
    int size;
    cin >> size;
    for (int i = 0; i < size; i++){
        int a;

        cin >> a;
        saved.insert(a);
    }
    cout << saved.size();
}