#include "LinkedList.h"

template<class T>
LinkedList<T>::~LinkedList<T>()
{
    Node<T> *pCur = head;
    Node<T> *pNext = nullptr;
    
    while(pCur)
    {
        pNext = pCur->get_next();
        delete pCur;
        pCur = pNext;
        NodeCount--;
    }
}

template<class T>
void LinkedList<T>::InsertAfter(Node<T> *curNode, Node<T> *newNode)
{
    // List Empty
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    
    //Insert after tail
    else if(curNode == tail)
    {
        tail->set_next(newNode);
        newNode->set_prev(tail);
        tail = newNode;
    }
    
    //Insert at head
    else if(curNode == nullptr)
    {
        newNode->set_next(head);
        head->set_prev(newNode);
        head = newNode;
    }
    
    // Insert somewhere in middle
    else
    {
        Node<T> *sucNode = curNode->get_next();
        newNode->set_next(sucNode);
        newNode->set_prev(curNode);
        curNode->set_next(newNode);
        sucNode->set_prev(newNode);
    }
    NodeCount++;
}

template<class T>
void LinkedList<T>::Remove(Node<T> *curNode)
{
    Node<T> *sucNode = curNode->get_next();
    Node<T> *predNode = curNode->get_prev();
    
    if(sucNode != nullptr) sucNode->set_prev(predNode);
    if(predNode != nullptr) predNode->set_next(sucNode);
    if(curNode == head) head = sucNode; //Removed head
    if(curNode == tail) tail = predNode; //Removed tail
    
    NodeCount--;
    delete curNode;
}

template<class T>
bool LinkedList<T>::Display() const
{
    if (!head) return false;
    Node<T> *ptr = head;
    while (ptr)
    {
        std::cout << ptr->get_data() << " ";
        ptr = ptr->get_next();
    }
    return true;
}
