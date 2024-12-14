#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <mutex>

using namespace std;

class LogStream {
private:
    static ofstream log_file;
    static string log_filename;
    static mutex log_mutex;
    static unique_ptr<LogStream> instance;

    // Приватный конструктор для обеспечения паттерна "Одиночка"
    LogStream() {}

public:
    // Удаляем копирование и присваивание
    LogStream(const LogStream&) = delete;
    LogStream& operator=(const LogStream&) = delete;

    static LogStream& getInstance() {
        lock_guard<mutex> lock(log_mutex);
        if (!instance) {
            instance.reset(new LogStream());
        }
        return *instance;
    }

    static void setLogFile(const string& filename) {
        lock_guard<mutex> lock(log_mutex);
        if (log_file.is_open()) {
            log_file.close();
        }
        log_filename = filename;
        log_file.open(log_filename, ios::out | ios::app);
        if (!log_file) {
            throw runtime_error("Невозможно открыть файл для записи логов");
        }
    }

    template <typename T>
    LogStream& operator<<(const T& message) {
        lock_guard<mutex> lock(log_mutex);
        if (!log_file.is_open()) {
            throw runtime_error("Файл для логов не установлен");
        }
        log_file << message;
        return *this;
    }

    LogStream& operator<<(ostream& (*manip)(ostream&)) {
        lock_guard<mutex> lock(log_mutex);
        if (!log_file.is_open()) {
            throw runtime_error("Файл для логов не установлен");
        }
        log_file << manip;
        return *this;
    }

    ~LogStream() {
        lock_guard<mutex> lock(log_mutex);
        if (log_file.is_open()) {
            log_file.flush();
        }
    }
};

// Инициализация статических членов
ofstream LogStream::log_file;
string LogStream::log_filename;
mutex LogStream::log_mutex;
unique_ptr<LogStream> LogStream::instance = nullptr;

// Пример использования
int main() {
    setlocale(LC_ALL, "Russian");

    try {
        LogStream::setLogFile("application.log");
        LogStream& log = LogStream::getInstance();

        log << "Приложение запущено" << endl;

        int a = 5;
        log << "Значение a: " << a << endl;

        log << "Приложение завершено" << endl;

        cout << "Логи записаны в файл application.log" << endl;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
