
#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* next;
    
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node *top;
    int height;
public:
    Stack(int val) {
        Node *newNode = new Node(val);
        top = newNode;
        height = 1;
    }
    void printStack(){
        Node *temp = top;
        while (temp){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void push(int val){
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        height++;
    }
    int pop() {
        if (height == 0) return -1;
        Node *temp = top;
        int popVal = temp->value;
        top = top->next;
        delete temp;
        height--;
        return popVal;
    }
};


int main() {
    Stack *myStack = new Stack(3);
    myStack->printStack();
    myStack->push(16);
    myStack->push(77);
    myStack->push(42);
    myStack->printStack();
    cout << myStack->pop() << endl;
    myStack->printStack();
    return 0;
}
