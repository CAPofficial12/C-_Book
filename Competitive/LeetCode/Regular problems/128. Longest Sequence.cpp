#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int solution(vector<int> nums){
    
    sort(nums.begin(), nums.end());
    int highest_length = 0;
    int temp = 0;
    for (int i = 1; i < size(nums); i++){
        if (nums[i] - nums[i] == 1){
            temp ++;
        } else{
            temp = 0;
        }

        if (temp > highest_length){
            highest_length = temp;
            if (i == size(nums) - 1){
                highest_length ++;
            }
        }
    }

    return highest_length;
}

int main(){
    vector<int> test = {1,2,6,7,8};
    cout << solution(test) << endl;

    test = {};
    cout << solution(test) << endl;
    return 0;
}