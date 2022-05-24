//TODO: member parameters should start with 'm_'
//TODO: all code conventions and naming conventions.
//TODO: destroy Iterators in case the queue is changed while they exist.

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include "Node.h"


template<class T> class Queue{
public:
    Queue(Node<T> *first_ptr = nullptr, Node<T> *last_ptr = nullptr); //constructor
    Queue(const Queue&); //copy constructor
    Queue& operator=(const Queue&); // '=' operator
    ~Queue(); //deconstructor

    void pushBack(T item);
    T& front();
//    const T& front(); //TODO: syntax. why cant i make a const version of this function like in the slides?
    void popFront();
    int size();


    //-------------------Iterator------------------------//

    class Iterator;
    Iterator begin() const;
    Iterator end() const;


private:
    Node<T>* first;
    Node<T>* last;
    int nodes_amount;
};



//---------------------------------Iterator class------------------------------------------//

template<class T> class Queue<T>::Iterator { //TODO: needs to be 'Iterator<T>' or 'Iterator'?
public:
    Iterator(const Iterator&) = default;
    ~Iterator() = default;

    //-----------------------------Iterator operators-------------------------------------//

    bool operator!=(const Iterator &other); //comparison between different Iterators
    T operator*(); //retrieval of content
    void operator++(); //prefix ++ operator

private:
    explicit Iterator(Queue<T> *queue, Node<T> *node); //Iterator can only be initialized with begin() and end()
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
Queue<T>::Iterator::Iterator(Queue<T> *queue, Node<T> *node) : queue(queue), current(node) {
    //this.queue = address of input queue.
}


//-------------------implementation of template Queue functions----------------------------//


template<class T>
Queue<T>::~Queue() {  //TODO: code copied from HW1. validity needs to be checked.
    while (last->get_next()) {
        popFront();
    }
    popFront(); //the last item doesn't have a "next" but it still needs to be deleted.
}

template<class T>
Queue<T>::Queue(Node<T> *first_ptr, Node<T> *last_ptr) : nodes_amount(0), first(first_ptr), last(last_ptr){

}


template<class T>
void Queue<T>::pushBack(T item) {
    Node<T> *new_node = new Node<T>; //pointer to new node.
    new_node->set_content(item);
    if (size() == 0) //no items
    {
        first = new_node;
    }
    else
    {
        last->connect_next(new_node);
    }
    last = new_node;
    ++nodes_amount;
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
    //TODO: error in case of empty queue. checked in piazza and we need to return error.
    //queue not empty:
    Node<T> *temp = first->get_next();
    delete first;
    first = temp; //even if temp == nullptr we still want the first item to point there.
    --nodes_amount;
}

template<class T>
int Queue<T>::size() {
    return 0;
}

template<class T>
class Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator (this, first);
}

template<class T>
class Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(this, nullptr);
}


//----------------------------------complex functions--------------------------------//

template<class T>
Queue<T> filter(Queue<T> queue, bool function(T item)){ //TODO: function as parameters syntax
    Queue<T> new_queue;
    for (T item : queue) //TODO: make sure iterator returns items as intended.
    {
        if (function(item))
        {
            new_queue.pushBack(item);
        }
    }
    return new_queue;
}

template<class T>
Queue<T> transform(Queue<T> queue, void function(T &item)){
    for (T item : queue)
    {
        function(item);
    }
}



#endif //HW3_QUEUE_H
