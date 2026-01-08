
#include <iostream>
using namespace std;

int main() {
    
    int A[5];
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;
    
    cout << sizeof(A) << endl; // 5 values * 4 bytes = 20 bytes
    cout << A[1] << endl; // print value C++
    printf("%d\n", A[2]); // C
    
    int AA[5] = {2, 4, 6, 8, 10};
    cout << AA[3] << endl;
    
    int AAA[] = {1, 3, 5, 7, 9}; // still works with size 5;
    int B[10] = {5, 10}; // B = [5, 10, 0, 0, 0, 0, 0, 0, 0, 0]
    cout << sizeof(B) << endl; // 10 values * 4 bytes = 40 bytes
    
    for (int i = 0; i < 5; i++){
        cout << AAA[i] << " ";
        cout << AA[i] << " ";
    }
    cout << endl;
    
    int BB[5] = {23, 65, 87, 32, 43};
    // ALSO HAVE FOR EACH LOOP
    for (int x : BB){
        cout << x << " ";
    }
    cout << endl;
    
    // INPUT ARRAY
    int n;
    cout << "Enter Size: ";
    cin >> n;
    int BBB[n];
    
    for (int i = 0; i < n; i++){
        cout << "Enter value " << (i + 1) << ": ";
        cin >> BBB[i];
    }
    for (int x : BBB){
        cout << x << " ";
    }
    cout << endl;
    
    
    
    return 0;
}
