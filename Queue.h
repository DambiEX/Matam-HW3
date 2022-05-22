//TODO: member parameters should start with 'm_'

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H

template<class T> class Queue{
public:
    Queue(); //constructor
    Queue(const Queue&); //copy constructor
    Queue& operator=(const Queue&); // '=' operator
    ~Queue();

    class iterator;
    iterator begin() const;
    iterator end() const;

private:
    T* items; // an array of T
    int size;
};

template<class T> class Queue<T>::iterator {
    //TODO: finish iterator using slides from lecture about operators. or from tutorial.
public:
    iterator(); //TODO: finish constructor
    iterator(const iterator&) = default;
    ~iterator() = default;

    iterator begin() const;
    iterator end() const;

private:
    const Queue<T>* queue;

    friend class Queue<T>;
};
#endif //HW3_QUEUE_H
