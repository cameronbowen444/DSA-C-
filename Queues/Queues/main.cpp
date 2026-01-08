
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
    
    Node(int val){
        value = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node *first;
    Node *last;
    int length;
    
public:
    Queue(int val){
        Node *newNode = new Node(val);
        first = newNode;
        last = newNode;
        length = 1;
    }
    void printQueue(){
        Node *temp = first;
        while (temp){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void enqueue(int val){
        Node *newNode = new Node(val);
        if (length == 0){
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    int dequeue() {
        if (length == 0) return -1;
        Node *temp = first;
        int delVal = temp->value;
        if (length == 1){
            first = nullptr;
            last = nullptr;
        } else {
            first = first->next;
        }
        delete temp;
        length--;
        return delVal;
    }
    
};
int main() {
    Queue *myQueue = new Queue(7);
    myQueue->printQueue();
    myQueue->enqueue(11);
    myQueue->enqueue(43);
    myQueue->printQueue();
    cout << myQueue->dequeue() << endl;
    myQueue->printQueue();
}
