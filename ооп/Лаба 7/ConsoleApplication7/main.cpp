#include "Stack.cpp"
#include <iostream>
#include <string>
using namespace std;

void displayMenu() {
    setlocale(0, "ru");
    cout << "1. Добавить элемент (push)\n";
    cout << "2. Удалить верхний элемент (pop)\n";
    cout << "3. Посмотреть верхний элемент (top)\n";
    cout << "4. Прямой обход стека (сверху вниз)\n";
    cout << "5. Обратный обход стека (снизу вверх)\n";
    cout << "6. Проверить, пуст ли стек\n";
    cout << "7. Посмотреть размер стека\n";
    cout << "0. Выйти\n";
}

int main() {
    Stack<int> stack;
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
                stack.push(value);
                cout << "Элемент добавлен.\n";
                break;
            }
            case 2:
                stack.pop();
                cout << "Верхний элемент удалён.\n";
                break;
            case 3:
                cout << "Верхний элемент: " << stack.top() << "\n";
                break;
            case 4: {
                cout << "Прямой обход стека (сверху вниз): ";
                auto it = stack.getForwardIterator();
                while (it.hasNext()) {
                    cout << it.next() << " ";
                }
                cout << "\n";
                break;
            }
            case 5: {
                cout << "Обратный обход стека (снизу вверх): ";
                auto it = stack.getReverseIterator();
                while (it.hasNext()) {
                    cout << it.next() << " ";
                }
                cout << "\n";
                break;
            }
            case 6:
                cout << "Стек " << (stack.empty() ? "пуст.\n" : "не пуст.\n");
                break;
            case 7:
                cout << "Размер стека: " << stack.size() << "\n";
                break;
            case 0:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Некорректный ввод! Попробуйте снова.\n";
            }
        }
        catch (const CustomException& e) {
            cerr << "Ошибка: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
