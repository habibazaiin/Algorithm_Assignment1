#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Heap {
public:

    void insert(const T& value);
    T extractMax();
    T extractMin();
    bool isEmpty() const;
    T getMax();

private:
    vector<T> elements;
    void heapify(int index);
};

template <typename T>
void Heap<T>::insert(const T& value) {
    elements.push_back(value);

    int index = elements.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (elements[index] > elements[parent]) {
            swap(elements[index], elements[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T>
T Heap<T>::extractMax() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
    }

    T max = elements.front();
    elements.front() = elements.back();
    elements.pop_back();

    heapify(0);

    return max;
}

template <typename T>
T Heap<T>::extractMin() {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
    }

    T min = elements.front();
    for (const T& el : elements) {
        if (el < min) {
            min = el;
        }
    }
    return min;
}

template <typename T>
bool Heap<T>::isEmpty() const {
    return elements.empty();
}

template <typename T>
void Heap<T>::heapify(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < elements.size() && elements[left] > elements[largest]) {
        largest = left;
    }
    if (right < elements.size() && elements[right] > elements[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(elements[index], elements[largest]);
        heapify(largest);
    }
}

template<typename T>
T Heap<T>::getMax() {
    if (elements.empty()) {
        cout << "Heap is empty" << endl;
    }

    return elements[0];
}


//////////////Priority Queue///////////////


template <typename T>
class PriorityQueue {
private:

    Heap<T> heap;

public:

    void push(int value) {
        heap.insert(value);
    }

    T Top() {
        if (heap.isEmpty()) {
            cout << "Heap is empty" << endl;
        }

        return heap.getMax();
    }

};


////////////////////Heap Sort///////////////////

template <typename T>
void heapsort(vector<T>& vec) {
    Heap<T> heap;

    for (auto i: vec) {
        heap.insert(i);
    }

    for (int i = vec.size()-1; i >= 0; --i) {
        vec[i] = heap.extractMax();
    }
}


int main() {
    Heap<int> heap;


    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);

    cout << "Extracted Max: " << heap.extractMax() << endl;

    cout << "Extracted Min: " << heap.extractMin() << endl;

    while (!heap.isEmpty()) {
        cout << "Extracted Max: " << heap.extractMax() << endl;
    }
    cout << endl;

    /////////////Priority Queue////////////////

    PriorityQueue<int>pq;

    pq.push(3);
    pq.push(10);
    pq.push(5);
    pq.push(2);

    cout << "Top = " << pq.Top() << endl;
    cout << endl;

    /////////////////Heap Sort///////////////////

    vector<int> v = {3, 5, 6, 1, 9, 20};

    cout << "The List After Sorting : ";

    for (auto i: v) {
        cout << i << " ";
    }

    return 0;
}
