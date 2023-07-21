#include <bits/stdc++.h>

using namespace std;

class Queue {
private:
    struct Node {
        Node* next;
        int data;

        Node(int data) : data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push(int data) {
        Node* node = new Node(data);
        if(empty()) {
            head = tail = node;
            return;
        }
        tail-> next = node;
        tail = node;
    }

    void pop() {
        if(empty())  return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    int peek() {
        if(empty()) return INT_MIN;
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    Queue* q = new Queue();

    q->push(5);
    q->push(4);
    q->push(3);

    while(!q->empty()) {
        cout << q->peek() << " ";
        q->pop();
    }
    cout << endl;
    return 0;
}