
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a; // when you attached r to a
    cout << a << " - " << r << endl;
    
    int b = 25;
    r = b;
    cout << a << " - " << r << endl; // r will always be a and vice versa
    
    r = 48;
    cout << a << " - " << r << " - " << b << endl;
    
    return 0;
}
