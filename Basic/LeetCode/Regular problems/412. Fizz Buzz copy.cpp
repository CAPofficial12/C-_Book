#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> FizzBuzz(int n){
    vector<string> final = {};
    for (int i = 1; i < n+1; i++ ){
        if (i%15 == 0){
            final.push_back("FizzBuzz");
        } 
        else if (i%3 == 0){
            final.push_back("Fizz");
        }
        else if (i%5 == 0){
            final.push_back("Buzz");
        } else{
            string str = to_string(i);
            final.push_back(str);
        }
    }
    return final;

}

int main(){
    int test = 5;
    vector<string> ans = FizzBuzz(test);
    for (string i:ans){
        cout << i << endl;
    }
    
    return 0;
}