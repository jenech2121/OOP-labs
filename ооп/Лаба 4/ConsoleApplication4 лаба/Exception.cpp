#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class StackError : public runtime_error {
public:
    explicit StackError(const string& message) : runtime_error(message) {}
};

class StackEmptyError : public StackError {
public:
    StackEmptyError() : StackError("Стек пуст. Операция невозможна.") {}
};
