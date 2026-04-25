#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int>& nums){
    std::map<int, int> counts;
    vector<int> refer;
    int r = -1;
    int y;
    int index1;
    int index2;
    int ind = 1;
    int fi;
    
    for (int i = 0; i < nums.size(); i++){
        refer.push_back(i+1);
    }

    for (int x : nums) {
        counts[x]++;
    }
    
    for (auto const& [val, count] : counts) {
        if (count > 1){
            r = count;
            y = val;
        }
    }

    for (int i = 0; i < nums.size(); i++){
        if(nums[i] == y){
            if (ind == 1){
                index1 = (unsigned)(i - (refer[i]-1));
                ind = 2;
            } else if(ind == 2){
                index2 = (unsigned)(i - (refer[i]-1));
            }
        }
    }
    fi = min(index1, index2);
    vector<int> ans = {y, fi+1};
    return ans;
}

int main(){
    vector<int> test = {1,1};
    vector<int> ans = solution(test);
    for (int i:ans){
        cout << i << endl;
    }

    return 0;
}