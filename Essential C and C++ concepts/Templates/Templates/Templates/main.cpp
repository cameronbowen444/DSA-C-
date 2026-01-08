
#include <iostream>
using namespace std;


//CLASS 1
template <class T>
class Arithmetic {
private:
    T a;
    T b;
public:
    //METHOD 1
//    Arithmetic(int a, int b){
//        this->a = a;
//        this->b = b;
//    }
//    int add(){
//        return a + b;
//    }
//    int sub(){
//        return a - b;
//    }
    
    //METHOD 2
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add() {
    return a + b;
}

template <class T>
T Arithmetic<T>::sub() {
    return a - b;
}

int main() {
    Arithmetic<int> ar(10, 5);
    cout << "Add: " << ar.add() << endl;
    cout << "Subtract: " << ar.sub() << endl;
    return 0;
}
