#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //Makes IO more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);   Reads from an input file
    //freopen("output.txt", "w", stdout);   Writes to an output file

    int a, b;
    cin >> a >> b;

    cout << a << endl;      //Slightly Slower
    cout << b << "\n";      //Slightly faster

    //scanf("%d %d", a, b);       C variant of C++ IO is faster
    //printf("%d %d\n", a, b);    But its difficult to use

    string x;
    getline(cin, x);
    printf("%s\n",x);

    vector<int> save = {};
    while (cin >> x){
        save.push_back(2);
    }

    return 0;
}