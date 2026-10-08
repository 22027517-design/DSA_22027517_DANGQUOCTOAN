#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return -1;
        }
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->data;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAt(int index, int val) {
        if (index < 0 || index > size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        if (index == 0) { insertHead(val); return; }
        if (index == size) { insertTail(val); return; }

        Node* cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;

        Node* newNode = new Node(val);
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next->prev = newNode;
        cur->next = newNode;
        size++;
    }

    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteTail() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        if (index == 0) { deleteHead(); return; }
        if (index == size - 1) { deleteTail(); return; }

        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        size--;
    }

    void traverseForward() {
        Node* cur = head;
        cout << "Duyet xuoi: ";
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void traverseBackward() {
        Node* cur = tail;
        cout << "Duyet nguoc: ";
        while (cur) {
            cout << cur->data << " ";
            cur = cur->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertHead(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertAt(1, 15);

    list.traverseForward();
    list.traverseBackward();

    cout << "Phan tu tai vi tri index 2: " << list.get(2) << endl;

    list.deleteHead();
    list.deleteAt(1);

    list.traverseForward();

    return 0;
}
