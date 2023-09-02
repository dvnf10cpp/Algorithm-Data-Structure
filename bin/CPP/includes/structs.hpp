#pragma once
#include <bits/stdc++.h>
// for storing all data structures into one file

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;

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


class Trie {
private:
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

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int data) : 
        data(data), 
        left(nullptr), 
        right(nullptr) {}
    };

public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    BinarySearchTree(int data) {
        root = new Node(data);
    }

    void rInsert(int data) { // recursive insertion
        // Time complexity : O(log n)
        // Space complexity : O(log n), creates another node in memory to traverse recursively
        // Call to another recursive function
        if (root == nullptr) {
            root = new Node(data);
            return;
        }

        insert(root, data);
    }

    void iInsert(int data) { // iterative insertion
        // Time complexity : O(log n)
        // Space complexity : O(1), doesnt create another node in memory
        if (root == nullptr) {
            root = new Node(data);
            return;
        }

        Node* curr = root;
        while(1) {
            if(data <= curr->data) {
                if(curr->left == nullptr) {
                    curr->left = new Node(data);
                    return;
                }
                curr = curr->left;
            } else {
                if(curr->right == nullptr) {
                    curr->right = new Node(data);
                    return;
                }
                curr = curr->right;
            }
        }
    }

    bool rSearch(int data) { // recursive search
        // Time complexity : O(log n)
        // Space complexity : O(log n), creates another node in memory to traverse recursively
        // Call to another recursive function
        return search(root, data);
    }

    bool iSearch(int data) { // iterative search
        // Time complexity : O(log n)
        // Space complexity : O(1), doesnt create another

        Node* curr = root;
        while(1) {
            if(curr == nullptr) return false;

            if(data == curr->data) return true;

            if(data < curr->data) curr = curr->left;
            else curr = curr->right;
        }
    }

    int maxElement() {
        if(root == nullptr) return INT_MIN;

        Node* curr = root;
        while(curr->right != nullptr)
            curr = curr->right;
        return curr->data;
    }

    int minElement() {
        if(root == nullptr) return INT_MAX;

        Node* curr = root;
        while(curr->left != nullptr)
            curr = curr->left;
        return curr->data;
    }

    int height() {
        // Time complexity : O(n), whereas n = number of nodes in bst
        return findHeight(root);
    }

    void print() {
        cout << "=====================================\n";
        cout << "|  VISUAL BST    |    root: " << root->data << endl;
        cout << "-------------------------------------\n";
        printTreeRecursive(root);
        cout << "-------------------------------------\n";
    }

private:
    void insert(Node* node, int data) {
        if(data <= node->data) {
            // basecase 1
            if(node->left == nullptr) {
                node->left = new Node(data);
                return;
            }
            insert(node->left, data);
        } else {
            // basecase 2
            if(node->right == nullptr) {
                node->right = new Node(data);
                return;
            }
            insert(node->right, data);
        }
    }

    bool search(Node* node, int data) {
        if(node == nullptr) {
            return false;
        }
        
        if(node->data == data) 
            return true;
          

        if(data < node->data) 
            return search(node->left, data);
        else 
            return search(node->right, data);
        
    }


    void printTreeRecursive(Node* node, int depth = 0) {
        if (node != nullptr) {
            printTreeRecursive(node->right, depth + 1);

            for (int i = 0; i < depth; ++i) {
                std::cout << "    ";
            }

            std::cout << node->data << std::endl;

            printTreeRecursive(node->left, depth + 1);
        }
    }

    int findHeight(Node* node) {
        if(node==nullptr) return 0;

        int left = findHeight(node->left);
        int right = findHeight(node->right);

        return max(left, right) + 1;
    }
};

