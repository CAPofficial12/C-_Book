#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using lln = long long int;

int search(lln n, string& list){

    for (int i; i < n+1; i++){
        string ref = " ";
        ref.append(to_string(i));
        ref.append(" ");
        
        long long int loc = list.find(ref);
        if (loc < 0){
            return i;
        } else {
            list.erase(loc, size(ref)-1);
        }
    }
    return 0;
}

int main(){
    string n;
    string tt;
    //getline(cin, n);
    //getline(cin, tt);

    long long a = stoll(n);
    int value = search(a, tt);
    cout << value;
    return 0;
}