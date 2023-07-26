#include <bits/stdc++.h>

using namespace std;

/**
 * Tree as data structure can be defined as a collection of entities called nodes 
 * linked together to simulate a hierarchy. Tree is a non linear data structure.
 * The top most node in the tree is called root of the tree. 
 * Each node can contain data of any type and link to other nodes that can be called children. 
 * Node that has reference or pointer to another node are called parent node.
 * Each node might have children, all node except root node has parent node.
 * Children of same parent are called sibling
 * Any node that doesnt have a child are called leaf node
 * Nodes that have same grandparent but not same parent can be called cousins
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * In a valid tree that has n nodes, there will be exactly n-1 edges
 * Depth of x in tree can be defined as length of path from root to node x
 * Height of x in tree can be defined as number of edges in longest path from x to a leaf
 * Heigh of tree can be defined as heigh of root node
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 * Applications in tree : 
    1. Storing naturally hierarchical data, ex : filesystem
    2. Organize data for quick search, insertion, deletion, ex : Binary Search Tree
    3. Prefix Tree, for dictionary
    4. Network routing algorithm
*/

// Generic tree
class Tree {
private:
    struct Node {
        vector<Node*> children;
        int data;
    };
public:
    Node* root;

    Tree() : root(nullptr) {}

};


int main() {
    return 0;
}