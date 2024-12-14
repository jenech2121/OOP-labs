#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric> // Для accumulate

using namespace std;

// Функция для решения линейного уравнения ax + b = 0
double solveLinearEquation(double a, double b) {
    if (a == 0) {
        throw invalid_argument("Уравнение не имеет решения или бесконечно много решений.");
    }
    return -b / a;
}

// Главная программа для задания 6 первой части
void solveEquationTask() {
    double a, b;
    cout << "Введите коэффициенты a и b для уравнения ax + b = 0: \n";
    cin >> a >> b;

    try {
        double solution = solveLinearEquation(a, b);
        cout << setfill('%') << setw(10) << fixed << setprecision(4) << solution << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}

// Функция для чтения чисел из файла
vector<int> readNumbersFromFile(const string& inputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        throw runtime_error("Не удалось открыть входной файл.");
    }

    vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

// Функция для записи чисел в файл
void writeNumbersToFile(const string& outputFile, const vector<int>& numbers) {
    ofstream outFile(outputFile);
    if (!outFile) {
        throw runtime_error("Не удалось открыть выходной файл.");
    }

    for (int num : numbers) {
        outFile << num << "\n";
    }
}

// Задание 6 2 часть: вычесть сумму всех чисел из каждого числа
void processFileTask(const string& inputFile, const string& outputFile) {
    vector<int> numbers = readNumbersFromFile(inputFile);

    int totalSum = accumulate(numbers.begin(), numbers.end(), 0);

    vector<int> processedNumbers;
    for (int num : numbers) {
        processedNumbers.push_back(num - totalSum);
    }

    writeNumbersToFile(outputFile, processedNumbers);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Выполнение первой части задания
    cout << "Задание 6 1 часть" << endl;
    solveEquationTask();

    // Выполнение второй части задания
    cout << "\nЗадание 6 2 часть" << endl;
    string inputFile = "input.txt";
    string outputFile = "output.txt";


    try {
        processFileTask(inputFile, outputFile);
        cout << "Обработка завершена. Результаты записаны в файл " << outputFile << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
