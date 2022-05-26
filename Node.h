#ifndef HW3_NODE_H
#define HW3_NODE_H

template<class T> class Node{

public:
    explicit Node();
    Node(const Node&);
    ~Node() = default;

    void connect_next(Node* other);
    Node* get_next();
    T& get_content();
    void set_content(T item);

private:
    T m_content; //an item itself, not a pointer!
    Node* m_next; //link to next node
};

template<class T>



//----------------------implementation---------------------//


void Node<T>::connect_next(Node* other){
    m_next = other;
}

template<class T>
Node<T>::Node() : m_content(), m_next(nullptr)  {
}

template<class T>
T& Node<T>::get_content() {
    return &m_content; //returns reference because item should be changeable. e.g "queue1.front() = 3;"
}

template<class T>
Node<T> *Node<T>::get_next() {
    return m_next;
}

template<class T>
void Node<T>::set_content(T item) {
    m_content = item;
}


#endif //HW3_NODE_H
