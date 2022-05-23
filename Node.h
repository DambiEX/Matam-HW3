#ifndef HW3_NODE_H
#define HW3_NODE_H

template<class T> class Node{

public:
    Node();
    Node(const Node&);
    ~Node() = default; //TODO: default or do i need to somehow delete the content?

    bool connect_next(Node* other);
    bool connect_previous(Node* other);

private:
    T content;
    Node next;
    Node previous;
};

#endif //HW3_NODE_H
