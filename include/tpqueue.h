// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int first;
    int last;
    int count;
 public:
    TPQueue() : first(0), last(0), count(0) { arr = new T[size]; }
    bool isEmpty() const;
    bool isFull() const;
    void push(const T&);
    const T& pop();
};
template <typename T, int size>
bool TPQueue<T, size>::isEmpty() const {
    return 0 == count;
}
template <typename T, int size>
bool TPQueue<T, size>::isFull() const {
    return size == count;
}
template <typename T, int size>
void TPQueue<T, size>::push(const T& value) {
    if (isFull()) {
        throw std::string("Full!");
    } else {
        ++count;
        arr[last % size] = value;
        int l = last;
        while (l > first && arr[l % size].prior > arr[(l - 1) % size].prior) {
            T temp = arr[l % size];
            arr[l % size] = arr[(l - 1) % size];
            arr[(l - 1) % size] = temp;
            l--;
        }
        last++;
    }
}
template <typename T, int size>
const T& TPQueue<T, size>::pop() {
    if (isEmpty()) {
        throw std::string("Empty!");
    } else {
        --count;
        return arr[first++ % size];
    }
}
struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
