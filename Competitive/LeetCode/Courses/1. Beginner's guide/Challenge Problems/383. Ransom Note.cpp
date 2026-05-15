#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstructsFast (string ransomNote, string magazine){
    unordered_map<char, int> map; 
    for (char i: magazine){
        map[i] += 1;
    }

    for(char a: ransomNote){
        map[a] -= 1;
        if (map[a] < 0){
            return false;
        }
    }

    return true;
}

bool canConstructsFast (string ransomNote, string magazine){
    for (char i: ransomNote){
        auto a = magazine.find(i);
        if (a != 18446744073709551615){
            magazine.erase(a, 1);
        } else{
            return false;
        }
    }
    return true;
}

int main(){
    string testR = "aabe";
    string testM = "aabdc";
    bool final = canConstructsFast(testR, testM);
    //cout << final;
    return 0;
}