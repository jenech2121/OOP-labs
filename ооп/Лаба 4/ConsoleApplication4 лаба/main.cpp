#include "Stack.cpp"
#include "Exception.cpp"
#include "SmartPointer.cpp"
#include <iostream>
#include <string>
using namespace std;

void displayMenu() {
    setlocale(0, "ru");
    cout << "1. Добавить элемент (push)\n";
    cout << "2. Удалить верхний элемент (pop)\n";
    cout << "3. Посмотреть верхний элемент (top)\n";
    cout << "4. Проверить, пуст ли стек\n";
    cout << "5. Посмотреть размер стека\n";
    cout << "0. Выйти\n";
}

int main() {
    Stack<int> intStack;
    Stack<double> doubleStack;
    Stack<string> stringStack;

    int choice;
    do {
        displayMenu();
        cout << "Введите номер операции: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                int value;
                cout << "Введите значение для добавления: ";
                cin >> value;
                intStack.push(value);
                cout << "Элемент добавлен.\n";
                break;
            }
            case 2:
                intStack.pop();
                cout << "Верхний элемент удалён.\n";
                break;
            case 3:
                cout << "Верхний элемент: " << intStack.top() << "\n";
                break;
            case 4:
                cout << "Стек " << (intStack.empty() ? "пуст.\n" : "не пуст.\n");
                break;
            case 5:
                cout << "Размер стека: " << intStack.size() << "\n";
                break;
            case 0:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Некорректный ввод! Попробуйте снова.\n";
            }
        }
        catch (const StackError& e) {
            cerr << "Ошибка: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
