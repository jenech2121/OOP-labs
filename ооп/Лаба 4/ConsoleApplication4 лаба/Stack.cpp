#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    // Конструктор по умолчанию
    Stack() = default;

    // Конструктор от std::initializer_list
    Stack(initializer_list<T> list) : data(list) {}

    // Конструктор копирования
    Stack(const Stack& other) = default;

    // Оператор копирующего присваивания
    Stack& operator=(const Stack& other) = default;

    // Конструктор перемещения
    Stack(Stack&& other) noexcept = default;

    // Оператор перемещающего присваивания
    Stack& operator=(Stack&& other) noexcept = default;

    // Добавить элемент
    void push(const T& value) {
        data.push_back(value);
    }

    // Удалить верхний элемент
    void pop() {
        if (data.empty())
            throw runtime_error("Стек пуст! Невозможно выполнить операцию.");
        data.pop_back();
    }

    // Получить верхний элемент
    T& top() {
        if (data.empty())
            throw runtime_error("Стек пуст! Невозможно получить элемент.");
        return data.back();
    }

    // Размер стека
    size_t size() const {
        return data.size();
    }

    // Проверить, пуст ли стек
    bool empty() const {
        return data.empty();
    }
};
