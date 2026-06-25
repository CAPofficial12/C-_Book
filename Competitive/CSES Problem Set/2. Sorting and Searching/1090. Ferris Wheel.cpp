#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    int gond = 0;
    int index = 0;
    vector<int> children;

    cin >> n;
    cin >> x;
    children.resize(n);
    for (int i = 0; i < n; i++){
        int weight;
        cin >> weight;
        children[i] = weight;
    }

    sort(children.begin(), children.end());
    int extra = 1;
    while (children[(children.size() - extra)/2] != 0){

        if (children.size() == 1 || children[index] + children[n - index - extra] > x){
            gond += 1;
            children[n - index - extra] = 0;
            extra += 1;
            
        } else{
            gond += 1;
            children[index] = 0;
            children[n - index - extra] = 0;
            index += 1;
        }
    }
    cout << gond;
    return 0;
}