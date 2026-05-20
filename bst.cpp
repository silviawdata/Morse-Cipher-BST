/*
 * Name: Silvia Williams
 * Description: This program implements Binary Search Tree
 * functions that store characters and their corresponding
 * Morse code paths. It includes functions such as insert,
 * update, getValue, getPath, and deallocation.
 * Input: Input comes from main.cpp
 * Output: Output code is produced in main.cpp
 *
 */

#include "bst.h"
using std::string;

// DEALLOCATE TREE FUNCTION //
// To free up memory to avoid memory leaks
// using recursion.
template <class t1, class t2>
void bst<t1, t2>::deallocateTree(binTreeNode *r)
{
    if (r == nullptr)
    {
        return;
    }

    deallocateTree(r->left);  // check left
    deallocateTree(r->right); // check right
    delete r;
}
// INSERT FUNCTION FOR BST ///
// recursive function to find where
// the new key belongs in the BST
template <class t1, class t2>
typename bst<t1, t2>::binTreeNode *bst<t1, t2>::insert(binTreeNode *r, t1 k, t2 v)
{
    // creates a new node if r is nullptr/empty spot
    if (r == nullptr)
    {
        return new binTreeNode(k, v);
    }
    // if key is smaller, go left.
    if (k < (*r).key)
    {
        r->left = insert(r->left, k, v);
    }
    // if key is larger, go right
    else if (k > (*r).key)
    {

        r->right = insert(r->right, k, v);
    }
    // return current node after insertion
    return r;
}
// UPDATE FUNCTION ////////
// recursively updates an existing node into the BST.
// similar logic as insert function except overriding
// node's value.
template <class t1, class t2>
void bst<t1, t2>::update(binTreeNode *r, t1 k, t2 v)
{
    if (r == nullptr)
    {
        return;
    }
    if (k < (*r).key)
    {

        update(r->left, k, v); // search left
    }
    else if (k > (*r).key)
    {

        update(r->right, k, v); // search right
    }
    else
    {

        r->value = v; // key found, update value
    }
}
// GET VALUE FUNCTION//
// recursively searches for a node with matching key
// and returns its associated value.
// This retrieves stored values from BST
//
template <class t1, class t2>
t2 bst<t1, t2>::getValue(binTreeNode *r, t1 k)
{
    if (r == nullptr)
    {
        return t2();
        // returning t2() default object because it could be
        // a character or a string.
    }
    if (k < (*r).key)
    {
        return getValue(r->left, k);
    }
    else if (k > (*r).key)
    {

        return getValue(r->right, k);
    }
    else
    {
        // if key matches, return the value
        return r->value;
    }
}
// GET PATH FUNCTION //
// parameter is the character key we are looking for.
// the only non recursive function that traverses the BST
// That returns a string of characters "L" and "R" directions
// from the root to the node. Return S if key is found at the root
// returns empty string if key is not found in tree.
template <class t1, class t2>
string bst<t1, t2>::getPath(t1 k)
{
    binTreeNode *current = root; // initialize node at the root
    string path = "";            // initialize path

    // traverse tree until key is found
    while (current != nullptr)
    {
        // char found at current node
        if (k == current->key)
        {
            // if path is empty, char is at the root
            if (path.empty())
            {

                return "S";
            }

            return path; // returns accumulated path of "L"/"R"
        }
        // if char is smaller than current node, go left
        else if (k < current->key)
        {
            path = path + "L"; // accumulate path + "L"
            current = current->left;
        }
        else
        {
            // if char is larger, go right

            path = path + "R"; // acummulated path + "R"
            current = current->right;
        }
    }
    return ""; // return empty string if char is not found
}

template class bst<char, std::string>;
template class bst<std::string, char>;

// morse code that leads you to the root node or any node in the binary search tree.
// Left-Right AVL style tree with string LR. from the midterm.
//