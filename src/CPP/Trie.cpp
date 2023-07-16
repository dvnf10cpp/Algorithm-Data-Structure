#include <bits/stdc++.h>

// Prefix Tree
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
};


int main() {
    return 0;
}