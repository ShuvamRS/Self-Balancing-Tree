template <class T>
class TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
public:
    TreeNode(): data(nullptr), left(nullptr), right(nullptr){}
    TreeNode(T& _data): data(_data), left(nullptr), right(nullptr){}
    TreeNode(const T& _data, TreeNode<T> *l = nullptr, TreeNode<T> *r = nullptr): data(_data), left(l), right(r){}
    void set_data(T &data) {this->data = data;}
    T get_data() const {return data;}
    void set_left(TreeNode<T> *left) {this->left = left;}
    TreeNode<T> *get_left() const {return left;}
    void set_right(TreeNode<T> *right) {this->right = right;}
    TreeNode<T> *get_right() const {return right;}
};
