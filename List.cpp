#include "List.h"

#include <utility>

int List::size() const {
    return length;
}

bool List::empty() const {
    return length == 0;
}

void List::push_back(const std::string &elem) {
    Node newNode = Node(elem, last, nullptr);
    last->next = &newNode;
    last = &newNode;
}

Node *List::insert(Node *node, const std::string &elem) {
    Node *newNode = new Node(elem, node->next, node->prev);
    node->prev->next = newNode;
    node->prev = newNode;
    length++;
    return newNode;
}

void List::clear() {
    Node *curr = head;
    while (head != nullptr) {
        Node *temp = curr->next;
        free(curr);
        curr = temp;
    }
    head = nullptr;
    last = nullptr;
    length = 0;
}

void List::pop_back() {
    Node *temp = last;
    last = last->prev;
    length--;
    free(temp);
}

void List::erase(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    length--;
    free(node);
}

std::string &List::front() {
    return head->data;
}

const std::string &List::front() const {
    return head->data;
}

std::string &List::back() {
    return last->data;
}

const std::string &List::back() const {
    return last->data;
}

Node *List::begin() {
    return head;
}

const Node *List::begin() const {
    return head;
}

Node *List::end() {
    return head;
}

const Node *List::end() const {
    return head;
}

Node::Node(std::string data, Node *next, Node *prev) {
    this -> data = std::move(data);
    this -> next = next;
    this -> prev = prev;
}
