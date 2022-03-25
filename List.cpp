#include "List.hpp"

#include <utility>

using namespace DM852;

int List::size() const {
    return length;
}

bool List::empty() const {
    return length == 0;
}

void List::push_back(const std::string &elem) {
    Node *newNode = new Node(elem, last, nullptr);
    if (head == nullptr){
        head = newNode;
    } else {
        last->next = newNode;
    }
    last = newNode;
    length++;
}

List::Node *List::insert(Node *node, const std::string &elem) {
    Node *newNode = new Node(elem, node, node->prev);
    if(node == head){
        head = newNode;
    } else {
        node->prev->next = newNode;
    }
    node->prev = newNode;
    length++;
    return newNode;
}

void List::clear() {
    Node *curr = head;
    while (head != nullptr) {
        Node *temp = curr->next;
        delete curr;
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
    if(head == last){
        head = nullptr;
    }
    delete temp;
}

void List::erase(Node *node) {
    if(node == head){
        head = node->next;
    } else {
        node->prev->next = node->next;
    }
    if(node == last){
        last = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    length--;
    delete node;
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

List::Node *List::begin() {
    return head;
}

const List::Node *List::begin() const {
    return head;
}

List::Node *List::end() {
    return head;
}

const List::Node *List::end() const {
    return head;
}

List::List() {
    head = nullptr;
    last = nullptr;
    length = 0;
}

List::~List() {
    delete head;
}

bool List::operator==(const List& other){
    return length == other.length && head->data == other.head->data && last->data == other.last->data && compareHelper(this->head, other.head);
}

bool List::compareHelper(Node *first, Node *second) {
    if (first == nullptr && second == nullptr){
        return true;
    }
    if(first == nullptr || second == nullptr){
        return false;
    }
    if( first->data == second->data){
        return compareHelper(first->next,second->next);
    }
    return false;
}

List::List(const List &other) {
    Node *current = other.head;
    while(current != nullptr){
        Node *newNode = new Node(current->data, current->prev, nullptr);
        if(current->prev != nullptr){
            current->prev->next = current;
        } else {
            head = newNode;
        }
        if(current->next == nullptr){
            last = newNode;
        }
        current = current->next;
    }
    length = other.length;
}

List &List::operator=(const List &other) {
    delete head;
    Node *current = other.head;
    while(current != nullptr){
        Node *newNode = new Node(current->data, current->prev, nullptr);
        if(current->prev != nullptr){
            current->prev->next = current;
        } else {
            head = newNode;
        }
        if(current->next == nullptr){
            last = newNode;
        }
        current = current->next;
    }
    length = other.length;
    return *this;
}

List::Node::Node(std::string data, Node *prev, Node *next) {
    data = std::move(data);
    next = next;
    prev = prev;
}

List::Node::~Node() {
    delete next;
}
