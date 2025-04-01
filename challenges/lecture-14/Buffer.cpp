#include "Buffer.h"
#include <iostream>

Buffer::Buffer(const Buffer& other) 
    : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy constructor called" << std::endl;
    }

Buffer& Buffer::operator=(const Buffer& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[other.size];
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

Buffer::Buffer(Buffer&& other) noexcept
    : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor called" << std::endl;
    }

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move assignment operator called" << std::endl;
    }
    return *this;
}




