#include<iostream>

int main()
{

    int a =5;

    std::cout << a;
    std::cout << "Hello World" << std::endl;
    std::cout << "The endl moves the print function to the next line" << std::endl;

    int value {100}; // {x} can be used to assgn a value to a variable, it is called uniform initialization and it prevents narrowing conversions
    std::cout << value << std::endl;

    int value2 (110.6); // This will cause a warning because of narrowing conversion, it will truncate the decimal part and assign 110 to value2
    std::cout << value2 << std::endl;

    int finalv {};
    std::cout << finalv << std::endl;

    std::cin.get(); // This is used to wait for the user to press enter before closing the console window, it is useful when running the program in an environment where the console window closes immediately after the program finishes executing.
    return 0;
}