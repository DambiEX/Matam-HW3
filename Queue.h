//TODO: member parameters should start with 'm_'

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
const int START_SIZE = 100;

template<class T> class Queue{
public:
    Queue(); //constructor
    Queue(const Queue&); //copy constructor
    Queue& operator=(const Queue&); // '=' operator
    ~Queue(); //deconstructor
    

    //-------------------Iterator------------------------// 
    class Iterator;  //TODO: syntax for declaring one class inside another?
    Iterator begin() const;
    Iterator end() const;


private:
    T* arr; // an array of T
    int max_size, current_size;
    int first_index, last_index;

    void expand();
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
delete arr;
}

template<class T>
Queue<T>::Queue() : max_size(START_SIZE), current_size(0), arr(new T[max_size]), first_index(0), last_index(0)
{}

template<class T>
void Queue<T>::expand() {

}




#endif //HW3_QUEUE_H
