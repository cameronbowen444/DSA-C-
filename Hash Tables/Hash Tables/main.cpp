
#include <iostream>
using namespace std;

class Node{
public:
    string key;
    int value;
    Node *next;
    
    Node(string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE]; // dont need constructor, this creates what you need (array of pointers to Node objects)/ Each val is Node type, arr is fixed size
    
    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++){ // ['p', 'a', 'i', 'n', 't']
            int asciiValue = int(key[i]); // p = 112, a = 97, etc...
            hash = (hash + asciiValue * 23) % SIZE; // (p) hash = (0 + 112 * 23) % 7
        }
        return hash;
    }
    
public:
    void printTable() {
        for (int i = 0; i < SIZE; i++){
            cout << i << ":" << endl;
            if (dataMap[i]) {
                Node *temp = dataMap[i];
                while (temp){
                    cout << "  {" << temp->key << ", " << temp->value << "}  " << endl;
                    temp = temp->next;
                }
            }
        }
    }

    
    void set(string key, int value){
        int index = hash(key);
        Node *newNode = new Node(key, value);
        if (dataMap[index] == nullptr){
            dataMap[index] = newNode;
        } else {
            Node *temp = dataMap[index];
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    int get(string key){
        int index = hash(key);
        Node *temp = dataMap[index];
        while (temp != nullptr){
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }
    
    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++){
            Node *temp = dataMap[i];
            while (temp){
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        
        return allKeys;
    }
};


int main() {
    HashTable *myHash = new HashTable();
    myHash->printTable();
    
    myHash->set("nails", 1000);
    myHash->set("bolts", 1200);
    myHash->set("tile", 50);
    myHash->set("lumber", 500);
    myHash->set("paint", 1000);
    myHash->printTable();
    
    cout << myHash->get("lumber") << endl;
    
    vector<string> myKeys = myHash->keys();
    for (auto key : myKeys) {
        cout << key << " ";
    }
    cout << endl;
    return 0;
}
