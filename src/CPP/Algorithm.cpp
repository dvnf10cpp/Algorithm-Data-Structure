#include <bits/stdc++.h>
#include "includes/structs.hpp"
using namespace std;

/**
 * Tree traversal is a process of visiting (reading) each node in tree exactly once in some order
 * Tree traversal can be classified into 2 category, breadth first and depth first
 * 1. Breadth first : 
 *      In breadth first traversal, we traverse the tree level by level. If we have tree with height of 3,
 *      then first we traverse every node at level 0, which is the root, next we traverse level 1 which is left and right
 *      of the root, next we traverse level 2 which is childs of the left previous and right previous and so on.
 *      In breadth first, we perform level order traversal.
 * 2. Depth first :
 *      In depth first traversal, we visiting the complete subtree in that child, means we go deep into left child node,
 *      until its null, then we right child node.
 *      There's 3 ways of depth first traversal : 
 *      1. <root><left><right> : preorder traversal, we read data first, then go left subtree then go right subtree [DLR]
 *      2. <left><root><right> : inorder traversal, we visit left subtree, then read data, then go right subtree [LDR]
 *      3. <left><right><root> : postoder traversal, we visit left subtree, then right subtree then read data [LRD]
*/

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data),left(nullptr),right(nullptr) {}
}

// you can try these methods in BST file
// all dfs take O(n) time complexity and O(n) space complexity for average case
void read_preorder_dfs(Node* node) {
    if(node == NULL) return;

    printf("%d ", node->data);
    read_preorder_dfs(node->left);
    read_preorder_dfs(node->right);
}

void read_inorder_dfs(Node* node) {
    if(node == NULL) return;

    read_inorder_dfs(node->left);
    printf("%d ", node->data);
    read_inorder_dfs(node->right);
}

void read_postorder_dfs(Node* node) {
    if(node == NULL) return;

    read_postorder_dfs(node->left);
    read_postorder_dfs(node->right);
    printf("%d ", node->data);
}

void read_levelorder_bfs(Node* node) {
    /**
     * in order to perform breadth first traversal,
     * we need queue to store pointer to each level child's node
     * Time complexity : O(n) , where n is number of nodes in binary tree
     * Space complexity : O(1) best case scenario, O(n) average and worst case scenario
    */
    
    if(node == NULL) return;
    Node* curr = node;
    queue<Node*> q;

    q.push(curr);
    while(!q.empty()) {
        cout << q.front()->data << " ";
        curr = q.front();
        q.pop();
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}


int main() {
    return 0;
}