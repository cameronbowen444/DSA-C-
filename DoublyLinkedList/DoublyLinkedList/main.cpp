
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
    
    Node(int value){
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
    int length;
public:
    DoublyLinkedList(int val){
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    
    void printList(){
        Node *temp = head;
        while (temp){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void Append(int val){
        Node *newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }
    
    void deleteLast(){
        if (head == nullptr) return;
        Node *temp = tail;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }
    
    void prepend(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    
    void deleteFirst() {
        if (head == nullptr) return;
        Node *temp = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }
    
    Node *get(int index){
        if (index < 0 || index >= length){
            return nullptr;
        }
        Node *temp = head;
        if (index < length/2){
            for (int i = 0; i < index; i++){
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; i--){
                temp = temp->prev;
            }
        }
        return temp;
    }
    bool set(int index, int value){
        Node *temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }
    
    bool insert(int index, int value){
        if (index < 0 || index > length) {
            return false;
        }
        if (index == 0){
            Append(value);
        } else if (index == length){
            prepend(value);
        } else {
            Node *newNode = new Node(value);
            Node *before = get(index - 1);
            Node *after = get(index);
            newNode->prev = before;
            newNode->next = after;
            before->next = newNode;
            after->prev = newNode;
            length++;
        }
        return true;
    }
    
    void deleteNode(int index){
        if (index < 0 || index >= length) return;
        if (index == 0){
            return deleteFirst();
        }
        if (index == length - 1){
            return deleteLast();
        }
        Node *temp = get(index);
        
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
};


int main() {
    DoublyLinkedList *myList = new DoublyLinkedList(4);
    myList->printList();
    myList->Append(11);
    myList->Append(44);
    myList->printList();
//    myList->deleteLast();
//    myList->deleteLast();
//    myList->deleteLast();
    myList->printList();
    myList->prepend(2);
    myList->printList();
//    myList->deleteFirst();
//    myList->deleteFirst();
//    myList->deleteFirst();
    myList->printList();
    myList->Append(23);
    myList->Append(15);
    myList->printList();
    cout << myList->get(4)->value << endl;
    myList->set(4, 78);
    myList->printList();
    myList->insert(4, 6);
    myList->insert(2, 18);
    myList->printList();
    return 0;
}
