//TODO: member parameters should start with 'm_'

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include "Node.h"
const int START_nodes_amount = 100;
const int EXPAND_RATE = 4;

template<class T> class Queue{
public:
    Queue(); //constructor
    Queue(const Queue&); //copy constructor
    Queue& operator=(const Queue&); // '=' operator
    ~Queue(); //deconstructor

    void pushBack(T item);
    T& front();
//    const T& front(); //TODO: syntax. why cant i make a const version of this function like in the slides?
    void popFront();
    int size();


    //-------------------Iterator------------------------// 
    class Iterator;  //TODO: syntax for declaring one class inside another?
    Iterator begin() const;
    Iterator end() const;


private:
    Node<T>* first;
    Node<T>* last;
    int nodes_amount;
};

//---------------------------------Iterator class------------------------------------------//
template<class T> class Queue<T>::Iterator { //TODO: needs to be 'Iterator<T>' or 'Iterator'?
    //TODO: finish Iterator using slides from lecture about operators. or from tutorial.
public:
    explicit Iterator(Queue<T> *queue); //TODO: finish constructor
    Iterator(const Iterator&) = default;
    ~Iterator() = default;

    //-----------------------------Iterator operators-------------------------------------//
    bool operator!=(const Iterator &other);
    T operator*();
    void operator++();

    Iterator begin() const;
    Iterator end() const;

private:
    const Queue<T>* queue;
    Node<T>* current;

    friend class Queue<T>; //TODO: make sure friend is needed for internal class.
};


//-------------------implementation of template Iterator functions----------------------------//


template<class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator &other) {
    return current != other.current;
}

template<class T>
T Queue<T>::Iterator::operator*() {
    return *current; //supposed to return current, not pointer to current.
}

template<class T>
void Queue<T>::Iterator::operator++() {
    current = (current->get_next());
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::begin() const {
    Iterator start(queue);
    start.current = *queue->first;
    return start;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::end() const {
    Iterator temp(queue);
//    temp.current = *queue->last;
    temp.current = nullptr;
    return temp;
}

template<class T>
Queue<T>::Iterator::Iterator(Queue<T> *queue) : queue(queue) { //this.queue = address of input queue.

}


//-------------------implementation of template Queue functions----------------------------//
template<class T>
Queue<T>::~Queue() {  //TODO: code copied from HW1. validity needs to be checked.
    Node<T> head = first;
    Node<T> temp;
    while (head->next) {
        temp = head->next;
        free(head);
        head = temp;
    }
    free(head);
}

template<class T>
Queue<T>::Queue() : nodes_amount(0), first(new Node<T>), last(first){

} //TODO: syntax for assigning memory on heap in constructors.


template<class T>
void Queue<T>::pushBack(T item) {
    Node<T> addition = new Node<T>;
    last->connect_next(addition);
    last = *addition;
    nodes_amount++;
}

template<class T>
T& Queue<T>::front() {
    if (size() > 0)
    {
        return &first->get_content();
    }
    return nullptr; //no nodes so no content
}

template<class T>
void Queue<T>::popFront() {

}

template<class T>
int Queue<T>::size() {
    return 0;
}


#endif //HW3_QUEUE_H
