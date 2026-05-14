#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int>& nums, int target){
    for (int i = 0; i < nums.size(); i++){
        for (int a = 0; a < nums.size(); a++){
            if (i != a && nums[i] + nums[a] == target){
                return{i, a};
            }
        }
    }
}

int main(){
    vector<int> test = {2,7,11,15};
    int test1 = 9;

    vector<int> ans = solution(test, test1);
    return 0;
}