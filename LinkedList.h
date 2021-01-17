#ifndef LinkedList_h
#define LinkedList_h

#include "Node.cpp"
#include <iostream>

template<class T>
class LinkedList
{
protected:
    Node<T> *head;
    Node<T> *tail;
    int NodeCount = 0;
    
public:
    LinkedList<T>(): head(nullptr), tail(head) {}
    LinkedList<T>(T data): head(new Node<T>(data)), tail(head) {NodeCount++;}
    ~LinkedList<T>();
    void Prepend(Node<T> *newNode) {InsertAfter(nullptr, newNode);}
    void Append(Node<T> *newNode) {InsertAfter(tail, newNode);}
    void InsertAfter(Node<T>*, Node<T>*);
    void Remove(Node<T>*);
    bool Display() const;
};

#endif
