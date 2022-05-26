//TODO: all code conventions and naming conventions.
//TODO: destroy Iterators in case the m_queue is changed while they exist.
//TODO: make sure +/- functions in healthpoints dont need to be internal/external.

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include "Node.h"


template<class T> class Queue{
public:
    explicit Queue(Node<T> *first_ptr = nullptr, Node<T> *last_ptr = nullptr); //constructor
    Queue(const Queue&) = default; //copy constructor
    Queue& operator=(const Queue&) = default;
    ~Queue(); //destructor

    void pushBack(T item);
    T& front();
//    const T& front(); //TODO: syntax. why cant i make a const version of this function like in the slides?
    void popFront();
    int size();


    //-------------------Iterator------------------------//

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;


    //-------------------Exceptions------------------------//

    class EmptyQueue;


private:
    Node<T>* m_first;
    Node<T>* m_last;
    int m_nodes_amount;
};



//---------------------------------Iterator class------------------------------------------//

template<class T> class Queue<T>::Iterator {
public:
    Iterator(const Iterator&) = default;
    ~Iterator() = default;

    //-----------------------------Iterator operators-------------------------------------//

    bool operator!=(const Iterator &other); //comparison between different Iterators
    T operator*(); //retrieval of m_content
    void operator++(); //prefix ++ operator

private:
    explicit Iterator(Queue<T> *queue, Node<T> *node); //Iterator can only be initialized with begin() and end()
    const Queue<T>* m_queue;
    Node<T>* m_current;

    friend class Queue<T>; //friend is needed to call begin() and end()
};



//-------------------implementation of template Iterator functions----------------------------//


template<class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator &other) {
    //TODO: throw exception if they dont have the same m_queue.
    return m_current != other.m_current;
}

template<class T>
T Queue<T>::Iterator::operator*() {
    //TODO: exception if m_current == nullptr.
    return *m_current; //supposed to return m_current, not pointer to m_current.
}

template<class T>
void Queue<T>::Iterator::operator++() {
    m_current = (m_current->get_next());
}

template<class T>
Queue<T>::Iterator::Iterator(Queue<T> *queue, Node<T> *node) : m_queue(queue), m_current(node) {
    //this.m_queue = address of input m_queue.
}


//-------------------implementation of template ConstIterator functions------------------------//






//-------------------implementation of Queue::Iterator functions----------------------------//

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    return ConstIterator (this, m_first);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    return ConstIterator(this, nullptr);
}


//TODO: at the very end, copy code from iterator into ConstIterator.
//template<class T>
//typename Queue<T>::Iterator Queue<T>::begin() {
//    return Iterator (this, m_first);
//}
//
//template<class T>
//typename Queue<T>::Iterator Queue<T>::end() {
//    return Iterator(this, nullptr);
//}
//



//-------------------implementation of template Queue functions----------------------------//


template<class T>
Queue<T>::~Queue() {
    while (m_last->get_next()) {
        popFront();
    }
    popFront(); //the m_last item doesn't have a "m_next" but it still needs to be deleted.
}

template<class T>
Queue<T>::Queue(Node<T> *first_ptr, Node<T> *last_ptr) : m_nodes_amount(0), m_first(first_ptr), m_last(last_ptr){

}


template<class T>
void Queue<T>::pushBack(T item) {
    Node<T> *new_node = new Node<T>; //pointer to new node.
    new_node->set_content(item);
    if (size() == 0) //no items
    {
        m_first = new_node;
    }
    else
    {
        m_last->connect_next(new_node);
    }
    m_last = new_node;
    ++m_nodes_amount;
}

template<class T>
T& Queue<T>::front() {
    if (size() > 0)
    {
        return m_first->get_content(); //get_content returns &m_content.
    }
    return nullptr; //no nodes so no m_content
}

template<class T>
void Queue<T>::popFront() {
    //TODO: error in case of empty m_queue. checked in piazza and we need to return error.
    //m_queue not empty:
    Node<T> *temp = m_first->get_next();
    delete m_first;
    m_first = temp; //even if temp == nullptr we still want the m_first item to point there.
    --m_nodes_amount;
}

template<class T>
int Queue<T>::size() {
    return 0;
}







//----------------------------------complex functions--------------------------------//

template<class T>
Queue<T> filter(const Queue<T> queue, bool function(T item)){
    //TODO: argument function object needs to be bool? or maybe another template?
    Queue<T> new_queue;
    for (const T item : queue)
    {
        if (function(item))
        {
            new_queue.pushBack(item);
        }
    }
    return new_queue;
}

template<class T>
Queue<T> transform(const Queue<T> queue, void function(T &item)){
    for (T item : queue)
    {
        function(item);
    }
}



#endif //HW3_QUEUE_H
