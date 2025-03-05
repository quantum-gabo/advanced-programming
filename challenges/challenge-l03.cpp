// Classwork: Assignment 0: Reference and Initialisation and Categorisation

#include <iostream>
#include <string>
#include <vector>
#include <utility>

/*- An `int` with an initial value.
- A `double` with an initial value.
- A `std::string` with an initial value.
- A `bool` with an initial value.
Use different types of initialization 
(i.e., direct initialization, uniform initialization, 
structured binding)Print all the initialized values.
*/
// Initialisation 
int a = 10; // Direct initialization
double b {3.14}; // Uniform initialization
std::pair<std::string, bool> pair1 {"Hola", true}; // Structured binding

// Create the struct Point
struct Point {
    int x;
    int y;
    int z;
};

// Analyse the following variables and their value type (lvalue or rvalue)
// a_val = 42; -> lvalue
// int x = a + b; -> a and b are lvalues, a + b is rvalue
// &a; -> lvalue 
// std::string s = c + "World"; -> c is lvalue, c + "World" is rvalue
// int& refx = x; -> lvalue
// int&& rref = 100; -> rvalue


int main() {

    auto [saludo, booleano] = pair1;
    // Print the initialized values
    std::cout << "Direct initialization: " << std::endl;
    std::cout << "int: " << a << std::endl;
    std::cout << "Uniform initialization: " << std::endl;
    std::cout << "double: " << b << std::endl;
    std::cout << "Structured binding: " << std::endl;
    std::cout << "std::string: " << saludo << std::endl;
    std::cout << "bool: " << booleano << std::endl;


    /*
    Declare a reference to a and use it to modify the value of the previously created variables.
    */
    // Print the values before modifying them
    std::cout << "Before modifying: " << std::endl;
    std::cout << "int: " << a << ", double: " << b << ", std::string: " << saludo << ", bool: " << booleano << std::endl;

    // Declare a reference to those variables
    int& ref_a = a;
    double& ref_b = b;
    std::string& ref_saludo = saludo;
    bool& ref_booleano = booleano;

    // Modify the values using the references
    ref_a = 20;
    ref_b = 6.28;
    ref_saludo = "Hello";
    ref_booleano = false;

    // Print the values after modifying them
    std::cout << "After modifying: " << std::endl;
    std::cout << "int: " << a << ", double: " << b << ", std::string: " << saludo << ", bool: " << booleano << std::endl;

    // Define a struct Point containing three members (e.g., x, y, z).
    // defined above

    // Create an instance of the struct Point
    Point point{1, 2, 3};

    // Unpack the members into separate variables
    auto [x, y, z] = point;

    // Print the unpacked values
    std::cout << "Unpacked Point values: " << std::endl;
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    
    return 0;
}








    