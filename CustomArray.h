#ifndef CUSTOM_ARRAY_H
#define CUSTOM_ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class CustomArray {
private:
    T* data;
    int size;

public:
    // 1. Default constructor
    CustomArray() : data(nullptr), size(0) {}

    // 2. Constructor with size
    CustomArray(int s) : size(s) {
        if (size < 0) throw std::invalid_argument("Size cannot be negative");
        data = new T[size]();
    }

    // 3. Copy constructor (Deep copy)
    CustomArray(const CustomArray& other) : size(other.size) {
        data = new T[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }

    // 4. Destructor
    ~CustomArray() {
        delete[] data;
    }

    // 5. Overloaded Assignment Operator (=)
    CustomArray& operator=(const CustomArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    // 6. Overloaded Subscript Operator ([ ])
    T& operator[](int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    // 7. Friend function for Output stream (<<)
    friend std::ostream& operator<<(std::ostream& os, const CustomArray<T>& arr) {
        os << "[ ";
        for (int i = 0; i < arr.size; ++i) {
            os << arr.data[i] << (i == arr.size - 1 ? "" : ", ");
        }
        os << " ]";
        return os;
    }

    // 8. Friend function for Input stream (>>)
    friend std::istream& operator>>(std::istream& is, CustomArray<T>& arr) {
        for (int i = 0; i < arr.size; ++i) {
            std::cout << "Element " << i << ": ";
            is >> arr.data[i];
        }
        return is;
    }

    int getSize() const { return size; }
};

#endif