#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> solution(vector<int> nums){
    unordered_map<int,int> values;
    vector<int> final;
    for (int i = 0; i < nums.size(); i++){
        values[i] = 0;
    }

    for (int i:nums){
        for (auto [key, value]: values){
            if (nums[key] > i){
                values[key] += 1;
            }
        }
    }
    for (auto [key, value]: values){
            final.insert(final.begin(), value);
        }
    return final;
}

int main(){
    vector<int> test = {60,14,3,39,49,43,53,24,33,13,32,93,65,26,77,55,2,28,2,50,18,4,92,20,57,90,64,86,54,69,28,80,88,66,57,28,67,83,3,50,86};
    vector<int> ans = solution(test);

    for (int i: ans){
        cout << i << endl;
    }
    return 0;
}