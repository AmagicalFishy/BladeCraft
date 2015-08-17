//====================
// Include Guard
#ifndef __LINKEDLIST_HPP_INCLUDED__
#define __LINKEDLIST_HPP_INCLUDED__

//===================
// Included Dependencies
#include <stdexcept>

//====================
// Forwarded Dependencies
//====================
// Classes (Header)

template<class T> struct LinkedList {

    public:
        LinkedList();
        LinkedList(const LinkedList& srcList);
        ~LinkedList();
    
        void addObject (T& addedObject);
        void removeObject (int position);
        //LinkedList& operator=(const LinkedList&); 
        
        class ListIterator {
            public:
                ListIterator();
                explicit ListIterator(LinkedList<T>& parentList);
                std::size_t size();

                // Operators
                ListIterator& operator++();
                //ListIterator operator++(int);
                ListIterator& operator--();
                //ListIterator operator--(int);
                T& operator*() const;
                //ListIterator& operator=(const ListIterator&);
                //bool operator==(const ListIterator& otherIter);
                //bool operator==(const T& otherObject);
                bool operator!=(const ListIterator& otherIter);
                //bool operator!=(const T& otherObject);

            private:
                typename LinkedList::Node* current_;
                //typename LinkedList::Node& parentHead_;
                //typename LinkedList::Node& parentTail_;
        };


        ListIterator begin();
        ListIterator end();
        std::size_t size_;

    private:

        struct Node {
            Node();
            Node(T& object);
            Node(const Node&);

            Node* next_;
            Node* prev_;
            T* object_;
        };

        Node head_;
        Node tail_;
};

//====================
// Classes (Implementation)

// Linked List default constructor 
template<class T> LinkedList<T>::LinkedList() 
: size_{0} {
    head_.next_ = &tail_;
    tail_.prev_ = &head_;
};

// Linked List copy constructor
template<class T> LinkedList<T>::
LinkedList(const LinkedList& srcList) { 
    size_ = srcList.size_;
    head_.next_ = &tail_;
    tail_.prev_ = &head_;
    ListIterator nodesToCopy = srcList.getIterator();

    while (nodesToCopy != srcList.end()) { 
        this->addObject(*nodesToCopy);
        srcList.removeObject(1);
    };
    delete &srcList;
};
    
// Linked List destructor
template<class T> LinkedList<T>::~LinkedList() {
    for (int ii = 1; ii == size_; ++ii) {
        Node* toDelete = head_.next_;
        head_.next_ = head_.next_->next_;
        delete toDelete;
    };
};
        
// Add object to Linked List
template<class T> void LinkedList<T>::addObject(T& addedObject) {
    Node* node = new Node(addedObject);
    node->prev_ = tail_.prev_;
    tail_.prev_->next_ = node;
    tail_.prev_ = node;
    node->next_ = &tail_;
    ++size_;
};

// Remove object from Linked List
template<class T> void LinkedList<T>::removeObject(int position) {
    Node* toDelete = &head_;
    if (position > size_ || position < 0) { 
        throw(std::out_of_range("Invalid index in removeObject " 
                    "argument")); 
    };
    for (int ii = 0; ii < position; ++ii) {
        toDelete = toDelete->next_;
    };
    toDelete->prev_->next_ = toDelete->next_;
    toDelete->next_->prev_ = toDelete->prev_;
    delete toDelete;
    --size_;
};

// Linked List Iterator constructor
template<class T> LinkedList<T>::ListIterator::
ListIterator(LinkedList<T>& parentList) {
//: parentHead_(parentList.head_), parentTail_(parentList.tail_) {
    current_ = parentList.head_.next_;
};

// Return size of Linked list
template<class T> std::size_t LinkedList<T>::ListIterator::size() {
    return size_;
};

// Iterator operators
// Increment forward
template<class T> typename LinkedList<T>::ListIterator& LinkedList<T>::
ListIterator::operator++() {
    current_ = current_->next_;
    return *this;
};
//template<class T> typename LinkedList<T>::ListIterator LinkedList<T>::
//ListIterator::operator++(int) {
//    ListIterator tmpIterator = *this;
//    current_ = current_->next_;
//    return tmpIterator;
//};

// Increment backward
template<class T> typename LinkedList<T>::ListIterator& LinkedList<T>::
ListIterator::operator--() {
    current_ = current_->prev_;
    return *this;
};
//template<class T> typename LinkedList<T>::ListIterator LinkedList<T>::
//ListIterator::operator--(int) {
//    ListIterator tmpIterator = *this;
//    current_ = current_->prev_;
//    return tmpIterator;
//};
//


// Return object pointed to
template<class T> T& LinkedList<T>::ListIterator::
operator*() const {
        return *(current_->object_); 

// throw std::runtime_error("Iterator's object points to NULL"); }
};

// Comparisons
//template<class T> bool LinkedList<T>::ListIterator::
//operator==(const LinkedList<T>::ListIterator& otherIter) {
//    return &(**this) == &(*otherIter);
//};
template<class T> bool LinkedList<T>::ListIterator::
operator!=(const ListIterator& otherIter) { 
    return &(**this) != &(*otherIter);
};

// Return an iterator object via begin() and end()
template<class T> typename LinkedList<T>::ListIterator
LinkedList<T>::begin() {
    ListIterator beginIterator(*this);
    return beginIterator;
};
template<class T> typename LinkedList<T>::ListIterator
LinkedList<T>::end() {
    ListIterator endIterator(*this);
    for (int ii = 0; ii < size_; ++ii) { ++endIterator; }; 
    return endIterator;
};

// Node constructors
template<class T> LinkedList<T>::Node::Node()
: object_(nullptr), next_(nullptr), prev_(nullptr) {};

template<class T> LinkedList<T>::Node::Node(T& object) {
    object_ = &object;
};

#endif
