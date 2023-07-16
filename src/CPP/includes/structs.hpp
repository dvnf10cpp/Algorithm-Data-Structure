#ifndef STRUCTS
#define STRUCTS

#include <bits/stdc++.h>
// for storing all data structures into one file

struct Node {
    Node* next; // 4 bytes size, its pointer
    int data; // 4 bytes size

    Node() : next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

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
        curr->next = curr->next->next;
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

class TrieNode {
public:
    TrieNode* child[26];
    bool end;
    
    TrieNode() {
        for(auto &tn : child)
            tn = nullptr;
        end = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    bool end;

    Trie() {
        root = new TrieNode();
    }

    void insert(TrieNode* node, string word){
        if(word.size()==0) return;
        int index = word[0] % 97;
        if(node->child[index] == nullptr)
            node->child[index] = new TrieNode();
        node = node->child[index];
        insert(node, word.substr(1));
    }

    void insert(string word) {
        insert(root, word);
    }

    bool search(string word) {
        TrieNode* node = root;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            int j = tolower(word[i]) % 97;
            if(node->child[j] == nullptr) {
                return false;
            }
            node = node->child[j];
        }
        return node->end;
    }


    bool startsWith(string prefix) {
        TrieNode* node = root;
        int n = prefix.size();
        for(int i = 0; i < n; i++) {
            int j = tolower(prefix[i]) % 97;
            if(node->child[j] == nullptr) {
                return false;
            }
            node = node->child[j];
        }
        return true;
    }
};`

#endif

