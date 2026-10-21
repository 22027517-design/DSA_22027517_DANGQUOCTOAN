#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue rong! Khong the dequeue." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getSize() {
        return size;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

class QueueList {
private:
    vector<int> list;

public:
    QueueList() {}

    void enqueue(int val) {
        list.push_back(val);
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue rong! Khong the dequeue." << endl;
            return;
        }
        list.erase(list.begin());
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        return list.front();
    }

    bool isEmpty() {
        return list.empty();
    }

    int getSize() {
        return list.size();
    }
};

int main() {
    cout << "=== DEMO QUEUE BANG LINKED LIST ===" << endl;
    QueueLinkedList queueLL;
    queueLL.enqueue(10);
    queueLL.enqueue(20);
    queueLL.enqueue(30);

    cout << "Phan tu o dau Queue: " << queueLL.front() << endl;
    queueLL.dequeue();
    cout << "Phan tu o dau sau khi dequeue: " << queueLL.front() << endl;

    cout << "\n=== DEMO QUEUE BANG LIST (VECTOR) ===" << endl;
    QueueList queueList;
    queueList.enqueue(100);
    queueList.enqueue(200);

    cout << "Phan tu o dau Queue: " << queueList.front() << endl;
    queueList.dequeue();
    cout << "Phan tu o dau sau khi dequeue: " << queueList.front() << endl;

    return 0;
}