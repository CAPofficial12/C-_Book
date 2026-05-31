#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int a,b;
    string x;
    cin >> a >> b >> x;

    vector<int> save = {};
    for (int i = 0; i < 2; i++){
        int a;
        cin >> a;
        save.push_back(a);
    }

    cout << a << b << x << endl;   
    
    for (int i: save){
        cout << i << " ";
    }
    return 0;
}