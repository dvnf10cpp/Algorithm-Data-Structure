#include <bits/stdc++.h>

using namespace std;

/**
 * Circular Linked List is a Linked List where the tail node next reference or pointer is the head node
*/

class CircularLinkedList {
private: 
    struct Node {
        Node* next;
        int data;

        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
    };
    void init(Node* node) {
        head = tail = node;
        head->next = tail;
        tail->next = head;
    }
public:
    Node* head;
    Node* tail;

    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void prepend(int data) {
        // add to head
        // takes O(1) time complexity
        Node* node = new Node(data);
        if(head == nullptr) {
            init(node);
            return;
        }
        node->next = head;
        head = node;
        tail->next = head;
    }

    void append(int data) {
        // add to tail
        // takes O(1) time complexity
        Node* node = new Node(data);
        if(head == nullptr) {
            init(node);
            return;
        }
        node->next = head;
        tail->next = node;
        tail = node;
    }
};

int main () {
    return 0;
}