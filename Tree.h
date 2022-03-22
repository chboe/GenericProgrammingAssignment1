#ifndef GENERICPROGRAMMINGASSIGNMENT1_TREE_H
#define GENERICPROGRAMMINGASSIGNMENT1_TREE_H

#include <string>

class Node {
private:
    const int key;
    std::string value;
    Node *parent;
    Node *left;
    Node *right;
    Node(const int key, std::string value, Node *parent, Node *left, Node *right);
    friend class Tree;

public:
    Node *next();
    const Node *next() const;
    Node *prev();
    const Node *prev() const;
};

class Tree {
private:
    int length;
    Node *root;

public:
    int size() const;
    bool empty() const;
    std::pair<Node*, bool> insert(int key, const std::string &value);
    Node *find(int key);
    const Node *find(int key) const;
    void clear();
    void erase(int key);
    void erase(const Node *node);
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;
    Node *begin();
    const Node *begin() const;
    Node *end();
    const Node *end() const;
};




#endif //GENERICPROGRAMMINGASSIGNMENT1_TREE_H
