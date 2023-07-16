#include <bits/stdc++.h>

using namespace std;
/*
Linked list is a data structure that stores a data and and a pointer/reference to the next data (Node)
*/

struct Node {
    Node* next; // 4 bytes size, its pointer
    int data; // 4 bytes size

    Node() : next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

void printNode(Node* node){
    //debug method
    Node* curr = node;
    while(curr != nullptr) {
        printf("| %d | >> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct LinkedList {
    Node* head;

    LinkedList(): head(nullptr) {}

    ~LinkedList() { clear(); }

    void prepend(int data) {
        // Takes O(1), add at the head instead of the tail
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void add(int data) {
        // Takes O(n)
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
    }

    void insert(int index, int data) {
        if(index==0){
            prepend(data);
            return;
        }
        
        Node* newNode = new Node(data);
        Node* curr = head;
        while(index-- > 1) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void remove(int index) {
        if(index == 0) {
            head = head->next;
            return;
        }
        Node* curr = head;
        while(index-- > 1) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    int get(int index) {
        Node* curr = head;
        while(index-- > 0) {
            curr = curr->next;
        }
        return curr->data;
    }

    void clear() {
        Node* curr = head;
        Node* temp = head;
        while(curr != nullptr) {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        Node* curr = head;
        int temp = 0;
        while (curr != nullptr) {
            temp++;
            curr = curr->next;
        }
        return temp;
    }

    void reverseVisualize() {
        // PAHAMI KONSEP INI
        Node* newHead = nullptr;
        Node* curr = head;
        Node* next;
        printf("DEBUGGING...\n");// debug
        while(curr != nullptr) {
            printf("-------------------------------\n");
            next = curr->next;
            printf("next : "); // debug
            printNode(next); // debug
            curr->next = newHead; 
            printf("curr : "); // curr
            printNode(curr); // debug
            newHead = curr;
            printf("newhead : ");
            printNode(newHead); // debug
            curr = next;
            printf("-------------------------------\n");
        }
        head = newHead;
    }

    void reverse() {
        // Understand this concept
        Node* newHead = nullptr;
        Node* curr = head;
        Node* next;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = newHead; 
            newHead = curr;
            curr = next;
        }
        head = newHead;
    }

    void reverseRecusive() {
        
    }

    void print() {
        if(head == nullptr) {
            printf("Empty!\n");
            return;
        }
        Node* curr = head;
        while(curr != nullptr) {
            printf("| %d | >> ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
};

int main() {
    LinkedList* ll = new LinkedList();
    ll->add(5);
    ll->add(1);
    ll->prepend(2);
    ll->insert(1,3);
    ll->insert(3,4);
    ll->print();
    ll->remove(0);
    ll->print();
    ll->add(10);
    ll->add(1);
    printf("SEBELUM REVERSE : \n");
    ll->print();
    ll->reverseVisualize();
    printf("SETELAH REVERSE : \n");
    ll->print();

    delete ll;
    return 0;
}