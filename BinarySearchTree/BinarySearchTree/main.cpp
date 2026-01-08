
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node *root;
public:
    BST() {
        root = nullptr;
    }
    int minValue(Node *currentNode){
        while (currentNode->left != nullptr){
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }
    bool insert(int val) {
        Node *newNode = new Node(val);
        if (root == nullptr){
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true){
            if (newNode->value == temp->value) return false;
            if (newNode->value < temp->value) {
                if (temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
    bool contains(int val) {
        if (root == nullptr) return false;
        Node *temp = root;
        while (temp){
            if (val < temp->value) {
                temp = temp->left;
            } else if (val > temp->value){
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }
    
    //RECURSIVE
    bool rContains(Node *currentNode, int value) {
        if (currentNode == nullptr) return false;
        if (currentNode->value == value) return true;
        if (value < currentNode->value){
            return rContains(currentNode->left, value);
        } else {
            return rContains(currentNode->right, value);
        }
    }
    bool rContains(int value){
        return rContains(root, value);
    }
    
    Node *rInsert(Node *currentNode, int value){
        if (currentNode == nullptr) return new Node(value);
        if (value < currentNode->value){
            currentNode->left = rInsert(currentNode->left, value);
        } else if (value > currentNode->value){
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }
    void rInsert(int value){
        if (root == nullptr) root = new Node(value);
        rInsert(root, value);
    }
    
    Node *deleteNode(Node* currentNode, int value){
        if (currentNode == nullptr) return nullptr;
        if (value < currentNode->value){
            currentNode->left = deleteNode(currentNode->left, value);
        } else if (value > currentNode->value){
            currentNode->right = deleteNode(currentNode->right, value);
        } else {
            if (currentNode->left == nullptr && currentNode->right == nullptr){
                delete(currentNode); // still points to address
                return nullptr; // removes address
            } else if (currentNode->left == nullptr){
                Node *temp = currentNode->right;
                delete(currentNode);
                return temp;
            } else if (currentNode->right == nullptr){
                Node *temp = currentNode->left;
                delete(currentNode);
                return temp;
            } else {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }
        return currentNode;
    }
    void deleteNode(int value){
        root = deleteNode(root, value);
    }
    
    
    //TRAVERSAL
    //BFS (top row to bottom row)
    void BFS() {
        queue<Node*> myQueue;
        myQueue.push(root);
        
        while (myQueue.size() > 0){
            Node *currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";
            if (currentNode->left != nullptr){
                myQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr){
                myQueue.push(currentNode->right);
            }
        }
        cout << endl;
    }
    
    
    //DFS
    // PreOrder
    void DFSPreOrder(Node *currentNode){
        cout << currentNode->value << " ";
        if (currentNode->left) {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right) {
            DFSPreOrder(currentNode->right);
        }
        
    }
    void DFSPreOrder() {
        DFSPreOrder(root);
    }
    
    //PostOrder
    void DFSPostOrder(Node *currentNode) {
        if (currentNode->left){
            DFSPostOrder(currentNode->left);
        }
        if (currentNode->right){
            DFSPostOrder(currentNode->right);
        }
        cout << currentNode->value << " ";
    }
    void DFSPostOrder() {
        DFSPostOrder(root);
    }
    
    //InOrder
    void DFSInOrder(Node *currentNode) {
        if (currentNode->left){
            DFSInOrder(currentNode->left);
        }
        cout << currentNode->value << " ";
        if (currentNode->right){
            DFSInOrder(currentNode->right);
        }
    }
    void DFSInOrder() {
        DFSInOrder(root);
    }
};


int main() {
    BST *myTree = new BST();
    myTree->insert(50);
    myTree->insert(25);
    myTree->insert(75);
    cout << myTree->contains(75) << endl;
    cout << myTree->contains(15) << endl;
    
    cout << myTree->rContains(75) << endl;
    cout << myTree->rContains(15) << endl;
    
    myTree->rInsert(15);
    myTree->rInsert(30);
    myTree->rInsert(65);
    myTree->rInsert(100);
    
//    myTree->deleteNode(75);
    
    myTree->BFS();
    myTree->DFSPreOrder();
    cout << endl;
    myTree->DFSPostOrder();
    cout << endl;
    myTree->DFSInOrder();
    cout << endl;
    return 0;
}
