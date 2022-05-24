//TODO: is "previous" needed?
#ifndef HW3_NODE_H
#define HW3_NODE_H

template<class T> class Node{

public:
    explicit Node();
    Node(const Node&);
    ~Node() = default; //TODO: default or do i need to somehow delete the content?

    void connect_next(const Node* other);
    Node* get_next();
    T get_content();
//    void connect_previous(const Node* other);

private:
    T content;
    Node* next; //link to next node
//    Node previous;
};

template<class T>

//----------------------implementation---------------------//

void Node<T>::connect_next(const Node* other){
    next = other;
}

//template<class T>
//void Node<T>::connect_previous(const Node *other) {
//    previous = other;
//}

template<class T>
Node<T>::Node() : content(), next(nullptr)  { //TODO: memory allocation on heap instead of stack for new nodes/for new content.

}

template<class T>
T Node<T>::get_content() {
    return &content;
}

template<class T>
Node<T> *Node<T>::get_next() {
    return next;
}


#endif //HW3_NODE_H
