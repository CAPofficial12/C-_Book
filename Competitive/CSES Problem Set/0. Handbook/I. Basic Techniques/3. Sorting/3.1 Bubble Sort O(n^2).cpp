#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {1,3,8,21,98,2,56,6,8,2,58,63,4,6};
    int size = v.size();
    for (int i = 0; i < size; i++){
        for (int e = 0; e < size - 1; e++){
            if (v[e] > v[e+1]){
                swap(v[e], v[e+1]); //Inversion
            }
        }
    }

    for (int i:v){
        cout << i << " ";
    }
    return 0;
}