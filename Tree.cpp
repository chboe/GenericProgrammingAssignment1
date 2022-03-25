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
    return std::pair<Node *, bool>(newNode, true);
}

Tree::Node::Node(int key, std::string value, Node *parent, Node *left, Node *right) : key(key), value(std::move(value)) {
    parent = parent;
    left = left;
    right = right;
}