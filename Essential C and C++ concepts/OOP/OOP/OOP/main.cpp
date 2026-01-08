
#include <iostream>
using namespace std;


//STRUCTURE
//struct Rectangle {
//    int length;
//    int breadth;
//    
//void initialize(int l, int b){
//    length = l;
//    breadth = b;
//}
//
//int area(){
//    return length * breadth;
//}
//
//int perimeter(){
//    return 2 * (length + breadth);
//}
//};

//CLASS
class Rectangle {
private:
    int length;
    int breadth;
public:
    void initialize(int l, int b){
        length = l;
        breadth = b;
    }

    int area(){
        return length * breadth;
    }

    int perimeter(){
        return 2 * (length + breadth);
    }
};


int main() {
    //STRUCTURE
//    Rectangle r;
//    r.initialize(10, 15);
//    int a = r.area();
//    int p = r.perimeter();
//    
//    cout << a << endl;
//    cout << p << endl;
    
    //CLASS
    Rectangle r;
    r.initialize(10, 15);
    int a = r.area();
    int p = r.perimeter();
    
    cout << a << endl;
    cout << p << endl;
    
    return 0;
}
