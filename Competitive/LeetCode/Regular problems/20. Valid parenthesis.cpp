#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isValid(string s){
    vector<char> order = {'a'};
    for(char i: s){
        if (i == '('){
            order.push_back(')');
        } else if (i == '{'){
            order.push_back('}');
        } else if (i == '['){
            order.push_back(']');
        } else if (i == order.back()){
            order.pop_back();
        } else{
            return false;
        }
        
    }
    order.pop_back();
    if (s.size() % 2 == 0 && order.size() == 0){
        return true;
    } else{
        return false;
    }
}

int main(){
    string test = "]";
    bool ans = isValid(test);
    cout << ans;
    return 0;
}