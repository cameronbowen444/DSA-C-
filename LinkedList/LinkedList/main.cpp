
#include <iostream>
using namespace std;

//can also use struct (just preference)
class Node {
public:
    int value;
    Node *next;
    
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int length;
public:
    LinkedList(int value){
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    void printList(){
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void getHead() {
        cout << "Head: " << head->value << endl;
    }
    void getTail() {
        cout << "Tail: " << tail->value << endl;
    }
    void getLength() {
        cout << "Length: " << length << endl;
    }
    void Append(int val){
        Node *newNode = new Node(val);
        if (length == 0){
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
        
        Node *temp = head;
        Node *pre = head;
        
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
        length--;
        
        if (length == 0){
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
    }
    void Prepend(int val) {
        Node *newNode = new Node(val);
    
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }
    void deleteFirst(){
        if (head == nullptr) return;
        Node *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }
    Node *get(int index) {
        if (index < 0 || index >= length){
            return nullptr;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }
    bool set(int index, int value) {
        Node *temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }
    bool insert(int index, int value){
        if (index < 0 || index > length) return false;
        if (index == 0) {
            Prepend(value);
            return true;
        }
        if (index == length){
            Append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }
    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();
        
        Node *prev = get(index - 1);
        Node *temp = prev->next;
        
        prev->next = temp->next;
        delete temp;
        length--;
    }
    
    void reverse() {
        Node *temp = head;
        head = tail;
        tail = temp;
        
        Node *after = temp->next;
        Node *before = nullptr;
        
        for (int i = 0; i < length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }
    
    
    ~LinkedList(){
        Node *temp = head;
        while (head != nullptr){
            head = head->next;
            delete temp;
            temp = head;
        }
        cout << "Done" << endl;
    }
    
};


int main() {
    LinkedList *myList = new LinkedList(4);
    myList->printList();
    myList->getHead();
    myList->getTail();
    myList->getLength();
//    myList->deleteFirst();
//    myList->deleteLast();
//    myList->printList();
    myList->Append(54);
    myList->Append(12);
    myList->Append(78);
    myList->printList();
//    myList->deleteLast();
//    myList->printList();
    myList->Prepend(2);
    myList->printList();
//    myList->deleteFirst();
//    myList->printList();
    cout << myList->get(3)->value << endl;
    myList->set(3, 8);
    myList->printList();
    myList->reverse();
    myList->printList();
    
    delete myList;
    return 0;
}
