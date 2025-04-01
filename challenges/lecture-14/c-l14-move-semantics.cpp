#include <iostream>
#include <utility>
#include <iostream>
#include "Buffer.h"
#include <chrono>

/*
int main() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;        // Copy
    std::vector<int> v3 = std::move(v1); // Move

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    return 0;
}
    */

int main() {
    Buffer buffer1(100000);

    auto start = std::chrono::high_resolution_clock::now();
    Buffer buffer2 = buffer1; // Copy constructor
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> copy_duration = end - start;
    std::cout << "Copy duration: " << copy_duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    Buffer buffer3 = std::move(buffer1); // Move constructor
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> move_duration = end - start;
    std::cout << "Move duration: " << move_duration.count() << " seconds" << std::endl;
}

