#include <bits/stdc++.h>

using namespace std;

/**
 * Queue as ADT
 * Queue is a structure that whatever come in first come out first, or aka first in first out (FIFO)
 * Insertion must happen on one end that we call tail
 * Deletion must happen on other end that we call head
 * Operations : 
 *  1. Enqueue or Push, insert item at tail
 *  2. Dequeue or Pop, remove item from head
 *  3. Front or Peek, read item from head
 * All those operations must take constant time, O(1)
*/

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

    void enqueue(int data) {
        Node* node = new Node(data);
        if(empty()) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    int dequeue() {
        if(empty())  return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    int front() {
        if(empty()) return INT_MIN;
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    Queue* q = new Queue();

    q->enqueue(5);
    q->enqueue(4);
    q->enqueue(3);

    while(!q->empty()) {
        cout << q->front() << " ";
        q->dequeue();
    }
    cout << endl;
    return 0;
}