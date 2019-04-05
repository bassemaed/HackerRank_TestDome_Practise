/*
Binary search tree (BST) is a binary tree where the value of each node is larger or equal to the values in
all the nodes in that node's left subtree and smaller than the values in all the nodes in that node's right subtree.

Write a function that, efficiently with respect to time used,
returns 1 if a given binary search tree contains a given value, else 0.

For example, for the following tree:

    n1 (Value: 1, Left: null, Right: null)
    n2 (Value: 2, Left: n1, Right: n3)
    n3 (Value: 3, Left: null, Right: null)

Call to contains(&n2, 3) should return 1 since a tree with root at n2 contains number 3

*/
#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value){
        Node* tree;
        int valuecompare = root.getValue();
        if(valuecompare == value) {
            return 1;
        }
        else if (valuecompare < value){
            tree = root.getRight();
            if(tree != NULL)
                return contains(*tree,value);
            else return 0;
        }
        else {
            tree = root.getLeft();
            if(tree != NULL)
                return contains(*tree, value);
            else return 0;
        }
    }
};

#ifndef RunTests
int main()
{
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);

    std::cout << BinarySearchTree::contains(n2, 3);
}
#endif
