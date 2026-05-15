#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> nums){
    vector<int> final;
    final.resize(nums.size());
    for (int i = 0; i < nums.size()-1; i++){
        for (int a: nums){
            if(nums[i] > a){
                final[i] += 1;
            }
        }
    }
    return final;
}

int main(){
    vector<int> test = {60,14,3,39,49,43,53,24,33,13,32,93,65,26,77,55,2,28,2,50,18,4,92,20,57,90,64,86,54,69,28,80,88,66,57,28,67,83,3,50,86};
    vector<int> ans = solution(test);
    return 0;
}