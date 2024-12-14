#include "Stack.cpp"
#include <iostream>
#include <string>
using namespace std;

void displayMenu() {
    setlocale(0, "ru");
    cout << "1. �������� ������� (push)\n";
    cout << "2. ������� ������� ������� (pop)\n";
    cout << "3. ���������� ������� ������� (top)\n";
    cout << "4. ������ ����� ����� (������ ����)\n";
    cout << "5. �������� ����� ����� (����� �����)\n";
    cout << "6. ���������, ���� �� ����\n";
    cout << "7. ���������� ������ �����\n";
    cout << "0. �����\n";
}

int main() {
    Stack<int> stack;
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
                stack.push(value);
                cout << "������� ��������.\n";
                break;
            }
            case 2:
                stack.pop();
                cout << "������� ������� �����.\n";
                break;
            case 3:
                cout << "������� �������: " << stack.top() << "\n";
                break;
            case 4: {
                cout << "������ ����� ����� (������ ����): ";
                auto it = stack.getForwardIterator();
                while (it.hasNext()) {
                    cout << it.next() << " ";
                }
                cout << "\n";
                break;
            }
            case 5: {
                cout << "�������� ����� ����� (����� �����): ";
                auto it = stack.getReverseIterator();
                while (it.hasNext()) {
                    cout << it.next() << " ";
                }
                cout << "\n";
                break;
            }
            case 6:
                cout << "���� " << (stack.empty() ? "����.\n" : "�� ����.\n");
                break;
            case 7:
                cout << "������ �����: " << stack.size() << "\n";
                break;
            case 0:
                cout << "����� �� ���������...\n";
                break;
            default:
                cout << "������������ ����! ���������� �����.\n";
            }
        }
        catch (const CustomException& e) {
            cerr << "������: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
