#include "Tree.hpp"

#include <utility>
using namespace DM852;

//Constructor
Tree::Node::Node(int key, std::string value, Tree::Node *parent, Tree::Node *left, Tree::Node *right) : key(key) {
    this -> value = std::move(value);
    this -> parent = parent;
    this -> left = left;
    this -> right = right;
}

//Return the node with the next value
Tree::Node *Tree::Node::next() {
    //Handles case of right child existing
    if(right != nullptr){
        Node* current = right;
        while(current -> left != nullptr){
            current = current -> left;
        }
        return current;
    } else {
        //Handles case of right child not existing
        Node* par = parent;
        Node* current = par->right;
        //If root returns nullptr
        while( par != nullptr && par->right == current){
            current = par;
            par = par -> parent;
        }
        return par;
    }
}

//Return the node with the next value
const Tree::Node *Tree::Node::next() const {
    //Handles case of right child existing
    if(right != nullptr){
        Node* current = right;
        while(current -> left != nullptr){
            current = current -> left;
        }
        return current;
    } else {
        //Handles case of right child not existing
        Node* par = parent;
        Node* current = par->right;
        //If root returns nullptr
        while( par != nullptr && par->right == current){
            current = par;
            par = par -> parent;
        }
        return par;
    }
}

//Return the node with the previous value
Tree::Node *Tree::Node::prev() {
    //Handles case of left child existing
    if(left != nullptr){
        Node* current = left;
        while(current -> right != nullptr){
            current = current -> right;
        }
        return current;
    } else {
        //Handles case of left child not existing
        Node* par = parent;
        Node* current = par->left;
        //If root returns nullptr
        while( par != nullptr && par->left == current){
            current = par;
            par = par -> parent;
        }
        return par;
    }
}

//Return the node with the previous value
const Tree::Node *Tree::Node::prev() const {
    //Handles case of left child existing
    if(left != nullptr){
        Node* current = left;
        while(current -> right != nullptr){
            current = current -> right;
        }
        return current;
    } else {
        //Handles case of left child not existing
        Node* par = parent;
        Node* current = par->left;
        //If root returns nullptr
        while( par != nullptr && par->left == current){
            current = par;
            par = par -> parent;
        }
        return par;
    }
}

//Returns length
int Tree::size() const {
    return length;
}

//Checks if length is 0
bool Tree::empty() const {
    return length == 0;
}

//Inserts a node with the given value
std::pair<Tree::Node*, bool> Tree::insert(int key, const std::string &value) {
    Node* current = root;
    Node* par = nullptr;
    //Iterates through list until correct location is found
    while(current != nullptr){
        if(key == current->key){
            current->value = value;
            return std::make_pair(current,false);
        } else if ( key < current->key){
            par = current;
            current = current -> left;
        } else if ( key > current->key){
            par = current;
            current = current -> right;
        }
    }
    Node* newNode = new Node(key, value, par, nullptr, nullptr);
    //Updates root if necessary
    if(root == nullptr){
        root = newNode;
    } else if(key < par->key){
        par->left = newNode;
    } else if(key > par->key){
        par->right = newNode;
    }

    length++;
    return std::make_pair(newNode,true);
}

//Finds node containing key
Tree::Node *Tree::find(int key) {
    Node* current = root;
    //Iterates through list until correct location is found
    while(current != nullptr){
        if(key == current->key){
            return current;
        } else if ( key < current->key){
            current = current -> left;
        } else if ( key > current->key){
            current = current -> right;
        }
    }
    return nullptr;
}

//Finds node containing key
const Tree::Node *Tree::find(int key) const {
    Node* current = root;
    //Iterates through list until correct location is found
    while(current != nullptr){
        if(key == current->key){
            return current;
        } else if ( key < current->key){
            current = current -> left;
        } else if ( key > current->key){
            current = current -> right;
        }
    }
    return nullptr;
}

//Returns value of root node
std::string &Tree::front() {
    return root->value;
}

//Returns value of root node
const std::string &Tree::front() const {
    return root->value;
}

//Returns value of last node
std::string &Tree::back() {
    Node* current = root;
    while(current -> right != nullptr){
        current = current -> right;
    }
    return current->value;
}

//Returns value of last node
const std::string &Tree::back() const {
    Node* current = root;
    while(current -> right != nullptr){
        current = current -> right;
    }
    return current->value;
}

//Returns root node
Tree::Node *Tree::begin() {
    return root;
}

//Returns root node
const Tree::Node *Tree::begin() const {
    return root;
}

//Returns last node
Tree::Node *Tree::end() {
    Node* current = root;
    while(current -> right != nullptr){
        current = current -> right;
    }
    return current;
}

//Returns last node
const Tree::Node *Tree::end() const {
    Node* current = root;
    while(current -> right != nullptr){
        current = current -> right;
    }
    return current;
}

Tree::Tree() {
    this -> root = nullptr;
    this -> length = 0;
}

Tree::~Tree() {
    delete root;
}

void Tree::transplant(Node* u, Node* v){
    if( u->parent == nullptr){
        root = v;
    } else if (u == u->parent->left){
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u->parent;
    }
}

Tree::Node* Tree::min(Node* node){
    Node* current = node;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}

void Tree::erase(int key) {
    Node* z = find(key);
    if(z->left == nullptr){
        transplant(z, z->right);
    } else if(z->right == nullptr){
        transplant(z, z->left);
    } else {
        Node* y = min(z->right);
        if(y->parent != z){
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    if(z != nullptr){
        z->right = nullptr;
        z->left = nullptr;
        delete z;
        length--;
    }
}

void Tree::erase(const Tree::Node *node) {
    Node* z = const_cast<Node *>(node);
    if(z->left == nullptr){
        transplant(z, z->right);
    } else if(z->right == nullptr){
        transplant(z, z->left);
    } else {
        Node* y = min(z->right);
        if(y->parent != z){
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    if(z != nullptr){
        z->right = nullptr;
        z->left = nullptr;
        delete z;
        length--;
    }
}

void Tree::clear() {
    delete root;
    length = 0;
    root = nullptr;
}

bool Tree::operator==(const Tree &other) {
    return length == other.length && compareHelper(root, other.root);
}

bool Tree::compareHelper(Tree::Node *first, Tree::Node *second) {
    //If both list end at the same time at this point they are similar
    if (first == nullptr && second == nullptr){
        return true;
    }
    //If one ends before the other they are not similar
    if(first == nullptr || second == nullptr){
        return false;
    }
    //Checking data of both lists before checking next element
    if( first->key == second->key && first->value == second->value){
        return compareHelper(first->left,second->left) && compareHelper(first->right,second->right);
    }
    //If data is not similar
    return false;
}

//Parent keeps track of the parent of the new node, current tracks the current node in the copyable list
Tree::Node* copyHelper(Tree::Node* parent, Tree::Node* current){
    if(current != nullptr){
        Tree::Node* newNode = new Tree::Node(current->key, current->value, parent, nullptr, nullptr);
        newNode->left = copyHelper(newNode, current->left);
        newNode->right = copyHelper(newNode, current->right);
        return newNode;
    }
    return nullptr;
}

Tree::Tree(const Tree &other) {
    root = copyHelper(nullptr, other.root);
    length = other.length;
}

Tree &Tree::operator=(const Tree &other) {
    delete root;
    root = copyHelper(nullptr, other.root);
    length = other.length;
    return *this;
}

//Deletes next element which will trigger deletion of following elements
Tree::Node::~Node() {
    delete left;
    delete right;
}
