#include<iostream>
#include <vector>
using namespace std;

//Renaming types using type def
typedef long long ll; 
typedef vector<int> vi;
typedef pair<int, int> pii;

//Macros (rename functions or rename strings)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define C cout <<
int main(){
    long long a = 123456789; //Typedef translates this code into 
    long long b = 987654321;
    C a*b << "\n";

    ll c = 123456789; //This code
    ll d = 987654321;
    C a*b << "\n";

    REP(i,0,5){
        C 1;
    }

    return 0;
}