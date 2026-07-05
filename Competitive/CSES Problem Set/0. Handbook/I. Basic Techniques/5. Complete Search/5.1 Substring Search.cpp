#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v){
    for(int i:v){
        cout << i<<" ";
    }
    cout << endl;
}
int main(){
    vector<int>s = {0,3,4};
    int n = s.size();
    int total = 0;
    for (int b = 0; b < (1 << n); b++){ //RTotates through the number of substrings present 
        vector<int> subset;
        for (int i = 0; i < n; i++){
            if (b & (1<<i) ){
                subset.push_back(i);
            }
        }
        print(subset);
    }
    cout << total;
    return 0;
}