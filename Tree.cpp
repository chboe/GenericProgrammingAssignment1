#include "Tree.hpp"

#include <utility>
using namespace DM852;

int Tree::size() const {
    return length;
}

bool Tree::empty() const {
    return length == 0;
}

std::pair<Tree::Node *, bool> Tree::insert(int key, const std::string &value) {
    Node *current = root;
    while (current != nullptr){
        if(key == current->key){
            current->value = value;
            return std::pair<Node *, bool>(current, false);
        } else if(key < current->key){
            if(current->left == nullptr){
                Node *newNode = new Node(key, value, current, nullptr, nullptr);
                current->left = newNode;
                current = nullptr;
                return std::pair<Node *, bool>(newNode, true);
            } else {
                current = current->left;
            }
        } else if(key > current->key){
            if(current->right == nullptr){
                Node *newNode = new Node(key, value, current, nullptr, nullptr);
                current->right = newNode;
                current = nullptr;
                return std::pair<Node *, bool>(newNode, true);
            } else {
                current = current->right;
            }
        }
    }
}

Tree::Node *Tree::find(int key) {
    Node *current = root;
    while (current != nullptr){
        if(key == current->key){
            return current;
        } else if(key < current->key){
            current = current->left;
        } else if(key > current->key){
            current = current->right;
        }
    }
    return nullptr;
}

const Tree::Node *Tree::find(int key) const {
    Node *current = root;
    while (current != nullptr){
        if(key == current->key){
            return current;
        } else if(key < current->key){
            current = current->left;
        } else if(key > current->key){
            current = current->right;
        }
    }
    return nullptr;
}

std::string &Tree::front() {
    Node *current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current->value;
}

const std::string &Tree::front() const {
    Node *current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current->value;
}

std::string &Tree::back() {
    Node *current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current->value;
}

const std::string &Tree::back() const {
    Node *current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current->value;
}

Tree::Node *Tree::begin() {
    Node *current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}

const Tree::Node *Tree::begin() const {
    Node *current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}

Tree::Node *Tree::end() {
    Node *current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current;
}

const Tree::Node *Tree::end() const {
    Node *current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current;
}

Tree::Node *Tree::Node::next() {
    Node *current = right;
    while(current -> left != nullptr){
        current = current -> left;
    }
    return current;
}

const Tree::Node *Tree::Node::next() const {
    Node *current = right;
    while(current -> left != nullptr){
        current = current -> left;
    }
    return current;
}

Tree::Node *Tree::Node::prev() {
    Node *current = left;
    while(current -> right != nullptr){
        current = current -> right;
    }
    return current;
}

const Tree::Node *Tree::Node::prev() const {
    Node *current = left;
    while(current -> right != nullptr){
        current = current -> right;
    }
    return current;
}

Tree::Node::Node(int key, std::string value, Node *parent, Node *left, Node *right) : key(key), value(std::move(value)) {
    parent = parent;
    left = left;
    right = right;
}