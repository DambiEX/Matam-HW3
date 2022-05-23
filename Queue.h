//TODO: member parameters should start with 'm_'

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
const int START_SIZE = 100;
const int EXPAND_RATE = 4;

template<class T> class Queue{
public:
    Queue(); //constructor
    Queue(const Queue&); //copy constructor
    Queue& operator=(const Queue&); // '=' operator
    ~Queue(); //deconstructor

    void pushback(T item);

    //-------------------Iterator------------------------// 
    class Iterator;  //TODO: syntax for declaring one class inside another?
    Iterator begin() const;
    Iterator end() const;


private:
    T* first;
    T* last;
    int size;
};

template<class T> class Queue<T>::Iterator {
    //TODO: finish Iterator using slides from lecture about operators. or from tutorial.
public:
    Iterator(); //TODO: finish constructor
    Iterator(const Iterator&) = default;
    ~Iterator() = default;

    Iterator begin() const;
    Iterator end() const;

private:
    const Queue<T>* queue;

    friend class Queue<T>;
};

//-------------------implementation of template functions----------------------------//
template<class T>
Queue<T>::~Queue() {
}

template<class T>
Queue<T>::Queue() : size(0), first(), last()
{}

template<class T>
void Queue<T>::pushback(T item) {
}


#endif //HW3_QUEUE_H
