#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    // Запрет копирования
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    // Перемещение
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};
