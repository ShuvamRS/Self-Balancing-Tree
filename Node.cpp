template<class T>
class Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
public:
    Node() : next(nullptr), prev(nullptr) {}
    Node(T _data) : data(_data), next(nullptr), prev(nullptr) {}
    void set_data(T data) {this->data = data;}
    T get_data() const {return data;}
    void set_next(Node<T> *next) {this->next = next;}
    Node<T>* get_next() const {return next;}
    void set_prev(Node<T> *prev) {this->prev = prev;}
    Node<T>* get_prev() const {return prev;}
};
