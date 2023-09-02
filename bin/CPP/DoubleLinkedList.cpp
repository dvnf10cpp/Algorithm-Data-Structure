#include <bits/stdc++.h>

/*
 * Unlike Single Linked List, In Doubly Linked List,
 * each node has reference to the next node and previous node
*/
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : 
    data(data), 
    next(nullptr), 
    prev(nullptr) 
    {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : 
    head(nullptr) {}

    void prepend(int data) {
        // insert at head
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void append(int data) {
        // insert at tail
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void print() {
        Node* curr = head;
        if(curr == nullptr) {
            printf("NULL EMPTY\n");
            return;
        }
        printf("NULL ");
        while(curr != nullptr) {
            printf("= | %d | ", curr->data);
            curr = curr->next;
        }
        printf("= NULL\n");
    }

    void reversePrint() {
        Node* curr = head;
        if(curr == nullptr) {
            printf("NULL EMPTY\n");
            return;
        }
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        printf("NULL ");
        while(curr != nullptr) {
            printf("= | %d | ", curr->data);
            curr = curr->prev;
        }
        printf("= NULL\n");
    }
};

int main() {
    DoublyLinkedList* dll = new DoublyLinkedList();
    dll->append(1);
    dll->prepend(0);
    dll->append(2);
    dll->print();
    dll->reversePrint();
    return 0;
}