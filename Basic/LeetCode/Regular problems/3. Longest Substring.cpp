#include <iostream>
#include <map>
#include <string>
using namespace std;

int solution(string s){
    int ans;
    map<char, int> save;

    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size(); j++){
            save[s[j]] += 1;
            if (save[s[j]] == 2){

                if (ans < save.size()){
                    ans = save.size();
                }

                break;
            }
        }

        save.clear();
    }
    return ans;
}

int main(){
    string test = "abcabcbb";
    int ans = solution(test);

    cout << ans;
    return 0;
}