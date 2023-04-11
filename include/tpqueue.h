// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

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
        for (int last1 = last; last1 > first && arr[last1 % size].prior > arr[(last1-1) % size].prior; last1--) {
            T temp = arr[last1 % size];
            arr[last1 % size] = arr[(last1 - 1) % size];
            arr[(last1 - 1) % size] = temp;
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
