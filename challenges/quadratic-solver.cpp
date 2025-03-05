#include <iostream>
#include <string>
#include <cmath>
#include <utility>

// Function to solve a quadratic equation
std::pair <bool, std::pair<double, double>> solveQuadratic(double a, double b, double c) {
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) { 
        return std::pair<bool, std::pair<double, double>>(false, std::pair<double, double>(0, 0));
    } 
    else {
        double x1 = (-b + sqrt(discriminant)) / (2*a);
        double x2 = (-b - sqrt(discriminant)) / (2*a);
        return std::pair<bool, std::pair<double, double>>(true, std::pair<double, double>(x1, x2));
    }
}

/* Other way to define our solver function
using Zeros = std::pair<double, double>;
using Solution = std::pair<bool, Zeros>;

Solution solveQuadratic(double a, double b, double c)...

// In main function 
Solution roots = solveQuadratic(a, b, c);  // Call function
*/

int main () {
    double a, b, c;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;

    //std::pair<bool, std::pair<double, double>> roots = solveQuadratic(a, b, c);
    auto roots = solveQuadratic(a, b, c);
    std::cout << "{" << (roots.first ? "true" : "false") << ", {" << roots.second.first << ", " << roots.second.second << "}}" << std::endl;

    return 0;
}
