
#include <iostream>
using namespace std;

//ADVANCED
// Parameter Passing
    // Pass by Value == copies value (doesnt actually modify it)
    // Call by Address == (pointers) modifies actual values (need to reference memory address specifically)
    // Call by Reference == modifies actual values (just need to change actual value)

// basic function - only needs to copy values, not modify them
int add(int a, int b) {
    int c = a + b;
    return c;
}

// Call by Address
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Call by Reference
void swap2(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


// Arrays (no matter how you pass them, ALWAYS CHANGES THE DATA)
void func(int A[], int n){ //automatically points to array without syntax
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void func2(int *A, int n){ //becuase of the above still works like this
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

// Also becuase its always treated like a pointer, it changes orignal values if needed
void func3(int A[], int n){
    for (int i = 0; i < n; i++){
        A[i] = A[i] + 10;
        cout << A[i] << " ";
    }
    cout << endl;
}

// function returning arr address
int *func3(int size){
    int *p;
    p = new int[size];
    for (int i = 0; i < size; i++){
        p[i] = i + 1;
    }
    return p;
}





int main() {
    int num1 = 10;
    int num2 = 15;
    int sum = add(num1, num2);
    cout << sum << endl;
    
    cout << num1 << " - " << num2 << endl;
    swap(num1, num2);
    cout << num1 << " - " << num2 << endl;
    
    cout << endl;
    
    cout << num1 << " - " << num2 << endl;
    swap2(num1, num2);
    cout << num1 << " - " << num2 << endl;
    
    cout << endl;
    
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;
    for (int x:A){
        cout << x << " ";
    }
    cout << endl;
    func(A, n);
    func2(A, n);
    func3(A, n);
    
    // real values changed
    for (int x:A){
        cout << x << " ";
    }
    cout << endl;
    
    int *ptr, size = 5;
    ptr = func3(size);
    func(ptr, size);
    
    delete ptr;
    
    return 0;
}
