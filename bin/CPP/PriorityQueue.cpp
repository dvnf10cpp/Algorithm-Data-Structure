#include <bits/stdc++.h>

using namespace std;

/**
 * Priority Queue is a type of queue that aranges elements based on their priority values.
 * Element with higher priority values are typically retrieved before elements with lower values
 * In this one, we are implementing descending type of priority queue
*/
class PriorityQueue {
private:
    struct Node {
        Node* next;
        int data;

        Node(int data) : data(data), next(nullptr) {}
    };
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}

    void push(int data) {
        // Takes O(n) time, where n is the size of the data structure
        Node* node = new Node(data);
        if(empty()) {
            head = node;
            return;
        }
        if(head->data <= data) {
            node->next = head;
            head = node;
            return;
        }
        Node* curr = head;
        while(curr->next != nullptr) {
            if(curr->next->data <= data) {
                node->next = curr->next;
                curr->next = node;
                return;
            }
            curr = curr->next;
        }
        curr->next = node;
    }

    void pop() {
        // Takes O(1) time
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    int peek() {
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    PriorityQueue* pq = new PriorityQueue();

    pq->push(3);
    pq->push(5);
    pq->push(1);
    pq->push(7);
    pq->push(9);
    pq->push(8);
    pq->push(4);
    pq->push(3);
    pq->push(7);
    pq->push(6);
    pq->push(1);
    pq->push(2);
    pq->push(9);

    while(!pq->empty()) {
        cout << pq->peek() << " ";
        pq->pop();
    }
    cout << endl;
    return 0;
}