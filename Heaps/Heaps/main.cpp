
#include <iostream>
#include <vector>
using namespace std;

class Heap{
private:
    vector<int> heap;
    int parent(int index){
        return (index - 1) / 2;
    }
    void swap(int index1, int index2) {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }
    int leftChild(int index){
        return 2 * index + 1;
    }
    int rightChild(int index){
        return 2 * index + 2;
    }
    void sinkDown(int index){ //don't need a parameter, few situations make it important
        int maxIdx = index;
        while (true) {
            int leftIdx = leftChild(index);
            int rightIdx = rightChild(index);
            if (leftIdx < heap.size() && heap[leftIdx] > heap[rightIdx]){
                maxIdx = leftIdx;
            }
            if (rightIdx < heap.size() && heap[rightIdx] > heap[leftIdx]) {
                maxIdx = rightIdx;
            }
            if (maxIdx != index){
                swap(index, maxIdx);
                index = maxIdx;
            } else {
                return;
            }
        }
    }
public:
    void printHeap() {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++){
            cout << heap[i];
            if (i < heap.size() - 1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    void insert(int value){
        heap.push_back(value);
        int current = heap.size() - 1;
        while (current > 0 && heap[current] > heap[parent(current)]){
            swap(current, parent(current));
            current = parent(current);
        }
    }
    int remove(){
        if (heap.empty()){
            return INT_MIN;
        }
        int maxVal = heap.front();
        if (heap.size() == 1){
            heap.pop_back();
        } else {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return maxVal;
    }
    
};


int main() {
    Heap *myHeap = new Heap();
    
    myHeap->insert(95);
    myHeap->insert(75);
    myHeap->insert(80);
    myHeap->insert(55);
    myHeap->insert(60);
    myHeap->insert(50);
    myHeap->insert(65);
    myHeap->printHeap();
    
    myHeap->remove();
    myHeap->printHeap();
    
    myHeap->remove();
    myHeap->printHeap();
    return 0;
}

