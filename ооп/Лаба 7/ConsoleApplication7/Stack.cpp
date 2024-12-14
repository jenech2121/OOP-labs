#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

// Исключение для итераторов
class CustomException : public runtime_error {
public:
    explicit CustomException(const string& message) : runtime_error(message) {}
};

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    // Конструкторы и методы
    Stack() = default;
    Stack(initializer_list<T> list) : data(list) {}
    Stack(const Stack& other) = default;
    Stack& operator=(const Stack& other) = default;
    Stack(Stack&& other) noexcept = default;
    Stack& operator=(Stack&& other) noexcept = default;

    void push(const T& value) { data.push_back(value); }
    void pop() {
        if (data.empty())
            throw CustomException("Стек пуст! Невозможно удалить элемент.");
        data.pop_back();
    }
    T& top() {
        if (data.empty())
            throw CustomException("Стек пуст! Невозможно получить верхний элемент.");
        return data.back();
    }
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }

    // Общий интерфейс для итераторов
    class IteratorInterface {
    public:
        virtual bool hasNext() const = 0;
        virtual T& next() = 0;
        virtual ~IteratorInterface() = default;
    };

    // Итератор для прямого обхода (сверху вниз)
    class ForwardIterator : public IteratorInterface {
    private:
        size_t index;
        Stack<T>& stack;

    public:
        ForwardIterator(Stack<T>& s) : stack(s), index(0) {
            if (stack.empty())
                throw CustomException("Итерация невозможна. Стек пуст.");
        }

        bool hasNext() const override {
            return index < stack.data.size();
        }

        T& next() override {
            if (!hasNext())
                throw CustomException("Достигнут конец стека при прямой итерации.");
            return stack.data[index++];
        }
    };

    // Итератор для обратного обхода (снизу вверх)
    class ReverseIterator : public IteratorInterface {
    private:
        size_t index; // Индекс, идущий от конца к началу
        Stack<T>& stack;

    public:
        ReverseIterator(Stack<T>& s) : stack(s), index(s.data.size()) {
            if (stack.empty())
                throw CustomException("Итерация невозможна. Стек пуст.");
        }

        bool hasNext() const override {
            return index > 0; 
        }

        T& next() override {
            if (!hasNext())
                throw CustomException("Достигнут конец стека при обратной итерации.");
            --index; 
            return stack.data[index];
        }
    };

    // Методы для получения итераторов
    ForwardIterator getForwardIterator() {
        return ForwardIterator(*this);
    }

    ReverseIterator getReverseIterator() {
        return ReverseIterator(*this);
    }
};
