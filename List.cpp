#include "List.h"

int List::size() const {
    return length;
}

bool List::empty() const {
    return length == 0;
}

void List::push_back(const std::string &elem) {
    Node newNode = Node(elem, last, nullptr);
    last->next = newNode;
    last = &newNode;
}

Node::Node(std::string data, Node *next, Node *prev) {
    data = data;
    next = next;
    prev = prev;
}
