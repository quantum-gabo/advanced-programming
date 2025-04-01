#include<iostream>
#include<utility>
#include<algorithm>
#include<concepts>



template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}
// overload the maxValue function
template <typename T>
T maxValue(T a, T b, T c) {
    return maxValue(maxValue(a, b), c);
}

template <typename A>
concept Numeric = std::integral<A> || std::floating_point<A>;

template <Numeric A>
A add(A a, A b) {
    return a + b;
}

/*1. Write a variadic template function called printAll that 
accepts any number of parameters and prints them separated by 
spaces. 

2. Test it with different types of arguments.*/

template <typename T>
void printAll(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void printAll(T t, Args... args) {
    std::cout << t << " ";
    printAll(args...);
}

/*
1.	Write a variadic template function called sum that returns the sum of all arguments.
2.	Test it with integers and floating-point values.
*/

template <typename T> 
T sum (T t) {
    return t;
}
template <typename T, typename... Args>
T sum (T t, Args... args) {
    return t + sum(args...);
}

/*
1.	Write a recursive template that calculates the factorial of a number at compile time using template metaprogramming.
2.	Test it with a constexpr value.
*/
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

/*
1.	Write a recursive template that calculates the nth Fibonacci number at compile time.
2.	Test it with constexpr values.
*/

template <int N> 
struct Fibonacci {
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "---------------------- Part 1: Basic Template Functions ----------------------" << std::endl;
    std::cout << maxValue(5, 10) << std::endl;
    std::cout << maxValue(5.5, 2.3) << std::endl;
    std::cout << maxValue<std::string>(std::string("Hello"), std::string("World")) << std::endl;
    std::cout << "Overload maxValue" << std::endl;
    std::cout << maxValue(5, 10, 15) << std::endl;
    std::cout << maxValue(5.5, 2.3, 8.1) << std::endl;

    std::cout << "---------------------- Part 2: Concepts ----------------------" << std::endl;
    std::cout << add(3, 4) << std::endl;
    std::cout << add(2.5, 3.1) << std::endl;

    std::cout << "---------------------- Part 3: Variadic Templates ----------------------" << std::endl;
    printAll(1, 2.5, "Hello", 'A');
    std::cout << "Variadic template summation" << std::endl;
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
    std::cout << sum(1.1, 2.2, 3.3) << std::endl;

    std::cout << "---------------------- Part 4: Template Metaprogramming ----------------------" << std::endl;
    constexpr int result = Factorial<5>::value;
    std::cout << "Factorial of 5 is: " << result << std::endl;

    std::cout << "---------------------- Fibonacci ----------------------" << std::endl;
    constexpr int fibResult = Fibonacci<10>::value;
    std::cout << "The 10th Fibonacci number is: " << fibResult << std::endl;
    
    std::cout << "---------------------- End of Program ----------------------" << std::endl;

}
