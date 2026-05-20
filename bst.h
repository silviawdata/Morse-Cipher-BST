#include <cstdlib>
#include <string>

#ifndef BST_H
#define BST_H

template <class t1, class t2>
class bst
{
private:
  class binTreeNode
  {
  public:
    binTreeNode() : key( t1() ), value( t2() ), left(nullptr), right(nullptr) {}
    binTreeNode(t1 k, t2 v) : key(k), value(v), left(nullptr), right(nullptr) {}

    t1 key;
    t2 value;

    binTreeNode * left;
    binTreeNode * right;
  };

  binTreeNode * root;

  void deallocateTree(binTreeNode*);

  binTreeNode* insert(binTreeNode*, t1, t2);
  void update(binTreeNode*, t1, t2);
  t2 getValue(binTreeNode*, t1);


public:
  bst() : root(nullptr) {}
  ~bst() { deallocateTree(root); }
  void insert(t1 k, t2 v) { root = insert(root, k, v); }
  void update(t1 k, t2 v) { update(root, k, v); }
  t2 getValue(const t1& k) { return getValue(root, k); }
  std::string getPath(t1);
};

#endif


/*
Getting lure of Resident Evil Game from encryptiom/decryption of an input
file.  

we went over binary search tree many time in class.

most difficult part would be reading in a file, then convert each letter
into morse code into the original text.


The LLRR part gives us the direction to go in for a binary search tree. 
S is the root node to get particular letters in a binary tree.
Create a binary search tree with a given set of letters.

for deallocation we are going to do a post order traveral to deallocate the tree.
  - dealocate left sub tree and deallocate right subtree and then deallocate R.

source code given from geeksforgeeks
insert function



update pass in pointer(pointer, int match)
traverse until you find a matching node.
match == t1 key
return value
everything will be all recursive


getPath funtion will return back a string LR for example
this doesnt have to be recursive. because no backtrackin, wer are
simple following directions.  we need a loop for this. 
create pointer within the function lik goRight=r->right goLeft=r->left 


FOR MAIN.CPP
we must read in two file names
  - 1st letters file that contains A-Z(upper lower); 0-9; "," "." whitespace
      *need to use getline character to string
      *read one by one and insert it into a binary search tree object as a character to string map.
      *map the character to its morse code path blank string value.
      *call getPath for every single character then return that path and update that characters value.
      *using the result of that getpath function. 
      *then call update function and reaasign that characters value to the path constructed from the get path funtion.
  
  - 2nd bst object string to map out each morse code to a letter so the LLRR for example
    *string to character so like a reversal.
    

  -3rd read in the games original versions plot. 

  read in each character one at a time and output the equivalent morse code value.
  take encrypted string and map that to the original plot string 
  
  

on the terminal: compile, type in the files, and a letter either e(encrypt) or d(decrypt)


CODE BELOW FOR INSPIRATION
# (sign) is the delimitter for eachafter each string LLRR which equals a letter

<script>

// javascript program to demonstrate insert  
// operation in binary search tree
// BST node 
class Node 
{ 
    constructor()
    {
        this.key = 0;
        this.left = null;
        this.right = null;
    }
}; 

// Utility function to create a new node 
function newNode(data) 
{ 
    var temp = new Node(); 
    temp.key = data; 
    temp.left = null; 
    temp.right = null; 
    return temp; 
} 

// A utility function to insert a new 
// Node with given key in BST 
function insert(root, key) 
{ 

    // Create a new Node containing 
    // the new element 
    var newnode = newNode(key); 
    
    // Pointer to start traversing from root and 
    // traverses downward path to search 
    // where the new node to be inserted 
    var x = root; 
    
    // Pointer y maintains the trailing 
    // pointer of x 
    var y = null; 

    while (x != null) 
    { 
        y = x; 
        if (key < x.key) 
            x = x.left; 
        else
            x = x.right; 
    } 
    
    // If the root is null i.e the tree is empty 
    // The new node is the root node 
    if (y == null) 
        y = newnode; 
        
    // If the new key is less than the leaf node key 
    // Assign the new node to be its left child 
    else if (key < y.key) 
        y.left = newnode; 
        
    // else assign the new node its right child 
    else
        y.right = newnode; 
        
    // Returns the pointer where the 
    // new node is inserted 
    return y; 
} 

// A utility function to do inorder 
// traversal of BST 
function Inorder(root) 
{ 
    if (root == null) 
        return; 
    else 
    { 
        Inorder(root.left); 
        document.write( root.key +" "); 
        Inorder(root.right); 
    } 
} 

// Driver code 
 Let us create following BST 
        50 
    / \ 
    30 70 
    / \ / \ 
20 40 60 80 
var root = null; 
root = insert(root, 50); 
insert(root, 30); 
insert(root, 20); 
insert(root, 40); 
insert(root, 70); 
insert(root, 60); 
insert(root, 80); 
// Print inorder traversal of the BST 
Inorder(root); 

// This code is contributed by itsok.
</script>

// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Custom Queue Implementation
class Queue {
    constructor() {
        this.items = {};
        this.headIndex = 0;
        this.tailIndex = 0;
    }

    enqueue(item) {
        this.items[this.tailIndex] = item;
        this.tailIndex++;
    }

    dequeue() {
        if (this.isEmpty()) return null;
        let item = this.items[this.headIndex];
        delete this.items[this.headIndex];
        this.headIndex++;
        return item;
    }

    isEmpty() {
        return this.tailIndex === this.headIndex;
    }

    size() {
        return this.tailIndex - this.headIndex;
    }
}

function getHeight(root, h) {
    if (root === null) return h - 1;
    return Math.max(getHeight(root.left, h + 1), getHeight(root.right, h + 1));
}

function levelOrder(root) {
    let q = new Queue();
    q.enqueue([root, 0]);

    let lastLevel = 0;

    // function to get the height of tree
    let height = getHeight(root, 0);

    // printing the level order of tree
    while (!q.isEmpty()) {
        let [node, lvl] = q.dequeue();

        if (lvl > lastLevel) {
            console.log("");
            lastLevel = lvl;
        }

        // all levels are printed
        if (lvl > height) break;

        // printing null node
        process.stdout.write((node.data === -1 ? "N" : node.data) + " ");

        // null node has no children
        if (node.data === -1) continue;

        if (node.left === null) q.enqueue([new Node(-1), lvl + 1]);
        else q.enqueue([node.left, lvl + 1]);

        if (node.right === null) q.enqueue([new Node(-1), lvl + 1]);
        else q.enqueue([node.right, lvl + 1]);
    }
}

// Recursive Function to Create BST
function sortedArrayToBSTRecur(arr, start, end) {
    if (start > end) return null;

    let mid = start + Math.floor((end - start) / 2);
    let root = new Node(arr[mid]);

    // Divide from middle element
    root.left = sortedArrayToBSTRecur(arr, start, mid - 1);
    root.right = sortedArrayToBSTRecur(arr, mid + 1, end);

    return root;
}

// Function which return BST
function sortedArrayToBST(arr) {
    return sortedArrayToBSTRecur(arr, 0, arr.length - 1);
}

// Driver code
const arr = [1, 5, 9, 14, 23, 27];
const root = sortedArrayToBST(arr);
levelOrder(root);

// Node Structure
class Node {
    constructor(v) {
        this.data = v;
        this.left = null;
        this.right = null;
    }
}

function postOrder(node, res) {
    if (node === null)
        return;

    // First we traverse left subtree
    postOrder(node.left, res);

    // After visiting left, traverse right subtree
    postOrder(node.right, res);

    // now we visit node
    res.push(node.data);
}

// Driver code
 //Represent Tree
        //       1
        //      / \
        //     2   3
        //    / \   \
        //   4   5   6
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.right = new Node(6);

let result = [];
postOrder(root, result);

// Print the postorder
for (let val of result)
    process.stdout.write(val + " ");
*/
