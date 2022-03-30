#ifndef GENERICPROGRAMMINGASSIGNMENT1_TREE_HPP
#define GENERICPROGRAMMINGASSIGNMENT1_TREE_HPP
#include <string>

namespace DM852{
    class Tree {
    public:
        class Node {
        public:
            const int key;
            std::string value;
            Node *parent{};
            Node *left{};
            Node *right{};

            friend class Tree;
            Node *next();
            const Node *next() const;
            Node *prev();
            const Node *prev() const;
            Node(int key, std::string value, Node *parent, Node *left, Node *right);
            ~Node();
        };
        int size() const;
        bool empty() const;
        std::pair<Node*, bool>insert(int key, const std::string &value);
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
        Tree();
        ~Tree();
        bool operator==(const Tree& other);
        bool compareHelper(Node *first, Node *second);
        Tree(const Tree &other);
        Tree& operator=(const Tree &other);

    private:
        int length;
        Node *root;
    };
}
#endif //GENERICPROGRAMMINGASSIGNMENT1_TREE_HPP
