#include <bits/stdc++.h>

using namespace std;

/**
 * Binary tree is a tree which each node can only have 2 children at maximum
 * -----------------------------------------------------------------------------
 * Strict or proper binary tree is a binary tree which each node can only have 
 * either 2 children or 0 children
 * -----------------------------------------------------------------------------
 * Complete binary tree is a binary tree if all levels except possibly the last are 
 * completely filled and all nodes are as left as possible
 * -----------------------------------------------------------------------------
 * Perfect binary tree is a binary tree in which each nodes must have 2 childrens 
 * or 0 if the nodes is at the lowest level
 * -----------------------------------------------------------------------------
 * Balanced binary tree is a binary tree if difference between height of left and right 
 * subtree for every node is not more than k (mostly 1)
 * this diff can be calculated with : diff = abs(hleft - hright)
 * -----------------------------------------------------------------------------
 * Depth of a node is defined as path from node root to that node
 * Height of tree is number of edges in longest path from root to a leaf
 * Height of empty tree = -1
 * Height of tree with 1 node = 0
 * -----------------------------------------------------------------------------
 * Some math equations : 
 * 1. Maximum of no. of nodes in a tree with height h => 2^(h+1) - 1
 * 2. Height of perfect binary tree with n nodes => log2(n+1) - 1
 * 3. Height of complete binary tree => floor(log2(n))
*/

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int data = 0) : 
        data(data), 
        right(nullptr), 
        left(nullptr) 
        {}
    };
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        Node* node = new Node(data);
        if(root == nullptr) {
            root = node;
            return;
        }
    }
};

int main() {
    return 0;
}