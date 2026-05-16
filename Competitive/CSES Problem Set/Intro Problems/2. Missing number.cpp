#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
using lln = long long int;

lln search(lln n, vector<lln> list){
    vector<lln> lista;
    lista.resize(n);
    for (lln i = 1; i < n+1; i++){
        lista[i-1] = i;
    }

    for(lln i: list){
        lista[i-1] = 0;
    }

    for(lln i:lista){
        if (i != 0){
            return i;
        }
    }
}

vector<lln> conversion(string input){
    vector<lln> numbers;

    stringstream ss(input);
    int value;
    // Extract integers one by one until the stream is exhausted
    while (ss >> value) {
        numbers.push_back(value);
    }

    // Print the vector to verify

    return numbers;

}

int main(){
    string n;
    string tt;
    getline(cin, n);
    getline(cin, tt);
    vector<lln> c = conversion(tt);
    long long a = stoll(n);
    int value = search(a, c);
    cout << value;
    return 0;
}