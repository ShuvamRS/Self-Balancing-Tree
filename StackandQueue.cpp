#include "LinkedList.cpp"

template <class T>
class Stack: public LinkedList<T>
{
public:
    void Push(Node<T> *newNode) {this->Prepend(newNode);}
    T Pop()
    {
        T data = this->head->get_data();
        this->Remove(this->head);
        return data;
    }
    T Peek() const {return this->head->get_data();}
    bool IsEmpty() const {return this->head == nullptr;}
    int GetLength() const {return this->NodeCount;}
};

template <class T>
class Queue: public LinkedList<T>
{
public:
    void Push(Node<T> *newNode) {this->Append(newNode);}
    T Pop()
    {
        T data = this->head->get_data();
        this->Remove(this->head);
        return data;
    }
    T Peek() const {return this->head->get_data();}
    bool IsEmpty() const {return this->head == nullptr;}
    int GetLength() const {return this->NodeCount;}
};
