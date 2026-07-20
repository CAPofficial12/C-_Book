#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("cownomics.in", "r", stdin);
    //freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> spotty_genomes(n);
    vector<vector<char>> plain_genomes(n);
    for(auto& ge: spotty_genomes){
        vector<char> spot(m);
        for(auto& g:spot){
            cin >> g;
        }
        ge = (spot);
    }

    for(auto& ge: plain_genomes){
        vector<char> spot(m);
        for(auto& g:spot){
            cin >> g;
        }
        ge = (spot);
    }

    tuple<int, int, int>saved;
    int points = 0;

    for(int a = 0; a < m; a++){
        for(int b = a + 1; b < m; b++){
            for(int c = b + 1; c < m; c++){
                bool flag = false;
                int p = 0;

                set<tuple<char, char, char>> place = {};
                set<tuple<char, char, char>> test = {};

                saved = make_tuple(a, b, c);
                for(int i = 0; i < n; i++){
                    char a1 = spotty_genomes[i][a];
                    char b1 = spotty_genomes[i][b];
                    char c1 = spotty_genomes[i][c];
                    test.insert(make_tuple(a1,b1,c1));
                }

                for(int i = 0; i < n; i++){
                    char a2 = plain_genomes[i][a];
                    char b2 = plain_genomes[i][b];
                    char c2 = plain_genomes[i][c];
                    tuple<char, char, char> amte= make_tuple(a2,b2,c2);
                    if (test.count(amte) != 0){
                        flag = true;
                    }
                
                }

                if (!flag){
                    points++;
                }
            }
        }
    }
    cout << points;
    return 0;

}
