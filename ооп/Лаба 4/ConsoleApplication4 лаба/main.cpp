#include "Stack.cpp"
#include "Exception.cpp"
#include "SmartPointer.cpp"
#include <iostream>
#include <string>
using namespace std;

void displayMenu() {
    setlocale(0, "ru");
    cout << "1. �������� ������� (push)\n";
    cout << "2. ������� ������� ������� (pop)\n";
    cout << "3. ���������� ������� ������� (top)\n";
    cout << "4. ���������, ���� �� ����\n";
    cout << "5. ���������� ������ �����\n";
    cout << "0. �����\n";
}

int main() {
    Stack<int> intStack;
    Stack<double> doubleStack;
    Stack<string> stringStack;

    int choice;
    do {
        displayMenu();
        cout << "������� ����� ��������: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                int value;
                cout << "������� �������� ��� ����������: ";
                cin >> value;
                intStack.push(value);
                cout << "������� ��������.\n";
                break;
            }
            case 2:
                intStack.pop();
                cout << "������� ������� �����.\n";
                break;
            case 3:
                cout << "������� �������: " << intStack.top() << "\n";
                break;
            case 4:
                cout << "���� " << (intStack.empty() ? "����.\n" : "�� ����.\n");
                break;
            case 5:
                cout << "������ �����: " << intStack.size() << "\n";
                break;
            case 0:
                cout << "����� �� ���������...\n";
                break;
            default:
                cout << "������������ ����! ���������� �����.\n";
            }
        }
        catch (const StackError& e) {
            cerr << "������: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
