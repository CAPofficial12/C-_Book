#include <iostream>
#include <vector>
using namespace std;
using inta = long long int;


void printa(vector<inta> test){
    cout << test.size() << endl;
    for (inta i: test){
        cout << i << " ";
    }
    cout << endl;
}

inta asum(vector<inta> test){
    inta total = 0;
    for (inta i: test){
        total += i;
    }
    return total;
}

int main(){
    inta num;
    cin >> num;

    vector<inta> set1 = {};
    vector<inta> set2 = {};

    inta total = 0;
    for (inta i = 1; i <= num; i++){
        total += i;
    }

    inta target = 0;
    if (total % 2 == 0){
        target = total / 2;
    } else{
        cout << "NO";
        return 0;
    }

    for (inta i = num; i > 0; i--){
        if (target >= i){
            target -= i;
            set1.push_back(i);
        }else{
            set2.push_back(i);
        }
    }

    if (asum(set1) == asum(set2)){
        cout << "YES" << endl;
        printa(set1);
        printa(set2);
    } else {
        cout << "NO";
    }
    return 0;
}