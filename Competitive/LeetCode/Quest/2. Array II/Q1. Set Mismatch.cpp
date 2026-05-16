#include <iostream>
#include <vector>
using namespace std;

vector<int> SOlution(vector<int>& nums){
    int value;
    int rep;

    int len = nums.size();
    vector<int> ref;
    ref.resize(len);
    for(int i = 1; i < len +1; i++){
        ref[i-1] = i;
    }
    for(int i = 0;i < len;i++){
        if (ref[nums[i]-1] == 0){
            rep = nums[i];
        }
        ref[nums[i]-1] = 0;
    }

    for (int i: ref){
        if (i != 0){
            value = i;
        }
    }
    vector<int> ans = {rep, value};
    return ans;
}

int main(){
    vector<int> nums = {1,2,2,4};
    vector<int> ans = SOlution(nums);
    return 0;
}