#include <iostream>
#include <vector>
using namespace std;

//Counting Sort Implemenation
int main(){
    //Counting Array Uses another set of data to help sort the original array

    vector<int> original = {1,3,6,9,9,3,5,9};
    vector<int> bookkeeping = {1,0,2,0,1,1,0,0,3};  //Each index corresponds to the value and The value corresponds to the number of occurences
    
    return 0;
}