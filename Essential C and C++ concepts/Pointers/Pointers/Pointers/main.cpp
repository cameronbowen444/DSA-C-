
#include <iostream>
using namespace std;

// POINTER ARE USED FOR:
    // 1) Accessing Heap memory
    // 2) Accessing resources (keyboard, monitor, etc...)
    // 3) Parameter Passing 



int main() {
    int a = 10;
    int *p;
    p = &a;
    
    
    cout << a << endl;
    cout << *p << endl;
    
    int A[5] = {2, 4, 6, 8, 10};
    p = A; // points at first value 2
    cout << *p << endl;
    
    for (int i = 0; i < 5; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    
    int *d;
    d = new int[5]; // dynamic array
    cout << *d << endl;
    for (int i = 0; i < 5; i++){
        d[i] = A[i]; //manually copy elements
        cout << d[i] << " ";
    }
    cout << endl;
    
    delete [] d;
    

    
    return 0;
}
