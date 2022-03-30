#include "List.hpp"

#include <utility>

using namespace DM852;

//Returns the private attribute length
int List::size() const {
    return length;
}

//Returns true if length is 0
bool List::empty() const {
    return length == 0;
}

//Places the node at last - also as head if head is missing
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

//Inserts a new node with the given value. Updates pointers as appropriate
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

//Iterates through all elements in list and deletes them before resetting the attributes of the list.
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

//Removes the last element of the list
void List::pop_back() {
    Node *temp = last;
    //If the element is also the head prev will be a nullptr
    last = last->prev;
    length--;
    if(head == last){
        head = nullptr;
    }
    delete temp;
}

//Deletes the given node and updates head/last pointers if needed
void List::erase(Node *node) {
    if(node == head){
        head = node->next;
    } else {
        node->prev->next = node->next;
    }
    if(node == last){
        //If the element is also the head prev will be a nullptr
        last = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    length--;
    delete node;
}

//Returns data value of first element in list
std::string &List::front() {
    return head->data;
}

//Returns data value of first element in list
const std::string &List::front() const {
    return head->data;
}

//Returns data value of last element in list
std::string &List::back() {
    return last->data;
}

//Returns data value of last element in list
const std::string &List::back() const {
    return last->data;
}

//Returns first element of list
List::Node *List::begin() {
    return head;
}

//Returns first element of list
const List::Node *List::begin() const {
    return head;
}

//Returns last element of list
List::Node *List::end() {
    return head;
}

//Returns last element of list
const List::Node *List::end() const {
    return head;
}

//Default constructor
List::List() {
    this -> head = nullptr;
    this -> last = nullptr;
    this -> length = 0;
}

//Deletes the list
List::~List() {
    //Only need to delete head as this will trigger deletion of following elements
    delete head;
}

bool List::operator==(const List& other){
    //Compares list attributes before checking similarity element wise
    return length == other.length && head->data == other.head->data && last->data == other.last->data && compareHelper(this->head, other.head);
}

bool List::compareHelper(Node *first, Node *second) {
    //If both list end at the same time at this point they are similar
    if (first == nullptr && second == nullptr){
        return true;
    }
    //If one ends before the other they are not similar
    if(first == nullptr || second == nullptr){
        return false;
    }
    //Checking data of both lists before checking next element
    if( first->data == second->data){
        return compareHelper(first->next,second->next);
    }
    //If data is not similar
    return false;
}

//Copies a list and its nodes element wise
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

//Copies a list and its nodes element wise
List &List::operator=(const List &other) {
    delete head;
    Node *current = other.head;
    while(current != nullptr){
        Node *newNode = new Node(current->data, current->prev, nullptr);
        //Handles head case
        if(current->prev != nullptr){
            current->prev->next = current;
        } else {
            head = newNode;
        }
        //Handles last case
        if(current->next == nullptr){
            last = newNode;
        }
        current = current->next;
    }
    length = other.length;
    return *this;
}

//Constructs a node with given parameters
List::Node::Node(std::string data, Node *prev, Node *next) {
    this -> data = std::move(data);
    this -> next = next;
    this -> prev = prev;
}

//Deletes next element which will trigger deletion of following elements
List::Node::~Node() {
    delete next;
    delete prev;
}
