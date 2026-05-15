#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int tuff;
        for (string i:strs){
            int length;
            if (size(i) > size(prefix)){
                length = size(prefix);
            } else{
                length = size(i);
            }
            for (int a = 0; a < length; a++){
                if (prefix[a] != i[a]){
                    prefix = prefix.substr(0, a);
                    break;
                }
                tuff = a;
            }
            prefix = prefix.substr(0, tuff+1);
            if (i == ""){
                prefix = i;
            }
        }
        return prefix;
}
int main(){
    vector<string> test = {"abab","aba",""};
    string ans = longestCommonPrefix(test);
    cout << ans;

    return 0;
}