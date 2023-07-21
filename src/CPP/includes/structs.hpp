#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <bits/stdc++.h>
// for storing all data structures into one file

using std::string;
using std::cin;
using std::cout;
using std::endl;

class LinkedList {
private:
    struct Node {
        Node* next; // 4 bytes size, its pointer
        int data; // 4 bytes size

        Node() : next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
        Node(int data, Node* next) : data(data), next(next) {}
    };
public:
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
        Node* tmp;
        if(index == 0) {
            tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node* curr = head;
        while(index-- > 1) {
            curr = curr->next;
        }
        tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
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

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int data) : 
        data(data), 
        next(nullptr), 
        prev(nullptr) 
        {}
    };

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

    ~Trie() {
        clear(root);
    }

    void insert(TrieNode* node, string word){
        if(word.empty()) {
            node->end = true;
            return;
        }
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

    void clear(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->child[i] != nullptr) {
                clear(node->child[i]);
            }
        }
        delete node;
    }

    void printSort(TrieNode* node, string res = "") {
        if(node->end) {
            cout << res << '\n';
        }
        for(int i = 0;i < 26; i++) {
            if(node->child[i] != nullptr) {
                printSort(node->child[i], res + char(i + 97));
            }
        }   
    }

    void printTrie(TrieNode* node, string prefix = "", int level = 0) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < level; i++) {
            cout << "  ";
        }

        if (node == root) cout << "|root";
        else cout << "|--";
        if (level > 0) {
            cout << "[" << prefix[level - 1] << "]";
        }
        cout << endl;

        for (int i = 0; i < 26; i++) {
            if (node->child[i] != nullptr) {
                char currentChar = 'a' + i;
                string newPrefix = prefix + currentChar;
                printTrie(node->child[i], newPrefix, level + 1);
            }
        }
    }
};

#endif

