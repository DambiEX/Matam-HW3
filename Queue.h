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
    Iterator(const Iterator&) = default;
    ~Iterator() = default;
    //-----------------------------Iterator functions-------------------------------------//
    void set_current(Node<T> *node);

    //-----------------------------Iterator operators-------------------------------------//
    bool operator!=(const Iterator &other);
    T operator*();
    void operator++(); //prefix ++ operator

//    Iterator begin() const; //these functions need to be part of Queue and not of Iterator
//    Iterator end() const;

private:
    explicit Iterator(Queue<T> *queue); //Iterator can only be ininitialized with begin() and end()
    const Queue<T>* queue;
    Node<T>* current;

    friend class Queue<T>; //friend is needed to call begin() and end()
};


//-------------------implementation of template Iterator functions----------------------------//


template<class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator &other) {
    //TODO: throw exception if they dont have the same queue.
    return current != other.current;
}

template<class T>
T Queue<T>::Iterator::operator*() {
    //TODO: exception if current == nullptr.
    return *current; //supposed to return current, not pointer to current.
}

template<class T>
void Queue<T>::Iterator::operator++() {
    current = (current->get_next());
}

template<class T>
Queue<T>::Iterator::Iterator(Queue<T> *queue) : queue(queue) { //this.queue = address of input queue.

}

template<class T>
void Queue<T>::Iterator::set_current(Node<T> *node) {
    current = node;
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

template<class T>
class Queue<T>::Iterator Queue<T>::begin() const {
    Iterator start(this);
    start.set_current(*first);
    return start;
}

template<class T>
class Queue<T>::Iterator Queue<T>::end() const {
    Iterator finish(this); //TODO: better naming.
    finish.set_current(nullptr);
    return finish;
}


#endif //HW3_QUEUE_H
