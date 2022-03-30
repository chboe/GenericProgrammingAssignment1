#include "Tree.hpp"

#include <utility>
using namespace DM852;

//Constructor
Tree::Node::Node(int key, std::string value, Tree::Node *parent, Tree::Node *left, Tree::Node *right) : key(key) {
    this -> key = key;
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
    }
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

void Tree::erase(int key) {
    //Find Node
    Node* res = find(key);
    if(res->left == nullptr && res->right == nullptr){ //Leaf node
        //Adjust parent's pointer
        if(res->parent->left == res){
            res->parent->left = nullptr;
        } else if(res->parent->right == res){
            res->parent->right = nullptr;
        }
        delete res;
    } else if(res->left == nullptr){ //Only right child exists
        //Adjust parent's pointer
        if(res->parent->left == res){
            res->parent->left = res->right;
            res->right->parent = res->parent;
        } else if(res->parent->right == res){
            res->parent->right = res->right;
            res->right->parent = res->parent;
        }
        delete res;
    } else if(res->right == nullptr){ //Only left child exists
        //Adjust parent's pointer
        if(res->parent->left == res){
            res->parent->left = res->left;
            res->left->parent = res->parent;
        } else if(res->parent->right == res){
            res->parent->right = res->left;
            res->left->parent = res->parent;
        }
        delete res;
    } else { //2 children exist
        Node* temp = res->next();
        //Set children correctly
        temp->left = res->left;
        temp->right = res->right;
        //Adjust pointer of previous parent
        if(temp->parent->left == temp){
            temp->parent->left = nullptr;
        } else if(temp->parent->right == temp){
            temp->parent->right = nullptr;
        }
        //Set new parent
        temp->parent = res->parent;
        //Adjust new parent's pointer
        if(res->parent->left == res){
            res->parent->left = temp;
        } else if(res->parent->right == res){
            res->parent->right = temp;
        }
        delete res;
    }
}

void Tree::erase(const Tree::Node *node) {
    Node* res = const_cast<Node *>(node);
    if(res->left == nullptr && res->right == nullptr){ //Leaf res
        //Adjust parent's pointer
        if(res->parent->left == res){
            res->parent->left = nullptr;
        } else if(res->parent->right == res){
            res->parent->right = nullptr;
        }
        delete res;
    } else if(res->left == nullptr){ //Only right child exists
        //Adjust parent's pointer
        if(res->parent->left == res){
            res->parent->left = res->right;
            res->right->parent = res->parent;
        } else if(res->parent->right == res){
            res->parent->right = res->right;
            res->right->parent = res->parent;
        }
        delete res;
    } else if(res->right == nullptr){ //Only left child exists
        //Adjust parent's pointer
        if(res->parent->left == res){
            res->parent->left = res->left;
            res->left->parent = res->parent;
        } else if(res->parent->right == res){
            res->parent->right = res->left;
            res->left->parent = res->parent;
        }
        delete res;
    } else { //2 children exist
        Tree::Node *temp = res->next();
        //Set children correctly
        temp->left = res->left;
        temp->right = res->right;
        //Adjust pointer of previous parent
        if (temp->parent->left == temp) {
            temp->parent->left = nullptr;
        } else if (temp->parent->right == temp) {
            temp->parent->right = nullptr;
        }
        //Set new parent
        temp->parent = res->parent;
        //Adjust new parent's pointer
        if (res->parent->left == res) {
            res->parent->left = temp;
        } else if (res->parent->right == res) {
            res->parent->right = temp;
        }
        delete res;
    }
}

void Tree::clearHelper(Node* curr){
    if(curr->right != nullptr){
        clearHelper(curr->right);
    }
    if(curr->left != nullptr){
        clearHelper(curr->left);
    }
    delete curr->left;
    delete curr->right;
    delete curr->parent;
}

void Tree::clear() {
    clearHelper(root);
    length = 0;
    root = nullptr;
}

//Deletes next element which will trigger deletion of following elements
Tree::Node::~Node() {
    delete left;
    delete right;
}
