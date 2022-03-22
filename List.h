#ifndef GENERICPROGRAMMINGASSIGNMENT1_LIST_H
#define GENERICPROGRAMMINGASSIGNMENT1_LIST_H


#include <string>



class Node {
private:
    std::string data;
    Node *prev;
    Node *next;
    Node(std::string data, Node *next, Node *prev);
    friend class List;
};

class List {
private:
    int length;
    Node *head;
    Node *last;
public:
    int size() const;
    bool empty() const;
    void push_back(const std::string &elem);
    Node *insert(Node *node, const std::string &elem);
    void clear();
    void pop_back();
    void erase(Node *node);
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;
    Node *begin();
    const Node *begin() const;
    Node *end();
    const Node *end() const;
};

#endif //GENERICPROGRAMMINGASSIGNMENT1_LIST_H
