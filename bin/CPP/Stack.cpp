#include <bits/stdc++.h>
using namespace std;

/**
 * Stack as ADT
 * Stack is a collection with a restriction that insertion and deletion can only be performed from one end,
 * called the top
 * Only the top stack is accessible to read 
 * Stack is also called Last In First Out 
 * Operations : 
 *  1. Push, insert item to stack
 *  2. Pop, remove recent item from stack
 *  3. Top, returns element at the top
 *  4. Empty, return true if empty false otherwise
 *  All stack method's time complexity must be constant time, O(1)
*/

/// @brief stack implementation using array
class StackArray {
private:
    vector<int> array;
    int size;
    int last;
public:
    StackArray() {
        last = -1;
        size = 50;
        array = vector<int>(size);
    }

    void push(int data) {
        if(last == size - 1) {
            size *= 2;
            vector<int> temp = vector<int>(size);
            temp = array;
            array = temp;
        }
        array[++last] = data;
    }

    void pop() {
        --last;
    }

    int top() {
        return array[last];
    }

    bool empty() {
        return last == -1;
    }
};

/// @brief stack implementation using linkedlist
class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
    };
    Node* last = nullptr;
public:
    Stack() {}

    void push(int data) {
        Node* node = new Node(data);
        if(last == nullptr) {
            last = node; return;
        }
        node->next = last;
        last = node;
    }

    void pop(){
        if(last == nullptr) return;
        Node* temp = last;
        last = last->next;
        delete temp;
    }

    Node* get() {
        return last;
    }

    int top() {
        if(empty()) return INT_MIN;
        return last->data;
    }

    bool empty() {
        return last == nullptr;
    }
};

int main() {
    Stack* st = new Stack();
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    while(!st->empty()) {
        cout << st->top() << " ";
        st->pop();
    }
    cout << (st->empty() ? "YES\n" : "NO\n");
    return 0;
}