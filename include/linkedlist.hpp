//====================
// Include Guard
#ifndef __LINKEDLIST_HPP_INCLUDED__
#define __LINKEDLIST_HPP_INCLUDED__

//===================
// Included Dependencies
#include <iostream>
#include <iterator>

//====================
// Forwarded Dependencies

//====================
// Classes (Header)

template<class T> class Node {
    public:
        Node();
        Node(T object);
        Node* next_;
        T object_;
};

template<class T> class ListIterator {
    public:
        ListIterator(Node<T>* head_node);
        T next();

    private:
        Node<T>* current_node;
};
        
template<class T> struct LinkedList {
    public:
        int size_;

        LinkedList (T initialObject);
        ~LinkedList();
        void addObject (T addedObject);
        void removeObject (int position); 
        ListIterator<T> getIterator();

    private:
        Node<T>* head_;
        Node<T>* current_;
};

//====================
// Class (Instantiation)

template<class T> Node<T>::Node() {};
template<class T> Node<T>::Node(T object) { object_ = object; };

template<class T> ListIterator<T>::ListIterator(Node<T>* head_node) {
    current_node = head_node;
};
template<class T> T ListIterator<T>::next() {
    Node<T>* tmp_node = current_node;
    current_node = current_node->next_;
    return current_node->object_;
};

template<class T> LinkedList<T>::LinkedList(T initialObject) {
    head_ = new Node<T>;
    current_ = new Node<T>(initialObject);
    head_->next_ = current_;
    current_->next_ = head_;
    size_ = 1;
};

// Destructor
template<class T> LinkedList<T>::~LinkedList() {
    for (int ii = 0; ii <= size_-1; ii++) {
        Node<T>* tmpNode = head_->next_;
        head_->next_ = head_->next_->next_;
        delete tmpNode;
    };
    delete head_;
};

// Add object. Link it to head to make this circular
template<class T> void LinkedList<T>::addObject(T addedObject) {
    Node<T>* tmpNode_ = current_;
    current_->next_ = new Node<T>(addedObject);
    current_ = current_->next_;
    current_->next_ = head_;
    size_ += 1;
};

// Remove the node in the spot specified by 'position'
template<class T> void LinkedList<T>::removeObject(int position) {
    if (position <= 0) { std::cout << "ERROR: Invalid position."; }
    else if (size_ > 0 && position <= size_) {
        Node<T>* tmpNode_ = head_;
        for (int ii = 0; ii < position-1; ii++) {
            tmpNode_ = tmpNode_->next_;
        };
        delete tmpNode_->next_;
        tmpNode_->next_ = tmpNode_->next_->next_;
        size_ -= 1;
    }
    else if (size_ > 0 && position > size_) { 
        std::cout << "ERROR: LinkedList contains less than " << position 
            << " elements\n"; 
    }
    else if (size_ == 0) { std::cout << "ERROR: LinkedList is empty\n"; }
};

// Return iterator
template<class T> ListIterator<T> LinkedList<T>::getIterator() {
    return ListIterator<T>(head_);
};

#endif
