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
    // ����������� �� ���������
    Stack() = default;

    // ����������� �� std::initializer_list
    Stack(initializer_list<T> list) : data(list) {}

    // ����������� �����������
    Stack(const Stack& other) = default;

    // �������� ����������� ������������
    Stack& operator=(const Stack& other) = default;

    // ����������� �����������
    Stack(Stack&& other) noexcept = default;

    // �������� ������������� ������������
    Stack& operator=(Stack&& other) noexcept = default;

    // �������� �������
    void push(const T& value) {
        data.push_back(value);
    }

    // ������� ������� �������
    void pop() {
        if (data.empty())
            throw runtime_error("���� ����! ���������� ��������� ��������.");
        data.pop_back();
    }

    // �������� ������� �������
    T& top() {
        if (data.empty())
            throw runtime_error("���� ����! ���������� �������� �������.");
        return data.back();
    }

    // ������ �����
    size_t size() const {
        return data.size();
    }

    // ���������, ���� �� ����
    bool empty() const {
        return data.empty();
    }
};
