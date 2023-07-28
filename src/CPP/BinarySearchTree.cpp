#include <bits/stdc++.h>

using namespace std;

/**
 * Binary search tree is a type of binary tree in which for each node, 
 * value of all nodes in the left subtree is lesser or equal and 
 * value of all the nodes in right subtree is greater
 * Binary search tree has more effecient search, insert and delete than
 * array and linked list. All of the method time complexity is O(log n).
*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : 
    data(data), 
    left(nullptr), 
    right(nullptr) {}
};

class BinarySearchTree {
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

    Node* getSuccessor() {
        return getSuccessor(root, root->data);
    }

    void remove(int data) {
        remove(root, data);
    }

    void print() {
        cout << "=====================================\n";
        cout << "|  VISUAL BST    |    root: " << root->data << endl;
        cout << "-------------------------------------\n";
        printTreeRecursive(root);
        cout << "-------------------------------------\n";
    }

    void read_bfs() {
        read_bfs(root);
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

    void read_bfs(Node* node) {
        if(node == NULL) return;

        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            cout << q.front()->data << " ";
            node = q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
        }
        cout << endl;
    }

    int findMin(Node* node) {
        if(node == nullptr) return INT_MAX;

        int dl = findMin(node->left);
        int dr = findMin(node->right);

        int mn = min(dl,dr);

        return min(node->data, mn);
    }

    Node* find(Node* node, int data) {
        if(node == nullptr) return nullptr;

        if(node->data == data) return node;
        if(node->data < data) return find(node->right, data);
        else return find(node->left, data);
    }

    Node* findNodeMin(Node* node) {
        if(node == nullptr) return nullptr;

        for(;node->left != nullptr; node = node->left);

        return node;
    }

    // find successor of root, part before graph
    Node* getSuccessor(Node* root, int data) {
        // search the node - O(h) time complexity, h as height of the tree
        Node* current = find(root, data);
        if(current == nullptr) return nullptr;

        // case 1 : node has right subtree
        if(current->right != nullptr) {
            return findNodeMin(current->right); // O(h) time 
        } 
        // case 2 : node doesnt has right subtree // O(h) time
        Node* successor = nullptr;
        Node* ancestor = root;
        for(;ancestor != current;) {
            if(current->data < ancestor->data) {
                successor = ancestor->left;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }

        return successor;
    }

    void remove(Node*& node, int data) {
        if(node == nullptr) return;

        if(data<node->data) remove(node->left, data);
        else if(data>node->data) remove(node->right, data);
        else { // node found
            // case 1 : no child subtree
            if(node->left == nullptr && node->right == nullptr){
                delete node; 
                node = nullptr;
            } 
            // case 2.0 : left child is null
            else if(node->left == nullptr) {
                Node* temp = node;
                // right child become root or parent
                node = node->right;
                delete temp;
            } 
            // case 2.1 : right child is null
            else if(node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } 
            // cas 3 : 2 children, left and right child is present (not null)
            else {
                /*
                * to delete a node with 2 child in a tree, we can do one of two things : 
                * 1. find min in right subtree if exist, copy value to targetted value, delete the duplicate
                * 2. find max in left subtree if exist, copy value to targetted value, delete the duplicate
                */
                int temp = findMin(node->right);
                node->data = temp;
                remove(node->right, temp);
            }
        }
    }
};

void verify(bool found, int data) {
    if (found) {
        printf("found: %d\n", data);
    } else {
        printf("not found: %d\n", data);
    }
}

bool isBST(Node* node, long low = LONG_MIN, long high = LONG_MAX) {
    if(node == nullptr) return true;

    return (node->data > low && node->data < high 
    && isBST(node->left,low,node->data) 
    && isBST(node->right, node->data, high));
}



int main(){
    BinarySearchTree* bst = new BinarySearchTree();

    verify ( (bst->iSearch(15)), 15 );

    bst->iInsert(15);
    bst->iInsert(10);
    bst->iInsert(20);
    verify ( (bst->iSearch(15)), 15 );
    verify ( (bst->iSearch(10)), 10 );
    verify ( (bst->iSearch(20)), 20 );

    bst->iInsert(25); 
    bst->iInsert(19);
    bst->iInsert(39);

    verify ( (bst->iSearch(39)), 39 );
    verify ( (bst->iSearch(40)), 40 );
    verify ( (bst->iSearch(1)), 1 );

    (*bst).print();

    cout << "curr height: "<<bst->height() << endl;

    bst->read_bfs();

    cout << isBST(bst->root) << endl;

    bst->remove(15);

    (*bst).print();    

    cout << bst->getSuccessor()->data << endl;
    return 0;
}