#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Пользовательское исключение
class CustomException : public exception {
private:
    string message;

public:
    CustomException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Функция для вычисления Z1
double calculateZ1(double m) {
    if (m * m - 4 < 0) {
        throw CustomException("Ошибка: Отрицательное значение под корнем в Z1.");
    }
    if (m + sqrt(m * m - 4) + 2 == 0) {
        throw CustomException("Ошибка: Деление на ноль в Z1.");
    }

    double numerator = sqrt(2 * m + 2 * sqrt(m * m - 4));
    double denominator = m + sqrt(m * m - 4) + 2;
    return numerator / denominator;
}

// Функция для вычисления Z2
double calculateZ2(double m) {
    if (m + 2 < 0) {
        throw CustomException("Ошибка: Отрицательное значение под корнем в Z2.");
    }

    return 1 / sqrt(m + 2);
}

int main() {
    setlocale(0, "ru");
    try {
        double m;
        cout << "Введите значение m: ";
        cin >> m;

        double z1 = calculateZ1(m);
        double z2 = calculateZ2(m);

        cout << "Z1 = " << z1 << ", Z2 = " << z2 << endl;

        if (fabs(z1 - z2) < 1e-9) {
            cout << "Значения Z1 и Z2 приблизительно равны." << endl;
        }
        else {
            cout << "Значения Z1 и Z2 различны." << endl;
        }

    }
    catch (const CustomException& e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Неизвестная ошибка." << endl;
    }

    return 0;
}
