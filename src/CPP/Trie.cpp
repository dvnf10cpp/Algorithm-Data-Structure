#include <bits/stdc++.h>

// Prefix Tree is another type of tree that usually stores a string in form of node
// that has information about characters of the string we store in the tree
// Look PPT folder for more information
using namespace std;

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
        clear();
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
        // Takes O(n) time, where n is the length of the word
        insert(root, word);
    }

    bool search(string word) {
        // Takes O(n) time, where n is the length of the word
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
        // Takes O(n) time, where n is the length of the word
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

    void clear(TrieNode* node = Trie::root) {
        for(int i = 0; i < 26; i++) {
            if(node->child[i] != nullptr) {
                clear(node->child[i]);
            }
        }
        delete node;
    }

    void printSort(TrieNode* node, string res) {
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

        cout << "|--";
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


int main() {
    return 0;
}