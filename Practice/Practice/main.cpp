
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int value){
        this->value = value;
    }
};


class LinkedList{
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(int val){
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    void printList() {
        Node *temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void getHead(){
        cout << head->value << endl;
    }
    void getTail(){
        cout << tail->value << endl;
    }
    void getLength() {
        cout << "Length: " << length << endl;
    }
    
    void Append(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    
    void deleteLast(){
        if (head == nullptr) return;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = head;
            Node *pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
            delete temp;
            length--;
        }
    }
};

int main() {
    LinkedList *myList = new LinkedList(4);
    myList->printList();
    myList->Append(7);
    myList->Append(13);
    myList->printList();
    myList->deleteLast();
    myList->printList();
    return 0;
}
