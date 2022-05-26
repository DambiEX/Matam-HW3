//TODO: all code conventions and naming conventions.
//TODO: destroy Iterators in case the m_queue is changed while they exist? there was an answer in the piazza i think.

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H

//---------------------------------Queue class---------------------------------------------//
template<class T> class Queue{
    /*
     * This class contains a linked list of T objects. Every node in the list contains one T
     * as its content. The items are taken out of the Queue in FIFO: first in first out. So
     * new nodes are connected to the last node, while when nodes are removed they are removed
     * from the first node.
     */
private:
    class Node;
    Node* m_first;
    Node* m_last;
    int m_nodes_amount;

public:
    explicit Queue(Node *first_ptr = nullptr, Node *last_ptr = nullptr); //constructor
    Queue(const Queue&) = default; //copy constructor. It works so don't change it?
    Queue& operator=(const Queue&) = default; //assignment operator
    ~Queue(); //destructor

    void pushBack(T item);
    T& front(); //returns reference because item should be changeable. e.g "queue1.front() = 3;"
    void popFront();
    int size();


    //-------------------Internal classes------------------------//

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    class EmptyQueue;


};


//---------------------------------Node class----------------------------------------------//
template<class T> class Queue<T>::Node{

public:
    explicit Node();
    Node(const Node&) = default;
    ~Node() = default;

    void connect_next(Node* other);
    Node* get_next();
    T& get_content(); //returns reference because item should be changeable. e.g "queue1.front() = 3;"
    void set_content(T item);

private:
    T m_content; //an item itself, not a pointer!
    Node* m_next; //link to next node
};


//--------------------------------Node implementation--------------------------------------//

template<class T>
void Queue<T>::Node::connect_next(Node* other){
    m_next = other;
}

template<class T>
Queue<T>::Node::Node() : m_content(), m_next(nullptr)  {
}

template<class T>
T& Queue<T>::Node::get_content() { //returns reference because item should be changeable. e.g "queue1.front() = 3;"
    return m_content;
}

template<class T>
typename Queue<T>::Node *Queue<T>::Node::get_next() {
    return m_next;
}

template<class T>
void Queue<T>::Node::set_content(T item) {
    m_content = item;
}



//---------------------------------Iterator class------------------------------------------//
template<class T> class Queue<T>::Iterator {
public:
    Iterator(const Iterator&) = default;
    ~Iterator() = default;

    //-----------------------------Iterator operators-------------------------------------//

    bool operator!=(const Iterator &other); //comparison between different Iterators
    T& operator*(); //retrieval of m_content
    void operator++(); //prefix ++ operator

    //-------------------Exceptions------------------------//
    class InvalidOperation;

private:
    explicit Iterator(Queue<T> *queue, Node *node); //Iterator can only be initialized with begin() and end()
    const Queue<T>* m_queue;
    Node* m_current_node;

    friend class Queue<T>; //friend is needed to call begin() and end()
};

//---------------------------------ConstIterator class------------------------------------------//
template<class T> class Queue<T>::ConstIterator {
public:
    ConstIterator(const ConstIterator&) = default;
    ~ConstIterator() = default;

    //-----------------------------ConstIterator operators-------------------------------------//

    bool operator!=(const ConstIterator &other); //comparison between different ConstIterators
    T& operator*(); //retrieval of m_content
    void operator++(); //prefix ++ operator

    //-------------------Exceptions------------------------//
    class InvalidOperation;

private:
    explicit ConstIterator(const Queue<T> *queue, Node *node); //ConstIterator can only be initialized with begin() and end()
    const Queue<T>* m_queue;
    Node* m_current_node;

    friend class Queue<T>; //friend is needed to call begin() and end()
};



//-------------------------------exceptions classes-------------------------------------------//

template<class T> class Queue<T>::EmptyQueue{};
template<class T> class Queue<T>::Iterator::InvalidOperation{};
template<class T> class Queue<T>::ConstIterator::InvalidOperation{};



//-------------------implementation of Queue::Iterator operators----------------------------//

template<class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator &other) {
    if(this->m_queue != other.m_queue) //pointer comparison
    {
        throw (InvalidOperation()); //throws an InvalidOperation object.
    }
    return m_current_node != other.m_current_node;
}

template<class T>
T& Queue<T>::Iterator::operator*() {
    if (m_current_node == nullptr)
    {
        throw (InvalidOperation());
    }
    return m_current_node->get_content();
}

template<class T>
void Queue<T>::Iterator::operator++() {
    if(m_current_node == nullptr)
    {
        throw (InvalidOperation());
    }
    m_current_node = (m_current_node->get_next());
}

template<class T>
Queue<T>::Iterator::Iterator(Queue<T> *queue, Node *node) : m_queue(queue), m_current_node(node) {
    //this.m_queue = address of input m_queue.
}



//-------------------implementation of Queue::Iterator functions----------------------------//


template<class T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator (this, m_first);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(this, nullptr);
}



//-------------------implementation of Queue::ConstIterator operators----------------------------//

template<class T>
bool Queue<T>::ConstIterator::operator!=(const Queue<T>::ConstIterator &other) {
    if(this->m_queue != other.m_queue) //pointer comparison
    {
        throw (InvalidOperation()); //throws an InvalidOperation object.
    }
    return m_current_node != other.m_current_node;
}

template<class T>
T& Queue<T>::ConstIterator::operator*() {
    if (m_current_node == nullptr)
    {
        throw (InvalidOperation());
    }
    return m_current_node->get_content();
}

template<class T>
void Queue<T>::ConstIterator::operator++() {
    if (m_current_node == nullptr)
    {
        throw (InvalidOperation());
    }
    m_current_node = (m_current_node->get_next());
}

template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T> *queue, Node *node) : m_queue(queue), m_current_node(node) {
    //this.m_queue = address of input m_queue.
}


//-------------------implementation of Queue::ConstIterator functions----------------------------//

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    return ConstIterator (this, m_first);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    return ConstIterator(this, nullptr);
}


//-------------------implementation of template Queue functions----------------------------//

template<class T>
Queue<T>::Queue(Queue::Node *first_ptr, Queue::Node *last_ptr) : m_nodes_amount(0), m_first(first_ptr), m_last(last_ptr){
}

template<class T>
Queue<T>::~Queue() {
    if (size() > 0)
    {
        while (m_first->get_next()) {
            popFront();
        }
        popFront(); //the m_last item doesn't have a "m_next" but it still needs to be deleted.
    }
}

template<class T>
void Queue<T>::pushBack(T item) {
    Node *new_node = new Node;
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
    //returns reference because item should be changeable. e.g "queue1.front() = 3;"
    if (size() <= 0)
    {
        throw (EmptyQueue());
    }
    else
    {
        return m_first->get_content(); //get_content returns &m_content.
    }
}

template<class T>
void Queue<T>::popFront() {
    if (m_first == nullptr){
        throw (EmptyQueue());
    }
    //m_queue not empty:
    Node *temp = m_first->get_next();
    delete m_first;
    m_first = temp; //even if temp == nullptr we still want the m_first item to point there.
    --m_nodes_amount;
}

template<class T>
int Queue<T>::size() {
    return m_nodes_amount;
}



//----------------------------------complicated functions--------------------------------//

template<class T>
Queue<T> filter(const Queue<T> &queue, bool function(T item)){
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
void transform(Queue<T> &queue, void function(T &item)){
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it) {
    function(*it);
    }
//    for (T t : queue)
//    {
//        function(t);
//    }
}



#endif //HW3_QUEUE_H
