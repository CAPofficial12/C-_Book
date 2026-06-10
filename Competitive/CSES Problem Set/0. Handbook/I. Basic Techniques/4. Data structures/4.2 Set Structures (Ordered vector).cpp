#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << "\n"; //All sets are ordered

    s.erase(3);
    s.insert(4);
    cout << s.count(4) << "\n";

    cout << s.size() << "\n";

    for (auto x : s) {
        s.insert(5); //Multiple inserts will not change anything so count only return if numbrt is present or not
        cout << x << " ";
    }
    cout << "\n";

    multiset<int> Sm;
    Sm.insert(5);
    Sm.insert(5);
    Sm.insert(5);
    cout << Sm.count(5) << " "; //Multi set permits multiple instances

    Sm.erase(Sm.find(5));   //Removes only a single instance
    cout << Sm.count(5) << " ";

    Sm.erase(5);
    cout << s.count(5) << " "; //Erase removes all instance of variable
}