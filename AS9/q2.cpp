#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;

        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteMin() {
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

    
        int i = 0;
        while(true) {
            int l = leftChild(i);
            int r = rightChild(i);
            int smallest = i;

            if(l < heap.size() && heap[l] < heap[smallest])
                smallest = l;
            if(r < heap.size() && heap[r] < heap[smallest])
                smallest = r;

            if(smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    int getMin() {
        if(heap.empty()) return -1;
        return heap[0];
    }

    void display() {
        cout << "Heap elements: ";
        for(int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap pq;
    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(3);
    pq.insert(7);

    pq.display();
    cout << "Minimum element: " << pq.getMin() << endl;

    pq.deleteMin();
    pq.display();
    cout << "Minimum element after deletion: " << pq.getMin() << endl;

    return 0;
}
