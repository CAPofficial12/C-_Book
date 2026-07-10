#include <iostream>
#include <vector>
#include <chrono>
#include <string>
using namespace  std;
using ll = long long int;

auto stat = std::chrono::steady_clock::now();
auto finish = std::chrono::steady_clock::now();
void start(){
    stat = std::chrono::steady_clock::now();
}

void time(){
    finish = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - stat;
    std::cout << "Execution time: " << elapsed.count() << " ms\n";
    cout << endl;
}

void Countdown_Overflow(ll n){ 
    cout << n << endl;
    Countdown_Overflow(n-1);    //The Function never stops calling itself so it fills up the call stack
}

void Countdown(ll n){
    cout << n << endl;

    if(n > 0){
        Countdown(n-1);
    }
    cout << "Pop" << n << endl;
}

ll sum(ll sumto){
    if (sumto == 0){
        return 0;
    }

    if (sumto == 1){
        return 1;
    }
    return sum(sumto-1) + sumto;
}

ll fib(ll n){
    if (n == 0){
        return 0;
    }

    if (n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

ll eff_fib(ll n){
    vector<ll> val = {0,1};
    ll total = 0;
    for (ll i = 0; i < n-1; i++){
        total = val[0] + val[1];
        val[0] = val[1];
        val[1] = total;
    }
    if (n == 0){
        return 0;
    } else{
        return val[1];
    }
}

ll prob_factorial(ll n){
    if (n == 1){
        return 1;
    }
    return prob_factorial(n-1)*n;
}

ll prob_char_sum(string n, ll index){

    if(index == 0){
        return n[0] - '0';
    }

    return prob_char_sum(n, index-1) + (n[index]-'0');
}

void prob_int_to_bin(ll num){
    if (num == 0){
        return;
    }
    prob_int_to_bin(num/2);

    cout << num%2;
}
int main(){
    ll n;
    cin >> n;
    
    start();
    prob_int_to_bin(static_cast<unsigned int>(n));
    cout << endl;
    time();
    return 0;
}