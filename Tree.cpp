#include "Tree.h"


int Tree::size() const {
    return length;
}

bool Tree::empty() const {
    return length == 0;
}

std::pair<Node *, bool> Tree::insert(int key, const std::string &value) {
    return std::pair<Node *, bool>();
}
