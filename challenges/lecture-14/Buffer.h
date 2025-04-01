#pragma once
#include <cstddef>
#include <iostream>

class Buffer {
    private:
        int* data;
        size_t size;

    public:
    Buffer(size_t s) : size(s), data(new int[s]) {
        std::cout << "Constructor called" << std::endl;
    }

    ~Buffer() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }

    Buffer(const Buffer& other);

    Buffer& operator=(const Buffer& other);


    Buffer(Buffer&& other) noexcept;

    Buffer& operator=(Buffer&& other) noexcept;  
};

