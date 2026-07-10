#include <iostream>
#include <vector>
using namespace std;

vector<int> shells1 = {0,1,0};
vector<int> shells2 = {1,0,0};
vector<int> shells3 = {0,0,1};

vector<int> check(int a, int b, int g){
    vector<int> score = {0,0,0};
    a -= 1;
    b -= 1;
    g -= 1;

    swap(shells1[a],shells1[b]);
    swap(shells2[a],shells2[b]);
    swap(shells3[a],shells3[b]);
    if (shells1[g] == 1){
        score[0] = 1;
    }
    if (shells2[g] == 1){
        score[1] = 1;
    }
    if (shells3[g] == 1){
        score[2] = 1;
    }
    return score;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int swap;
    cin >> swap;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for (int i = 0; i < swap; i++){
        int a,b,g;
        cin >> a >> b >> g;
        vector<int> score= check(a,b,g);
        c1 += score[0];
        c2 += score[1];
        c3 += score[2];
    }
    cout << max(max(c1,c2), c3);
    return 0;
}