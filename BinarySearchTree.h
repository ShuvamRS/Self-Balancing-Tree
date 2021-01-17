#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <functional>
#include <cmath>
#include "TreeNode.cpp"
#include "StackandQueue.cpp"

template<class T>
class BinarySearchTree
{
    TreeNode<T> *root;
    TreeNode<T>* rotate_left(TreeNode<T>*);
    TreeNode<T>* rotate_right(TreeNode<T>*);
    TreeNode<T>* rotate_leftRight(TreeNode<T>*);
    TreeNode<T>* rotate_rightLeft(TreeNode<T>*);
public:
    BinarySearchTree(): root(nullptr){}
    ~BinarySearchTree();
    void insert(T);
    void search(std::string) const; // iterative
    void search(T) const; // recursive
    int get_height(TreeNode<T>*) const;
    bool is_complete(TreeNode<T>*) const;
    bool is_balanced(TreeNode<T>*) const;
    TreeNode<T>* balance_height(TreeNode<T>*);
    void balance_height() {root = balance_height(root);}
    void print_in_order() const;
    void print_pre_order() const;
    void print_post_order() const;
    void print_level_order() const;
};

#endif
