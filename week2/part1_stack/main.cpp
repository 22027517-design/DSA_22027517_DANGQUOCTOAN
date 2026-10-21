#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* topNode;
    int size;

public:
    StackLinkedList() : topNode(nullptr), size(0) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong! Khong the pop." << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int getSize() {
        return size;
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class StackList {
private:
    vector<int> list;

public:
    StackList() {}

    void push(int val) {
        list.push_back(val);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong! Khong the pop." << endl;
            return;
        }
        list.pop_back();
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return list.back();
    }

    bool isEmpty() {
        return list.empty();
    }

    int getSize() {
        return list.size();
    }
};

int main() {
    cout << "=== DEMO STACK BANG LINKED LIST ===" << endl;
    StackLinkedList stackLL;
    stackLL.push(10);
    stackLL.push(20);
    stackLL.push(30);

    cout << "Phan tu o dinh Stack: " << stackLL.top() << endl;
    stackLL.pop();
    cout << "Phan tu o dinh sau khi pop: " << stackLL.top() << endl;

    cout << "\n=== DEMO STACK BANG LIST (VECTOR) ===" << endl;
    StackList stackList;
    stackList.push(100);
    stackList.push(200);

    cout << "Phan tu o dinh Stack: " << stackList.top() << endl;
    stackList.pop();
    cout << "Phan tu o dinh sau khi pop: " << stackList.top() << endl;

    return 0;
}