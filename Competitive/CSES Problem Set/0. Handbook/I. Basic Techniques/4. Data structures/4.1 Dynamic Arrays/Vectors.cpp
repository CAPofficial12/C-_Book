#include <iostream>
#include <vector>   //Verctors are a type of dynamic array which can only store 1 data type
#include <string>   //Strings work similar to vectors but have special commands
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;  //Initalisation alway automates to a new empty array
    v.push_back(3); // Pushback works by making a new array and moving all elements into the new array with 3 added at the end
    v.push_back(2);
    v.push_back(5);

    //Iterates via index
    for (int i = 0; i < v.size(); i++){
        cout << i << " " << v[i] << "\n";
    }

    //Iterates Via element
    for (auto i: v){
        cout << i << " ";
    }

    cout << "\n";

    //Returns last element
    cout << v.back() << " ";

    //Remove last element
    v.pop_back();
    cout << v.back() << " \n";

    //cout << v[-1] << " " << v[-2];  Negative indices do not work

    //Initialises v2 with 10 spaces each with element 5
    vector<int> v2(10,5);
    for(auto x: v2){
        cout << x << " ";
    }
    cout << "\n";
    
    //STRINGS

    string a = "hatti";
    string b = a+a;
    cout << b << " ";
    b[5] = 'v';
    cout << b << " ";
    string c = b.substr(3,4);
    cout << c << " ";
    return 0; 
}