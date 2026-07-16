#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<string>> blocks;
    vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for (int i = 0; i < n; i++){
        string up, down;
        cin >> up >> down;
        vector<string> block = {up, down};
        blocks.push_back(block);
    }

    map<char, int> letters;
    for(auto& c:alphabet){
        letters[c] = 0;
    }
    for(auto& b:blocks){
        string up = b[0];
        string down = b[1];
        map<char, int> letters_up;
        map<char, int> letters_down;
        for(char c: up){
            letters_up[c] += 1;
        }

        for(char c: down){
            letters_down[c] += 1;
        }

        for(char c: alphabet){
            letters[c] += max(letters_up[c], letters_down[c]);
        }
    }

    for(auto& [letter, num]: letters){
        cout << num << endl;
    }
    return 0;
}