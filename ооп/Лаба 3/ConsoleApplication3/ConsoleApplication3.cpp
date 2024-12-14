#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class UPtrArr {
private:
    T* ptr;
    size_t size;

public:
    UPtrArr() : ptr(nullptr), size(0) {}

    explicit UPtrArr(size_t size) : ptr(size > 0 ? new T[size] : nullptr), size(size) {}

    ~UPtrArr() {
        delete[] ptr;
    }

    // Конструктор перемещения
    UPtrArr(UPtrArr&& other) noexcept : ptr(other.ptr), size(other.size) {
        other.ptr = nullptr;
        other.size = 0;
    }

    // Оператор присваивания перемещением
    UPtrArr& operator=(UPtrArr&& other) noexcept {
        if (this != &other) {
            delete[] ptr;
            ptr = other.ptr;
            size = other.size;
            other.ptr = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // Удаляем копирование
    UPtrArr(const UPtrArr&) = delete;
    UPtrArr& operator=(const UPtrArr&) = delete;

    // Оператор индексирования с проверкой на выход за границы
    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return ptr[index];
    }

    // Метод для получения "сырого" указателя
    T& get() const {
        return ptr;
    }

    // Метод для обнуления указателя
    void reset(T& newPtr = nullptr, size_t newSize = 0) {
        delete[] ptr;
        ptr = newPtr;
        size = newSize;
    }

    // Метод для обмена указателями
    void swap(UPtrArr& other) {
        T* temp = ptr;
        size_t tempSize = size;
        ptr = other.ptr;
        size = other.size;
        other.ptr = temp;
        other.size = tempSize;
    }

    // Проверка на пустоту
    bool isNull() const {
        return ptr == nullptr;
    }

    // Получить размер массива
    size_t getSize() const {
        return size;
    }

    // Метод для изменения размера массива
    void resize(size_t newSize) {
        T* newPtr = newSize > 0 ? new T[newSize] : nullptr;
        size_t minSize = std::min(size, newSize);
        for (size_t i = 0; i < minSize; ++i) {
            newPtr[i] = std::move(ptr[i]);
        }
        delete[] ptr;
        ptr = newPtr;
        size = newSize;
    }
};

template <typename T>
void manageArray() {
    size_t initialSize;
    cout << "Введите начальный размер массива: ";
    cin >> initialSize;

    UPtrArr<T> arr(initialSize);

    cout << "Введите " << initialSize << " элементов массива:" << endl;
    for (size_t i = 0; i < initialSize; ++i) {
        cin >> arr[i];
    }

    cout << "Элементы массива:" << endl;
    for (size_t i = 0; i < initialSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    size_t newSize;
    cout << "Введите новый размер массива: ";
    cin >> newSize;

    arr.resize(newSize);
    if (newSize > initialSize) {
        cout << "Введите " << (newSize - initialSize) << " дополнительных элементов массива:" << endl;
        for (size_t i = initialSize; i < newSize; ++i) {
            cin >> arr[i];
        }
    }

    cout << "Массив после изменения размера:" << endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Выберите тип данных для массива (1 - int, 2 - string, 3 - double): ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        manageArray<int>();
        break;
    case 2:
        manageArray<string>();
        break;
    case 3:
        manageArray<double>();
            break;
    }
    return 0;
}
