
#include <iostream>
using namespace std;

struct Rectangle {
    int length; // 4 bytes
    int breadth; //4 bytes
};
//struct Rectangle r1, r2, r3; can also declare it outside main



//STRUCTURE AS A PARAMETER - (There is a call by value (unlike arrays that dont))
    // Pass by Value
    // Call by Address
    //Returning address of a structure


void print(struct Rectangle r){ // Call By Value and doesn't change original values
    cout << "Length: " << r.length << endl;
    cout << "Breadth: " << r.breadth << endl;
}

//Call by address
void growRec(struct Rectangle *r){ // Call By Value and doesn't change original values
    r->length = r->length + 5;
    r->breadth = r->breadth + 5;
    cout << "New Length: " << r->length << endl;
    cout << "New Breadth: " << r->breadth << endl;
}

//function of TYPE rectangle (Returning address of a structure)
struct Rectangle *func(){ //create a dynamic rectangle
    struct Rectangle *p;
    p = new Rectangle;
    p->length = 25;
    p->breadth = 30;
    return p;
}



int main() {
    struct Rectangle r1 = {10, 5};
    cout << sizeof(r1) << endl;
    
    r1.length = 15;
    r1.breadth = 8;
    
    cout << r1.length << endl;
    cout << r1.breadth << endl;
    
    
    //POINTER TO STRUCTURE
    Rectangle r = {10, 5};
    cout << r.length << endl;
    cout << r.breadth << endl;
    
    Rectangle *p = &r; // pointing to a regular rectangle
    cout << p->length << endl;
    cout << p->breadth << endl;
    
    Rectangle *pp; // dynamic Structure to a regular rectangle
    pp = new Rectangle;
    
    pp->length = 25;
    pp->breadth = 15;
    cout << pp->length << endl;
    cout << pp->breadth << endl;
    
    delete pp;
    
    print(r);
    growRec(&r);
    
    //ACTUAL VALUES CHANGED
    cout << r.length << endl;
    cout << r.breadth << endl;
    
    
    struct Rectangle *ptr = func(); //from funciton creating dynamic structure
    print(*ptr);
    
    
    return 0;
}
