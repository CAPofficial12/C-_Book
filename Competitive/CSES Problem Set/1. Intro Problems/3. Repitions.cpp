#include <iostream>
using namespace std;

int main(){
    string n;
    cin >> n;
    
    long long int lon = 1;
    long long int count = 1;
    for(int i = 0; i < n.size()-1;i++){
        if (n[i] == n[i+1]){
            count += 1;
        } else{
            count = 1;
        }

        if (lon < count){
            lon = count;
        }

    }

    cout << lon;
    return 0;
}