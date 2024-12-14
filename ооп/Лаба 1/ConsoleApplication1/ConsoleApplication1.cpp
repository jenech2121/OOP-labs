#include <iostream> 
#include <stdexcept> 

using namespace std;

template <typename T>
class PQueue {
private:
    struct Node {
        T value;         
        int priority;     
        Node* next;       

         
        Node(const T& val, int pri) : value(val), priority(pri), next(nullptr) {}
    };

    Node* head;  
public:
    
    PQueue() : head(nullptr) {}

    
    ~PQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Метод добавления элемента с заданным приоритетом 
    void add(const T& value, int priority) {
        Node* newNode = new Node(value, priority);

            if (head == nullptr || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Метод удаления элемента с наивысшим приоритетом 
    T remove() {
        if (isEmpty()) {
            throw out_of_range("Очередь пуста");
        }

        Node* temp = head;
        T highestPriorityValue = head->value;
        head = head->next;
        delete temp; 
        return highestPriorityValue;
    }

    // Метод проверки, пуста ли очередь 
    bool isEmpty() const {
        return head == nullptr;
    }

    // Метод получения элемента с наивысшим приоритетом без удаления 
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Очередь пуста");
        }
        return head->value;
    }
};

int main() {
    PQueue<string> pq;

    pq.add("Kalinin M.A", 1);
    pq.add("Zhalov A.P.", 3);
    pq.add("Pekar' A.S.", 2);

    while (!pq.isEmpty()) {
        cout << "Highest priority task: " << pq.remove() << endl;
    }

    return 0;
}