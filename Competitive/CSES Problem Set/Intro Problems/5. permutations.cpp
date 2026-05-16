#include <iostream>
#include <array>
#include <vector>
using namespace std;

vector<int> Solution(int len){
    vector<int> beutiful;
    vector<int> ref;
    beutiful.resize(len);
    for(int i = 1; i < len+1; i+=2){
        ref.push_back(i+1);
    }

    for (int i = 0; i < len/2; i ++){
        beutiful[i] = ref[i];
    }

    for(int i = len/2; i < len; i ++){
        beutiful[i] = ref[i-len/2] - 1;
    }

    return beutiful;
}

int main(){
    int s;
    cin >> s;
    if (s > 3){
        vector<int> ans = Solution(s);
        for (int i: ans){
            cout << i << " ";
        }
    } else if (s == 3 || s == 2){
        cout << "NO SOLUTION";
    } else{
        cout << s;
    }

    cin >> s;
    return 0;
}