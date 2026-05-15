#include <iostream>
#include <string>
using namespace std;

void printReverse(const char *str) {
  if (!*str)
    return;
  printReverse(str + 1);
  putchar(*str);
}

int main(){
    string test = "test";
    const char *str = "Tatse";
    printReverse(str);
    return 0;
}