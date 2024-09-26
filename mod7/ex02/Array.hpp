#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T *_array;
        unsigned int _size;
    public:
        Array() : _array(nullptr), _size(0) {}
        Array(unsigned int n) : _array(new T[n]()), _size(n) {}
        ~Array() { delete[] _array; }
        Array(Array const &src) : _array(new T[src._size]), _size(src._size) {
            for (unsigned int i = 0; i < src._size; i++)
                _array[i] = src._array[i];
        }
        Array &operator=(Array const &rhs) {
            if (this != &rhs) {
                delete[] _array;
                _array = new T[rhs._size];
                for (unsigned int i = 0; i < rhs._size; i++)
                    _array[i] = rhs._array[i];
                _size = rhs._size;
            }
            return *this;
        }
        T &operator[](unsigned int i) {
            if (i >= _size)
                throw std::out_of_range("Index out of range");
            return _array[i];
        }
        const T &operator[](unsigned int i) const {
            if (i >= _size)
                throw std::out_of_range("Index out of range");
            return _array[i];
        }
        unsigned int size() const { return _size; }
};

#endif