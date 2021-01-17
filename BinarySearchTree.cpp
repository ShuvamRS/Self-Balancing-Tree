#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    std::function<void(TreeNode<T>*)> remove_all = [&](TreeNode<T> *ptr) -> void
    {
        if (ptr == nullptr) return;
        remove_all(ptr->get_left());
        remove_all(ptr->get_right());
        delete ptr;
    };
    remove_all(root);
}

template<class T>
void BinarySearchTree<T>::insert(T data)
{
    TreeNode<T> *newNode = new TreeNode<T>(data);
    TreeNode<T> *pPre = nullptr, *pCur = root;
    
    if (!root) {root = newNode; return;}
    while(true)
    {
        if (pCur == nullptr)
        {
            pCur = newNode;
            if (data < pPre->get_data()) pPre->set_left(newNode);
            else pPre->set_right(newNode);
            break;
        }
        else if (data < pCur->get_data())
        {
            pPre = pCur;
            pCur = pCur->get_left();
        }
        else
        {
            pPre = pCur;
            pCur = pCur->get_right();
        }
    }
}

template<class T>
void BinarySearchTree<T>::search(std::string key) const
{
    TreeNode<T> *rover = root;
    while(true)
    {
        if (!rover)
        {
            std::cout << key << " not found!\n";
            break;
        }
        if(rover->get_data() == key)
        {
            std::cout << "Found!\n"<< rover->get_data() << std::endl;
            break;
        }
        else if(key < rover->get_data()) rover = rover->get_left();
        else rover = rover->get_right();
    }
}

template<class T>
void BinarySearchTree<T>::search(T key) const
{
    std::function<void(TreeNode<T>*)> recursive_search = [&, key](TreeNode<T> *rover) -> void
    {
        if (!rover)
        {
            std::cout << key << " not found!\n";
            return;
        }
        if (rover->get_data() == key)
        {
            std::cout << "\nFound!\n"<< rover->get_data() << std::endl;
            return;
        }
        else if(key < rover->get_data()) recursive_search(rover->get_left());
        else recursive_search(rover->get_right());
    };
    recursive_search(root);
}

template<class T>
int BinarySearchTree<T>::get_height(TreeNode<T> *node) const
{
    if (node == nullptr) return -1;
    int left_height = get_height(node->get_left());
    int right_height = get_height(node->get_right());
    return 1 + std::max(left_height, right_height);
}

template<class T>
bool BinarySearchTree<T>::is_complete(TreeNode<T> *node) const
{
    // An empty tree is complete Binary Tree
    if (node == nullptr) return 1;
    
    // This flag variable is set true
    // when a non full node is seen.
    bool flag = 0;
    
    Queue<TreeNode<T>*> *queue = new Queue<TreeNode<T>*>();
    queue->Push(new Node<TreeNode<T>*>(node));
    
    while (!queue->IsEmpty())
    {
        TreeNode<T> *tempNode = queue->Pop();
        
        // Check if left child is present
        if (tempNode->get_left())
        {
            // If we have seen a non full node, and we see a node
            // with non-empty left child, then the given tree is not
            // a complete Binary Tree
            if (flag) return 0;
            
            // Enqueue left child
            queue->Push(new Node<TreeNode<T>*>(tempNode->get_left()));
        }
        // If this is a non-full node, set the flag true
        else flag = 1;
        
        // Check if right child is present
        if (tempNode->get_right())
        {
            // If we have seen a non full node, and we see a node
            // with non-empty right child, then the given tree is not
            // a complete Binary Tree.
            if (flag) return 0;
            
            // Enqueue right child
            queue->Push(new Node<TreeNode<T>*>(tempNode->get_right()));
        }
         // If this is a non-full node, set the flag true
        else flag = 1;
    }
    // If we reach here, then the tree is complete Binary Tree
    return true;
}

template<class T>
bool BinarySearchTree<T>::is_balanced(TreeNode<T> *node) const
{
    return (std::abs(get_height(node->get_left()) - get_height(node->get_right())) > 1) ? false : true;
}


template<class T>
TreeNode<T> *BinarySearchTree<T>::rotate_left(TreeNode<T> *node)
{
    TreeNode<T> *temp = node->get_right(); // set temp = grandparent's right child
    node->set_right(temp->get_left()); // set grandparent's right child = temp's left child
    temp->set_left(node); // set temp's left child = grandparent
    return temp; // use temp instead of grandparent
}

template<class T>
TreeNode<T> *BinarySearchTree<T>::rotate_right(TreeNode<T> *node)
{
    TreeNode<T> *temp = node->get_left(); // set temp = grandparent's left child
    node->set_left(temp->get_right()); // set  grandparent's left child = temp's right child
    temp->set_right(node); // set temp's right child = grandparent
    return temp; // use temp instead of grandparent
}

template<class T>
TreeNode<T> *BinarySearchTree<T>::rotate_leftRight(TreeNode<T> *node)
{
    // parent rotates to the left of grandchild and grandchild is returned (as the new parent)
    // by the rotate_left() which gets set to grandparent's left as the new parent.
    node->set_left(rotate_left(node->get_left()));
    
    // grandparent goes to the right of the parent node and the parent node is returned by rotate_right()
    return rotate_right(node);
}

template<class T>
TreeNode<T> *BinarySearchTree<T>::rotate_rightLeft(TreeNode<T> *node)
{
    // parent rotates to the right of grandchild and grandchild is returned (as the new parent)
    // by the rotate_right() which gets set to grandparent's right as the new parent.
    node->set_right(rotate_right(node->get_right()));
    
    // grandparent goes to the left of the parent node and the parent node is returned by rotate_left()
    return rotate_left(node);
}


template<class T>
TreeNode<T>* BinarySearchTree<T>::balance_height(TreeNode<T> *node)
{
    if (!node) return nullptr;
    
    while (!is_balanced(node))
    {
        // if the height of left subtree is greater than that of right subtree by 2 or more
        if (get_height(node->get_left()) - get_height(node->get_right()) > 1)
        {
            // if node's left subtree is skewed-left
            if (get_height(node->get_left()->get_left()) > get_height(node->get_left()->get_right()))
            node = rotate_right(node);
            else node = rotate_leftRight(node);
        }
        
        // if the height of right subtree is greater than that of left subtree by 2 or more
        else
        {
            // if node's subtree is skewed-right
            if (get_height(node->get_right()->get_right()) > get_height(node->get_right()->get_left()))
            node = rotate_left(node);
            else node = rotate_rightLeft(node);
        }
    }
    node->set_left(balance_height(node->get_left()));
    node->set_right(balance_height(node->get_right()));
    return node;
}

template<class T>
void BinarySearchTree<T>::print_in_order() const
{
    std::function<void(TreeNode<T>*)> print = [&](TreeNode<T> *ptr) -> void
    {
        if (ptr == nullptr) return;
        print(ptr->get_left());
        std::cout << ptr->get_data() << std::endl;
        print(ptr->get_right());
    };
    print(root);
}

template<class T>
void BinarySearchTree<T>::print_pre_order() const
{
    std::function<void(TreeNode<T>*)> print = [&](TreeNode<T> *node) -> void
    {
        if (!node) return;
        std::cout << node->get_data() << std::endl;
        print(node->get_left());
        print(node->get_right());
    };
    print(root);
}

template<class T>
void BinarySearchTree<T>::print_post_order() const
{
    std::function<void(TreeNode<T>*)> print = [&](TreeNode<T> *node) -> void
    {
        if (!node) return;
        print(node->get_left());
        print(node->get_right());
        std::cout << node->get_data() << std::endl;
    };
    print(root);
}

template<class T>
void BinarySearchTree<T>::print_level_order() const
{
    if (!root) return;
    Stack<TreeNode<T>*> *stack = new Stack<TreeNode<T>*>;
    stack->Push(new Node<TreeNode<T>*>(root));
    int level = 1;

    while (!stack->IsEmpty())
    {
        Stack<TreeNode<T>*> *temp = new Stack<TreeNode<T>*>;
        
        while(!stack->IsEmpty())
        {
            temp->Push(new Node<TreeNode<T>*>(stack->Pop()));
        }
        std::cout << "Level " << level++ << std::endl;
        while(!temp->IsEmpty())
        {
            TreeNode<T> *node = temp->Pop();
            std::cout << node->get_data() << " ";
            if (node->get_left()) stack->Push(new Node<TreeNode<T>*>(node->get_left()));
            if (node->get_right()) stack->Push(new Node<TreeNode<T>*>(node->get_right()));
        }
        std::cout << "\n\n";
    }

}
