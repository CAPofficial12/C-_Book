#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> nums){
    vector<int> final;
    nums.push_back(-1);
    for (int i = 1; i < nums.size(); i++){
        auto index = find(nums.begin(), nums.end(), i);
        if (index == nums.end()){
            final.push_back(i);
        }
    }

    return final;
}

int main(){

    vector<int> test = {};
    vector<int> ans = solution(test);
    return 0;
}