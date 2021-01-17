#include <vector>
#include "BinarySearchTree.cpp"

int main() {
    std::vector<long> v;
    for (long i = 0; i < 32; i++)
    {
        long val = std::pow(2, i);
        v.push_back(val);
    }
    
    BinarySearchTree<long> *bst = new BinarySearchTree<long>;
    for (long i: v) bst->insert(i);
    
    bst->balance_height();
    bst->print_level_order();
    return 0;
}
