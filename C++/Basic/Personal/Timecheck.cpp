#include <iostream>
#include <chrono>

int main(){

    // Takes up time
    int a = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while (a < 10000000){
        a++;
    }

    /*  The above code is a simple loop that increments the variable 'a' until it reaches 10 million. 
        This is done to create a time-consuming task, allowing us to measure the time taken for this operation.
        The 'auto' keyword is used to automatically deduce the type of 'start' and 'end' variables, which are of type 'std::chrono::time_point'.
        The 'std::chrono::high_resolution_clock' is used to get the current time before and after the loop, and the difference is calculated in milliseconds.
        Finally, the elapsed time is printed to the console.
    */
   auto end = std::chrono::high_resolution_clock::now();

   auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
   std::cout << "Time elapsed: " << diff.count() << " ms" << std::endl;

   return 0;
}
